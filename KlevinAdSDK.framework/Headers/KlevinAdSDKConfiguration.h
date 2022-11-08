//
//  KlevinAdSDKConfiguration.h
//  KlevinAdSDK
//
//  Created by ArvinLiang on 2021/11/29.
//  Copyright © 2021 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 日志回调代理
@protocol KLNLoggingDelegate <NSObject>

/// 日志回调函数
/// @param message 日志内容
- (void)logWithMessage:(nullable NSString *)message;

@end

/// SDK配置类
/// 应用生命周期内，共享一个实例
@interface KlevinAdSDKConfiguration : NSObject

/// 默认配置，共享一个实例
@property (nonatomic, class, readonly) KlevinAdSDKConfiguration *configuration;

/// 是否允许获取定位信息，权限需由接入方获取，SDK不会主动弹框申请
/// 基于用户地理信息，系统能推荐更精准的个性化广告，提升广告收益
/// 默认为YES
@property (atomic, assign) BOOL allowAccessLocation;

/// 当前设备的经度：可接入方传递
@property (atomic, assign) float userLongitude;

/// 当前设备的纬度：可接入方传递
@property (atomic, assign) float userLatitude;

/// 是否允许获取设备IDFA，权限需由接入方获取，SDK不会主动弹框申请IDFA的访问权限
/// 若当前用户允许访问IDFA信息，且 allowAccessIDFA 为 YES，则SDK会访问IDFA信息
/// 默认为YES
@property (atomic, assign) BOOL allowAccessIDFA;

/// 接入方指定IDFA的值（若媒体传入非nil值，则SDK不会请求IDFA）
@property (atomic, copy, nullable) NSString *mediaIDFA;

/// 用户设备的CAID信息（若媒体传入非nil值，则SDK不会请求CAID）
@property (atomic, copy, nullable) NSString *mediaCAID;

/// 是否允许广告个性化推荐。如果不设置，默认为YES。
@property (atomic, assign) BOOL allowPersonalizedRecommendation;

/// 是否输出SDK调试信息。默认不输出
@property (nonatomic, assign) BOOL enableDebugLogout;

/// SDK调试信息协议。当设置enableDebugLogout为YES，实现logDelegate方法可以获取SDK调试信息
@property (nonatomic, weak, nullable) id<KLNLoggingDelegate> logDelegate;

@end

NS_ASSUME_NONNULL_END
