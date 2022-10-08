//
//  KLNAdEnumTypes.h
//  KlevinAdSDK
//
//  Copyright © 2021 Tencent. All rights reserved.
//  Created by Klevin on 2021/4/20.
//

#import <Foundation/Foundation.h>
#import "KLNAdsDefines.h"

/// 广告样式
typedef NS_ENUM(NSInteger, KLNAdFormat) {
    KLNAdFormatSplash = 1,                ///< 开屏广告（Splash）
    KLNAdFormatInterstitial,              ///< 插屏广告（Interstitial）
    KLNAdFormatRewarded,                  ///< 激励广告（Rewarded）
    KLNAdFormatUnifiedNative,             ///< 自渲染广告（UnifiedNative）
    KLNAdFormatTemplate,                  ///< 模版广告（Template）
};

/// 广告创意模版
typedef NS_ENUM(NSInteger, KLNAdTemplateType) {
    /// 未知模版
    KLNAdTemplateTypeNone = 0,
    /// 开屏大图
    KLNAdTemplateTypeSplashImage = 100,
    /// 开屏视频
    KLNAdTemplateTypeSplashVideo = 101,
    /// 激励竖版
    KLNAdTemplateTypeVerticalRewarded = 102,
    /// 激励横版
    KLNAdTemplateTypeHorizontalRewarded = 103,
    /// 插屏1：1
    KLNAdTemplateTypeInterstitial11 = 104,
    /// 插屏9：16
    KLNAdTemplateTypeInterstitial916 = 105,
    /// 原生自渲染-横版大图16：9
    KLNAdTemplateTypeUnifiedNativeAdHorBigImage = 201,
    /// 原生自渲染-横版视频16：9
    KLNAdTemplateTypeUnifiedNativeAdHorVideo = 202,
    /// 原生自渲染-竖版大图9：16
    KLNAdTemplateTypeUnifiedNativeAdVerBigImage = 203,
    /// 原生自渲染-竖版视频9：16
    KLNAdTemplateTypeUnifiedNativeAdVerVideo = 204,
    
    /// 互动广告横版
    KLNAdTemplateTypeHorInteractive = 301,
    /// 互动广告竖版
    KLNAdTemplateTypeVerInteractive = 302,
};
//
typedef NS_ENUM(NSInteger, KLNInteractionType) {
    KLNInteractionTypeUnknown       = 0,
    KLNInteractionTypeInnerWeb      = 1,                // 落地页
    KLNInteractionTypeAppStore      = 2,                // 下载页
    KLNInteractionTypeVideoAdDetail = 3                 // 视频详情页
};

/// Bidding
typedef NS_ENUM(NSInteger, KLNAdBiddingLossReason) {
    KLNAdBiddingLossReasonNone              = 1,        // 竞得
    KLNAdBiddingLossReasonLowPrice          = 2711,     // 竞争力不足
    KLNAdBiddingLossReasonTimeOut           = 2712,     // 返回超时
    KLNAdBiddingLossReasonNoAd              = 2713,     // 无广告回包
    KLNAdBiddingLossReasonOther             = 2714,     // 其他原因
};


/// 投放方式
typedef NS_ENUM(NSInteger, KLNAdDeliveryType) {
    KLNAdDeliveryTypeDefault                = 0,
    KLNAdDeliveryTypeDownload               = 1,     // 直接下载
    KLNAdDeliveryTypeInnerWeb               = 2,     // 落地页
};

typedef NSString *KLNAdBidingAdnID NS_STRING_ENUM;
/// 输给游可赢其他广告
KLN_EXTERN KLNAdBidingAdnID const KLNAdBidingAdnIDYKYAd;

/// 输给第三方ADN
KLN_EXTERN KLNAdBidingAdnID const KLNAdBidingAdnIDThirdParty;

/// 输给自售广告主
KLN_EXTERN KLNAdBidingAdnID const KLNAdBidingAdnIDSelfOwn;

