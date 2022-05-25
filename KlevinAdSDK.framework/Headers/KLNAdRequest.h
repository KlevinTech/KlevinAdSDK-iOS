//
//  KLNAdRequest.h
//  KlevinAdSDK
//
//  Copyright © 2021 Tencent. All rights reserved.
//  Created by Klevin on 2021/4/20.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/// 请求对象基类，请勿直接使用
@interface KLNAdRequest : NSObject

/// 广告位ID
@property (nonatomic, copy, readonly) NSString *posId;

/// 请求ID
@property (nonatomic, copy, readonly) NSString *requestId;

- (instancetype)initWithPosId:(NSString *)posId;

@end

/// 新版开屏广告请求对象
@interface KLNSplashAdRequest : KLNAdRequest

/// 超时时长，单位s， 不设置默认5s
@property (nonatomic, assign) NSTimeInterval timeout;

/// 广告view的宽和高，不设置默认为屏幕宽和高
@property (nonatomic, assign) CGSize adSize;

@end

/// 插屏广告请求对象
@interface KLNInterstitialAdRequest : KLNAdRequest
@end

/// 激励视频请求对象
@interface KLNRewardedAdRequest : KLNAdRequest

/// 激励视频播放是否自动静音
/// @discussion 不设置，默认NO，非静音播放
@property (nonatomic, assign) BOOL autoMute;

/// 触发的激励类型，1：复活；2：签到；3：道具；4：虚拟货币；5：其他
/// @discussion 不设置，则默认为5
@property (nonatomic, assign) NSUInteger rewardTrigger;

/// 激励卡秒时长
/// @discussion 默认为视频时长/赋值大于视频时长或者为非正数时，SDK以视频时长为准
@property (nonatomic, assign) NSUInteger rewardTime;

@end

/// 视频素材下载策略
typedef NS_ENUM(NSInteger, KLNVideoDownloadPolicy) {
    KLNVideoDownloadPolicyAlways = 0,      ///< 默认自动下载视频
    KLNVideoDownloadPolicyWifiOnly,         ///< 仅WIFI环境自动下载视频
};

//视频播放策略
typedef NS_ENUM(NSUInteger, KLNVideoAutoPlayPolicy) {
    KLNVideoAutoPlayPolicyAlways = 0, // 总是自动播放，无论网络条件
    KLNVideoAutoPlayPolicyWIFI = 1, // WIFI 下自动播放
    KLNVideoAutoPlayPolicyNever = 2, // 从不自动播放，无论网络条件
};

/// 自渲染广告请求对象
@interface KLNUnifiedNativeAdRequest : KLNAdRequest

/// 一次请求自渲染广告个数，推荐请求1-3个，一次最多请求10个。
@property (nonatomic, assign) NSUInteger adCount;

/// 视频素材下载策略：控制视频素材下载时机
@property (nonatomic, assign) KLNVideoDownloadPolicy autoDownloadPolicy;

@end

/// 模版广告请求对象
@interface KLNTemplateAdRequest : KLNAdRequest

/// 一次请求模版广告个数，推荐请求1-3个，一次最多请求3个。不填默认为1。
@property (nonatomic, assign) NSUInteger adCount;

/// 请求广告的宽和高，SDK目前忽略设置的高度，建议填0。必填参数。
@property (nonatomic, assign) CGSize adSize;

/// 视频素材下载策略：控制视频素材下载时机。不设置,默认为始终下载视频(KLNVideoDownloadPolicyAlways)
@property (nonatomic, assign) KLNVideoDownloadPolicy autoDownloadPolicy;

/// 视频广告初始化时是否静音播放，默认静音播放
@property (nonatomic, assign) BOOL muted;

@end

NS_ASSUME_NONNULL_END
