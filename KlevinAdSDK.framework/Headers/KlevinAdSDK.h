//
//  KlevinAdSDK.h
//  KlevinAdSDK
//
//  Copyright © 2021 Tencent. All rights reserved.
//  Created by Klevin on 2021/4/24.
//

#import <UIKit/UIKit.h>
#import <KlevinAdSDK/KLNAdRequest.h>
#import <KlevinAdSDK/KLNAdsDefines.h>
#import <KlevinAdSDK/KLNAdEnumTypes.h>
#import <KlevinAdSDK/KLNAdErrorCode.h>
#import <KlevinAdSDK/KLNAdVideoController.h>
#import <KlevinAdSDK/KLNAdBiddingProtocol.h>
#import <KlevinAdSDK/KlevinAdSDKConfiguration.h>
#import <KlevinAdSDK/KLNFullScreenContentDelegate.h>

NS_ASSUME_NONNULL_BEGIN

/// SDK初始化方法回调 [KlevinAdSDK startWithCompletionHandler:]
/// error为空则表示初始化成功，回调非线程安全
typedef void (^KLNAdInitializationCompletionHandler)(NSError *_Nullable error);

/// SDK初始化、设置入口类
@interface KlevinAdSDK : NSObject

/// 当前SDK版本号
+ (NSString *)sdkVersion;

/// 返回KlevinAdSDK实体（单例）
+ (KlevinAdSDK *)sharedInstance;

/// 输出SDK调试信息
- (void)enableDebugLogout;

/// 是否允许获取定位信息，权限需由接入方获取，SDK不会主动弹框申请
/// 基于用户地理信息，系统能推荐更精准的个性化广告，提升广告收益
/// 默认为YES
- (void)enableGPS:(BOOL)enabled DEPRECATED_MSG_ATTRIBUTE("Please use [KlevinAdSDKConfiguration.configuration setAllowAccessLocation:]");

/// 初始化SDK，从Info.plist 读取KlevinApplicationIdentifier配置
/// 相关配置方式见文档说明：集成及初始化SDK，默认使用KlevinAdSDKConfiguration.configuration
/// @param completionHandler 初始化结果回调 ，非线程安全
- (void)startWithCompletionHandler:(nullable KLNAdInitializationCompletionHandler)completionHandler;

/// 初始化SDK
/// @param appId 平台注册APPID
/// @param completionHandler 初始化结果回调 ，非线程安全
- (void)startWithAppId:(NSString *)appId withCompletionHandler:(nullable KLNAdInitializationCompletionHandler)completionHandler;

#pragma mark - 新增SDK配置入口

/// 初始化SDK，从Info.plist 读取KlevinApplicationIdentifier配置
/// 相关配置方式见文档说明：集成及初始化SDK，默认使用KlevinAdSDKConfiguration.configuration
/// @param completionHandler 初始化结果回调 ，非线程安全
/// @param configuration SDK配置类，默认使用KlevinAdSDKConfiguration.configuration
- (void)startWithCompletionHandler:(nullable KLNAdInitializationCompletionHandler)completionHandler
                 withConfiguration:(nullable KlevinAdSDKConfiguration *)configuration;

/// 初始化SDK
/// @param appId 平台注册APPID
/// @param completionHandler 初始化结果回调 ，非线程安全
/// @param configuration SDK配置类，如果不传入默认使用KlevinAdSDKConfiguration.configuration
- (void)startWithAppId:(NSString *)appId
 withCompletionHandler:(nullable KLNAdInitializationCompletionHandler)completionHandler
     withConfiguration:(nullable KlevinAdSDKConfiguration *)configuration;

@end

NS_ASSUME_NONNULL_END
