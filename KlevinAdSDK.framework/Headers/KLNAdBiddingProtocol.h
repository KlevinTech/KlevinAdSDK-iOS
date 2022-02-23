//
//  KLNAdBiddingProtocol.h
//  KlevinAdSDK
//
//  Copyright © 2021 Tencent. All rights reserved.
//  Created by Klevin on 2022/1/21.
//

#import <Foundation/Foundation.h>
#import <KlevinAdSDK/KLNAdEnumTypes.h>

NS_ASSUME_NONNULL_BEGIN

@protocol KLNAdBiddingProtocol <NSObject>

/// 返回广告的 eCPM，单位：分
/// @return 成功返回一个大于等于0的值，-1表示无权限或后台出现异常
- (NSInteger)eCPM;

/// 竞胜之后调用, 需要在调用 present 广告之前调用
/// @param price - 竞胜价格 (单位: 分)
- (void)sendWinNotificationWithPrice:(NSInteger)price;

/// 竞败之后调用
/// @param price - 竞胜价格 (单位: 分)
/// @param reason - 竞败原因
/// @param adnID - adnID
///      KLNAdBidingAdnIDYKYAd：输给游可赢其他广告
///      KLNAdBidingAdnIDThirdParty：输给第三方ADN
///      KLNAdBidingAdnIDSelfOwn：输给自售广告主
- (void)sendLossNotificationWithWinnerPrice:(NSInteger)price lossReason:(KLNAdBiddingLossReason)reason winnerAdnID:(KLNAdBidingAdnID _Nullable)adnID;

@end

NS_ASSUME_NONNULL_END
