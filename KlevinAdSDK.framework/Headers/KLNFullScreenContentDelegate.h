//
//  KLNFullScreenContentDelegate.h
//  KlevinAdSDK
//
//  Copyright © 2021 Tencent. All rights reserved.
//  Created by Klevin on 2021/4/20.
//

#import <Foundation/Foundation.h>

@protocol KLNFullScreenContentDelegate;

/// 全屏类型广告协议（开屏/插屏/激励 均遵循此协议）
@protocol KLNFullScreenPresentingAd <NSObject>
/// 全屏视图展示/销毁消息回调代理
@property (nonatomic, weak, nullable) id<KLNFullScreenContentDelegate> fullScreenContentDelegate;
@end

/// 全屏广告内容展示（presentation）和销毁（dismissal）回调方法
/// 业务方可以通过回调方法，暂停或恢复 UI动画/计时器等
@protocol KLNFullScreenContentDelegate <NSObject>

@optional

/// 广告曝光上报成功回调方法
/// 业务方可以通过实现该方法，统计｜曝光｜量（对账）
/// @param ad 广告对象
- (void)adDidRecordImpression:(nonnull id<KLNFullScreenPresentingAd>)ad;

/// 广告响应点击事件回调方法
/// 业务方可以通过实现该方法，统计｜点击｜量（对账）
/// @param ad 广告对象
- (void)adDidRecordClick:(nonnull id<KLNFullScreenPresentingAd>)ad;

/// 广告响应跳过回调方法
/// 业务方可以通过实现该方法，统计广告｜跳过｜量（对账）
/// @param ad 广告对象
- (void)adDidRecordSkip:(nonnull id<KLNFullScreenPresentingAd>)ad;

/// 广告展示失败回调方法
/// 业务方可以通过实现该方法，处理广告展示失败事件；比如重新拉取广告
/// @param ad 广告对象
/// @param error 错误信息
- (void)ad:(nonnull id<KLNFullScreenPresentingAd>)ad
    didFailToPresentFullScreenContentWithError:(nonnull NSError *)error;

/// 广告视图展示（did appear）回调方法
/// 业务方可以通过实现该方法，暂停业务视图上的动画/计时器等UI操作
/// @param ad 广告对象
- (void)adDidPresentFullScreenContent:(nonnull id<KLNFullScreenPresentingAd>)ad;

/// 广告视图移除（dismissal）回调方法
/// 业务方可以通过实现该方法，恢复业务视图上的动画等UI操作
/// @param ad 广告对象
- (void)adDidDismissFullScreenContent:(nonnull id<KLNFullScreenPresentingAd>)ad;

@end

