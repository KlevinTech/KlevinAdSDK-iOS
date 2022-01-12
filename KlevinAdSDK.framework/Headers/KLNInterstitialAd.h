//
//  KLNInterstitialAd.h
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

@class KLNInterstitialAd;

/// A block to be executed when the ad request operation completes. On success,
/// interstitialAd is non-nil and |error| is nil. On failure, interstitialAd is nil
/// and |error| is non-nil.
typedef void (^KLNInterstitialAdLoadCompletionHandler)(KLNInterstitialAd *_Nullable interstitialAd,
                                                       NSError *_Nullable error);

/// 插屏广告
@interface KLNInterstitialAd : NSObject<KLNFullScreenPresentingAd>

/// 视图展示/销毁消息回调代理
@property (nonatomic, weak, nullable) id<KLNFullScreenContentDelegate> fullScreenContentDelegate;

/// Controller for video play
@property (nonatomic, strong, readonly, nullable) KLNAdVideoController *videoController;

/// 加载插屏广告方法
///
/// @param request 插屏广告请求对象
/// @param completionHandler 广告加载结果回调（成功/失败），请注意：回调非线程安全
+ (void)loadWithRequest:(nonnull KLNInterstitialAdRequest *)request
      completionHandler:(KLNInterstitialAdLoadCompletionHandler)completionHandler;

/// 判断插屏广告是否可展示方法，请在主线程调用
/// Returns whether the interstitial ad can be presented from the provided root view
/// controller. Sets the error out parameter if the ad can't be presented. Must be called on the
/// main thread.
/// @param rootViewController 视图对象
/// @param error 错误信息
- (BOOL)canPresentFromRootViewController:(UIViewController *)rootViewController
                                   error:(NSError *_Nullable __autoreleasing *_Nullable)error;

/// 插屏广告展示方法，请在主线程调用
/// Presents the interstitial ad. Must be called on the main thread.
/// @param rootViewController A view controller to present the ad.
- (void)presentFromRootViewController:(UIViewController *)rootViewController;

@end

NS_ASSUME_NONNULL_END
