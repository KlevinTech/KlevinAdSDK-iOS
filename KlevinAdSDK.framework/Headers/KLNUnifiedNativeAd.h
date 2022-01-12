//
//  KLNUnifiedNativeAd.h
//  KlevinAdSDK
//
//  Copyright © 2021 Tencent. All rights reserved.
//  Created by Klevin on 2021/7/2.
//

#import <UIKit/UIKit.h>
#import <KlevinAdSDK/KLNAdRequest.h>
#import <KlevinAdSDK/KLNAdVideoController.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, KLNUnifiedNativeAdType) {
    /// 未知模版
    KLNUnifiedNativeAdTypeUnknown = 1,
    /// 原生自渲染-横版大图16：9
    KLNUnifiedNativeAdTypeHorBigImage = 1001,
    /// 原生自渲染-横版视频16：9
    KLNUnifiedNativeAdTypeHorVideo = 1002,
    
};

typedef NS_ENUM(NSUInteger, KLNUnifiedNativeAdVideoAutoPlayPolicy) {
    KLNUnifiedNativeAdVideoAutoPlayPolicyAlways = 0, // 总是自动播放，无论网络条件
    KLNUnifiedNativeAdVideoAutoPlayPolicyWIFI = 1, // WIFI 下自动播放
    KLNUnifiedNativeAdVideoAutoPlayPolicyNever = 2, // 从不自动播放，无论网络条件
};

@class KLNUnifiedNativeAd;
@protocol KLNUnifiedNativeAdDelegate;

/// 加载自渲染广告回调。
/// 成功时，adList不为nil, error为nil。失败时，adList为nil，error不为nil。
typedef void (^KLNUnifiedNativeAdLoadCompletionHandler)(NSArray<KLNUnifiedNativeAd *> *_Nullable adList,
                                                       NSError *_Nullable error);

///自渲染广告
@interface KLNUnifiedNativeAd : NSObject

/// 广告事件回调对象
@property (nonatomic, weak, nullable) id<KLNUnifiedNativeAdDelegate> delegate;

/// 开发者传入的用来present目标页的ViewController
@property (nonatomic, weak, readwrite) UIViewController *viewController;

/// 广告标题
@property (nonatomic, copy, readonly, nullable) NSString *title;

/// 广告描述
@property (nonatomic, copy, readonly, nullable) NSString *desc;

/// App 图标url
@property (nonatomic, readonly, nullable) NSString *appIconURL;

/// 按钮文案
@property (nonatomic, readonly, nullable) NSString *actionTitle;

/// 广告类型
@property (nonatomic, readonly) KLNUnifiedNativeAdType adType;

/// 广告图标
@property (nonatomic, readonly) UIImage *adLogoImage;

/// 静音播放视频广告（后续可能收拢到 KLNAdVideoController ）
@property (nonatomic, assign, getter=isMuted) BOOL muted;

/// 视频播放器
@property (nonatomic, strong, readonly, nullable) KLNAdVideoController *videoController;

/// 广告view
@property (nonatomic, strong, readonly) UIView *adView;

/// 广告宽度
@property (nonatomic, assign, readonly) CGFloat width;

/// 广告高度
@property (nonatomic, assign, readonly) CGFloat height;

/// 广告图片URL
@property (nonatomic, readonly, nullable) NSString *imageUrl;

/// 视频广告自动播放策略，默认 KLNUnifiedNativeAdVideoAutoPlayPolicyAlways（总是自动播放）
@property (nonatomic, assign) KLNUnifiedNativeAdVideoAutoPlayPolicy videoAutoPlayPolicy;

/// 加载自渲染广告方法
/// @param request 自渲染广告请求对象
/// @param completionHandler 广告信息加载结果回调（成功/失败），请注意：回调非线程安全
+ (void)loadWithRequest:(nonnull KLNUnifiedNativeAdRequest *)request
      completionHandler:(KLNUnifiedNativeAdLoadCompletionHandler)completionHandler;

/// 注册可点击View和显示广告的view。
/// @param clickableViews 可点击的视图数组，此数组内的广告元素会添加手势，可以响应广告对应的点击事件
/// @param adView  传入显示广告的view，SDK需要对此view做曝光检测
- (void)registerWithClickableViews:(NSArray<__kindof UIView *> *_Nullable)clickableViews adView:(UIView*)adView;

/// 解绑可点击view手势
- (void)unregisterClickableViews;

/// 渲染广告View
/// 注意：只有接入方用KLNUnifiedNativeAd的属性adView进行广告渲染才调用此方法。否则不需要调用
- (void)render;

/// 根据传入的宽度和广告model计算高度。内部会根据广告素材的宽高比计算相应的高度。
/// @param width 传入的宽度
/// @param nativeAd 广告model
+ (CGFloat)calcHeiWithWidth:(CGFloat)width nativeAd:(KLNUnifiedNativeAd *)nativeAd;

/// 用户手动关闭广告时，请调用该方法
- (void)dislike;


@end

@protocol KLNUnifiedNativeAdDelegate <NSObject>

@optional

/// 广告素材加载结果回调
/// @param ad  KLNUnifiedNativeAd实例
/// @param error 素材加载成功为nil，失败非nil
- (void)kln_unifiedNativeAdDidLoad:(KLNUnifiedNativeAd *)ad didCompleteWithError:(NSError *_Nullable)error;

/// 广告曝光回调
/// 业务方可以通过实现该方法，统计｜曝光｜量（对账）
/// @param ad  KLNUnifiedNativeAd 实例
- (void)kln_unifiedNativeAdWillExpose:(KLNUnifiedNativeAd *)ad;

/// 广告点击回调
/// 业务方可以通过实现该方法，统计｜点击｜量（对账）
/// @param ad KLNUnifiedNativeAd 实例
- (void)kln_unifiedNativeAdDidClick:(KLNUnifiedNativeAd *)ad;

@end

NS_ASSUME_NONNULL_END
