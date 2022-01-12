//
//  KLNRewardedAd.h
//  KlevinAdSDK
//
//  Copyright © 2021 Tencent. All rights reserved.
//  Created by Klevin on 2021/4/20.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <KlevinAdSDK/KLNAdReward.h>
#import <KlevinAdSDK/KLNAdRequest.h>
#import <KlevinAdSDK/KLNFullScreenContentDelegate.h>
#import <KlevinAdSDK/KLNAdVideoController.h>

NS_ASSUME_NONNULL_BEGIN

@class KLNRewardedAd;

/// 激励广告信息加载成功回调（视频素材未下载完成），此时调用播放会触发边拉边播体验
typedef void (^KLNRewardedAdDidLoadCallback)(KLNRewardedAd *_Nonnull rewardedAd);

/// 激励广告加载完成回调，如果rewardedAd不为空，则表示视频素材已下载完成。
/// 建议在此回调方法中进行广告的展示，可保证广告播放流畅展示，用户体验较好。
/// 如果激励广告加载过程产生失败，则error对象不为空，rewardedAd为空。建议重新加载广告
typedef void (^KLNRewardedAdLoadCompletionHandler)(KLNRewardedAd *_Nullable rewardedAd,
                                                  NSError *_Nullable error);

/// 激励广告
@interface KLNRewardedAd : NSObject<KLNFullScreenPresentingAd>

/// 当前激励广告绑定的激励内容
@property (nonatomic, readonly) KLNAdReward *adReward;

/// 视图展示/销毁消息回调代理
@property (nonatomic, weak, nullable) id<KLNFullScreenContentDelegate> fullScreenContentDelegate;

/// Controller for video play
@property (nonatomic, strong, readonly, nullable) KLNAdVideoController *videoController;

/// 加载激励广告方法
/// @param request 激励广告请求对象
/// @param completionHandler 广告加载结果回调（成功/失败）
+ (void)loadWithRequest:(KLNRewardedAdRequest *)request
      completionHandler:(KLNRewardedAdLoadCompletionHandler)completionHandler;

/// 加载激励广告方法
/// @param request 激励广告请求对象
/// @param adLoadedCallback 激励广告信息加载成功回调（视频素材未下载完成），此时调用播放会触发边拉边播体验
/// @param completionHandler  广告加载结果回调（成功/失败）
+ (void)loadWithRequest:(KLNRewardedAdRequest *)request
       adDidLoadHandler:(nullable KLNRewardedAdDidLoadCallback)adLoadedCallback
      completionHandler:(KLNRewardedAdLoadCompletionHandler)completionHandler;

/// 判断激励广告是否可展示方法，请在主线程调用
/// Returns whether the rewarded ad can be presented from the provided root view
/// controller. Sets the error out parameter if the ad can't be presented. Must be called on the
/// main thread.
/// @param rootViewController 当前视图
/// @param error 错误信息
- (BOOL)canPresentFromRootViewController:(UIViewController *)rootViewController
                                   error:(NSError *_Nullable __autoreleasing *_Nullable)error;

/// 展示激励广告，并指定用户获得奖励事件回调 KLNAdUserDidEarnRewardHandler
///
/// @param rootViewController 展示激励广告的视图
/// @param userDidEarnRewardHandler 处理获得奖励事件回调
- (void)presentFromRootViewController:(UIViewController *)rootViewController
             userDidEarnRewardHandler:(KLNAdUserDidEarnRewardHandler)userDidEarnRewardHandler;

@end

NS_ASSUME_NONNULL_END
