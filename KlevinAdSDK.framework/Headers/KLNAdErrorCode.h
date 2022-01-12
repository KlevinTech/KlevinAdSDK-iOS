//
//  KLNAdErrorCode.h
//  KlevinAdSDK
//
//  Copyright © 2021 Tencent. All rights reserved.
//  Created by Klevin on 2021/4/20.
//

#import <KlevinAdSDK/KLNAdsDefines.h>

///// KLN Ads SDK  error domain.
KLN_EXTERN NSString * const KLNAdErrorDomain;

/// NSError codes for KLNAdErrorDomain
typedef NS_ENUM(NSInteger, KLNAdErrorCode) {
    /// 成功
    KLNAdErrorSucceed = 0,

    /// 应用ID异常
    KLNAdErrorAppIdException = 1110,
    /// 资源位异常
    KLNAdErrorAdUnitException = 1111,
    /// 资源位平台匹配异常
    KLNAdErrorCRMException = 1113,
    
    /// 广告请求成功，无广告填充
    KLNAdErrorNoFillA = 5300,
    KLNAdErrorNoFillB = 5301,
    KLNAdErrorNoFillC = 5302,
        
    /// 请求过于频繁
    KLNAdErrorLimitA = 5400,
    KLNAdErrorLimitB = 5402,

    ////////////////////////
    
    /// SDK初始化错误
    KLNAdErrorSDKInitError = 12001,
    /// SDK内部错误
    KLNAdErrorInternalError = 12002,
    /// SDK未初始化
    KLNAdErrorUninitialized = 12003,
    
    /// 网络异常
    KLNAdErrorNetworkException = 13001,
    /// 网络超时
    KLNAdErrorNetworkTimeout = 13002,
    /// 网络不可用
    KLNAdErrorNotReachable = 13003,
    
    /// 初始化错误
    KLNAdErrorInitException = 14001,
    /// 工程配置错误
    KLNAdErrorConfigError = 14002,
    /// 开屏广告拉取超时
    KLNAdErrorSplashTimeout = 14003,
    /// 资源位ID请求为空
    KLNAdErrorNullPosId = 14004,
    /// 广告数量错误
    KLNAdErrorInvalidAdCount = 14005,
    /// 应用横竖方向参数与广告位支持方向不匹配
    KLNAdErrorMismatchOrientation = 14006,
    /// 功能不可用
    KLNAdErrorInvalidFunction = 14007,
    /// 广告已曝光
    KLNAdErrorAdAlreadyUsed = 14008,
    /// 广告已过期
    KLNAdErrorAdInvalid = 14009,
    /// 请求广告传入参数错误
    KLNAdErrorInvalidRequestParams = 14010,
    /// 展示广告传入参数错误
    KLNAdErrorInvalidPresentParams = 14011,
    
    /// 服务端数据错误
    KLNAdErrorInvalidResponse = 15001,
    /// 视频素材下载错误
    KLNAdErrorDownloadVideo = 15002,
    /// 视频素材播放错误
    KLNAdErrorPlayVideo = 15003,
    /// 数据解析失败
    KLNAdErrorParseDataFail = 15004,
    /// 数据解析无Ad
    KLNAdErrorNoAdResponse = 15005,
    /// 返回数据缺失必要字段
    KLNAdErrorMissData = 15006,
    /// 缓存数据解析失败
    KLNAdErrorInvalidCache = 15007,
    /// 图片下载错误
    KLNAdErrorDownloadImage = 15008,
    /// 非主线程UI操作
    KLNAdErrorNotMainThread = 15009,
    
    /// 广告加载中
    KLNAdErrorAdNotReady,
   
};
