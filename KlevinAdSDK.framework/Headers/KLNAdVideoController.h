//
//  KLNAdVideoController.h
//  KlevinAdSDK
//
//  Copyright © 2021 Tencent. All rights reserved.
//  Created by Klevin on 2021/4/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol KLNAdVideoControllerDelegate;

/// The video controller class provides a way to  manages video content of the ad rendered by the SDK.
/// You don't need to create an instance of this class.
/// When the ad rendered by the SDK loads video content, you may be able to get an instance of this class from the rendered ad object.
@interface KLNAdVideoController : NSObject

/// Delegate for receiving video notifications.
@property(nonatomic, weak, nullable) id<KLNAdVideoControllerDelegate> delegate;

@end

/// The KLNAdVideoControllerDelegate protocol defines methods that are called by the video controller
/// object in response to the video events that occurred throughout the lifetime of the video
/// rendered by an ad.
@protocol KLNAdVideoControllerDelegate <NSObject>

@optional

/// Tells the delegate that the video controller has began or resumed playing a video.
/// @param videoController controller instance
- (void)videoControllerDidPlayVideo:(nonnull KLNAdVideoController *)videoController;

/// Tells the delegate that the video controller has paused video.
/// @param videoController controller instance
- (void)videoControllerDidPauseVideo:(nonnull KLNAdVideoController *)videoController;

/// Tells the delegate that the video controller's video playback has ended.
/// @param videoController controller instance
- (void)videoControllerDidEndVideoPlayback:(nonnull KLNAdVideoController *)videoController;

/// Tells the delegate that the video controller has muted video.
/// @param videoController controller instance
- (void)videoControllerDidMuteVideo:(nonnull KLNAdVideoController *)videoController;

/// Tells the delegate that the video controller has unmuted video.
/// @param videoController controller instance
- (void)videoControllerDidUnmuteVideo:(nonnull KLNAdVideoController *)videoController;

@end

NS_ASSUME_NONNULL_END
