//
//  KLNTemplateAd.h
//  KlevinAdSDK
//
//  Copyright © 2021 Tencent. All rights reserved.
//  Created by Klevin on 2021/11/23.
//

#import <UIKit/UIKit.h>
#import <KlevinAdSDK/KLNAdRequest.h>
#import <KlevinAdSDK/KLNAdVideoController.h>
#import <KlevinAdSDK/KLNAdBiddingProtocol.h>

NS_ASSUME_NONNULL_BEGIN


@class KLNTemplateAd;
@protocol KLNTemplateAdDelegate;

/// 加载模版广告回调。
/// 成功时，adList不为nil, error为nil。失败时，adList为nil，error不为nil。
typedef void (^KLNTemplateAdLoadCompletionHandler)(NSArray<KLNTemplateAd *> *_Nullable adList,
                                                       NSError *_Nullable error);

///模版广告。请注意，在主线程中使用该类！！！
@interface KLNTemplateAd : NSObject<KLNAdBiddingProtocol>

/// 广告事件回调对象
@property (nonatomic, weak, nullable) id<KLNTemplateAdDelegate> delegate;

/// 开发者传入的用来present目标页的ViewController
@property (nonatomic, weak, readwrite) UIViewController *viewController;

/// 是否视频广告
@property (nonatomic, readonly) BOOL videoAd;

/// 视频播放器
@property (nonatomic, strong, readonly, nullable) KLNAdVideoController *videoController;

/// 广告view
@property (nonatomic, strong, readonly) UIView *adView;

/// 视频广告自动播放策略，默认 KLNVideoAutoPlayPolicyAlways（总是自动播放）
@property (nonatomic, assign) KLNVideoAutoPlayPolicy videoAutoPlayPolicy;

/// 广告推广类型： 2=下载广告；3=网页推广广告
@property (nonatomic, assign, readonly) NSInteger promotedType;

/// 加载模版广告方法
/// @param request 模版广告请求对象
/// @param completionHandler 广告信息加载结果回调（成功/失败），请注意：回调非线程安全
+ (void)loadWithRequest:(nonnull KLNTemplateAdRequest *)request
      completionHandler:(KLNTemplateAdLoadCompletionHandler)completionHandler;

/// 渲染广告View
- (void)render;

@end

@protocol KLNTemplateAdDelegate <NSObject>

@optional

/// 广告曝光回调
/// 业务方可以通过实现该方法，统计｜曝光｜量（对账）
/// @param ad  KLNTemplateAd 实例
- (void)kln_templateAdWillExpose:(KLNTemplateAd *)ad;

/// 广告点击回调
/// 业务方可以通过实现该方法，统计｜点击｜量（对账）
/// @param ad KLNTemplateAd 实例
- (void)kln_templateAdDidClick:(KLNTemplateAd *)ad;

/// 原生模板广告被关闭
/// @param ad  KLNTemplateAd 实例
- (void)kln_templateAdClosed:(KLNTemplateAd *)ad;

/// 原生模板广告渲染成功, 此时的 ad.adView.frame.size.height 根据请求广告传入的width完成了动态更新。
/// @param ad  KLNTemplateAd 实例
- (void)kln_templateAdRenderSuccess:(KLNTemplateAd *)ad;

/// 原生模板广告渲染失败
/// @param ad  KLNTemplateAd 实例
///  @param error  错误码
- (void)kln_templateAdRenderFail:(KLNTemplateAd *)ad error:(NSError *)error;


/// 广告跳转到其他控制器时，控制器被关闭时调用
/// @param ad KLNTemplateAd 实例
/// @param interactionType  KLNInteractionType枚举类型，包括Appstore/网页/视频详情页等
- (void)kln_templateAdDidCloseOtherController:(KLNTemplateAd *)ad interactionType:(KLNInteractionType)interactionType;
@end

NS_ASSUME_NONNULL_END
