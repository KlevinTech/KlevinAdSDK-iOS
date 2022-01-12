//
//  KLNAdReward.h
//  KlevinAdSDK
//
//  Copyright © 2021 Tencent. All rights reserved.
//  Created by Klevin on 2021/4/20.
//

#import <Foundation/Foundation.h>

/// A block to be executed when the user earns a reward.
typedef void (^KLNAdUserDidEarnRewardHandler)(void);

/// 奖励内容对象（流量方无需创建实例）
@interface KLNAdReward : NSObject

/// 奖励类型: 1：复活；2：签到；3：道具；4：虚拟货币；5：其他
@property(nonatomic, readonly, nonnull) NSString *type;

/// 奖励数量，默认为1
@property(nonatomic, readonly, nonnull) NSDecimalNumber *amount;

/// Returns an initialized KLNAdReward with the provided reward type and reward amount.
/// @param rewardType 奖励类型
/// @param rewardAmount 奖励数量
- (nonnull instancetype)initWithRewardType:(nonnull NSString *)rewardType
                              rewardAmount:(nonnull NSDecimalNumber *)rewardAmount;

@end
