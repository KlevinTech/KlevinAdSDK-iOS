//
//  KlevinAdSDKConfiguration.h
//  KlevinAdSDK
//
//  Created by ArvinLiang on 2021/11/29.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

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

@end

NS_ASSUME_NONNULL_END
