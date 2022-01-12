//
//  KLNSplashAd.h
//  KlevinAdSDK
//
//  Copyright © 2021 Tencent. All rights reserved.
//  Created by Klevin on 2021/4/20.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <KlevinAdSDK/KLNAdRequest.h>
#import <KlevinAdSDK/KLNFullScreenContentDelegate.h>
#import <KlevinAdSDK/KLNAdVideoController.h>

NS_ASSUME_NONNULL_BEGIN

@class KLNSplashAd;

/// The handler block to execute when the ad load operation completes. On failure, the
/// splashAd is nil and the |error| is non-nil. On success, the splashAd is non-nil and the
/// |error| is nil.
typedef void (^KLNSplashAdLoadCompletionHandler)(KLNSplashAd *_Nullable splashAd,
                                                  NSError *_Nullable error);

/// 开屏广告
@interface KLNSplashAd : NSObject<KLNFullScreenPresentingAd>

/// 视图展示/销毁消息回调代理
@property (nonatomic, weak, nullable) id<KLNFullScreenContentDelegate> fullScreenContentDelegate;

/// Controller for video play
@property (nonatomic, strong, readonly, nullable) KLNAdVideoController *videoController;

/// 加载开屏广告方法
///
/// @param request 开屏广告请求对象
/// @param completionHandler 广告加载结果回调（成功/失败），请注意：回调非线程安全
+ (void)loadWithRequest:(nonnull KLNSplashAdRequest *)request
      completionHandler:(KLNSplashAdLoadCompletionHandler)completionHandler;

/// 判断开屏广告是否可展示，请在主线程调用
/// Returns whether the interstitial ad can be presented from the provided root view
/// controller. Sets the error out parameter if the ad can't be presented. Must be called on the
/// main thread.
/// @param rootViewController 当前视图
/// @param error 错误信息
- (BOOL)canPresentFromRootViewController:(UIViewController *)rootViewController
                                   error:(NSError *_Nullable __autoreleasing *_Nullable)error;

/// 展示开屏广告方法，请在主线程调用
///
/// @param rootViewController A view controller to present the ad.
- (void)presentFromRootViewController:(UIViewController *)rootViewController;

@end

NS_ASSUME_NONNULL_END
