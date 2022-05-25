//
//  KLNAdsDefines.h
//  Pods
//
//  Copyright © 2021 Tencent. All rights reserved.
//  Created by Klevin on 2021/4/20.
//

#import <Foundation/Foundation.h>

#if defined(__cplusplus)
#define KLN_EXTERN extern "C" __attribute__((visibility("default")))
#else
#define KLN_EXTERN extern __attribute__((visibility("default")))
#endif  // defined(__cplusplus)

#if __has_feature(attribute_deprecated_with_message)
#define KLN_DEPRECATED_MSG_ATTRIBUTE(s) __attribute__((deprecated(s)))
#elif __has_attribute(deprecated)
#define KLN_DEPRECATED_MSG_ATTRIBUTE(s) __attribute__((deprecated))
#else
#define KLN_DEPRECATED_MSG_ATTRIBUTE(s)
#endif  // __has_feature(attribute_deprecated_with_message)

#if __has_attribute(deprecated)
#define KLN_DEPRECATED_ATTRIBUTE __attribute__((deprecated))
#else
#define KLN_DEPRECATED_ATTRIBUTE
#endif  // __has_attribute(deprecated)

#define klevin_main_queue_excute(block)\
if ([NSThread isMainThread]) {\
block();\
} else {\
dispatch_async(dispatch_get_main_queue(), block);\
}

#define KLNHEX(colorValue) [UIColor colorWithRed:((CGFloat)((colorValue & 0xFF0000) >> 16)) / 255.f green:((CGFloat)((colorValue & 0x00FF00) >> 8)) / 255.f blue:((CGFloat)((colorValue & 0x0000FF) >> 0)) / 255.f alpha:1.0]
#define KLNHEXA(colorValue, alphaValue) [UIColor colorWithRed:((CGFloat)((colorValue & 0xFF0000) >> 16)) / 255.f green:((CGFloat)((colorValue & 0x00FF00) >> 8)) / 255.f blue:((CGFloat)((colorValue & 0x0000FF) >> 0)) / 255.f alpha:alphaValue]

#define KLNStringNotNil(_str_) (_str_ ?: @"")
#define KLNStringMultiline(...) [[NSString alloc] initWithCString:#__VA_ARGS__ encoding:NSUTF8StringEncoding]
#define KLNBlockExec(block, ...)  if (block) { block(__VA_ARGS__); };

/**
 强弱引用
 */
#define klnmacro_concat(A, B) A ## B
#define klnweak(VAR)             __weak   __typeof(VAR)  klnmacro_concat(VAR, _weak_) = (VAR)
#define klnstrong(VAR)           __strong __typeof(klnmacro_concat(VAR, _weak_)) VAR = klnmacro_concat(VAR, _weak_); if (!VAR) return



// Quick declare of singleton
#define KLNSingletonInterface(cls)  +(nonnull cls*)sharedInstance;

// Quick implement of singleton(allow multiple instance)
#define KLNSingletonImp(cls) \
static cls *gSharedInstance; \
+ (cls*)sharedInstance \
{ \
static dispatch_once_t onceToken; \
dispatch_once(&onceToken, ^{ \
gSharedInstance = [[self alloc] init]; \
}); \
return gSharedInstance; \
} \

// Quick implement of singleton(only have one instance)
#define KLNSingletonRestrictedImp(cls) \
static cls *gSharedInstance; \
+ (id)allocWithZone:(NSZone *)zone \
{ \
static dispatch_once_t onceToken; \
dispatch_once(&onceToken, ^{ \
gSharedInstance = [super allocWithZone:zone]; \
}); \
return gSharedInstance; \
} \
+ (cls*)sharedInstance \
{ \
static dispatch_once_t onceToken; \
dispatch_once(&onceToken, ^{ \
gSharedInstance = [[self alloc] init]; \
}); \
return gSharedInstance; \
} \
- (id)copyWithZone:(NSZone *)zone \
{ \
return gSharedInstance; \
}


#define KLNSuppressPerformSelectorLeakWarning(Stuff) \
    do { \
        _Pragma("clang diagnostic push") \
        _Pragma("clang diagnostic ignored \"-Warc-performSelector-leaks\"") \
        Stuff; \
        _Pragma("clang diagnostic pop") \
    } while (0)


#pragma mark - 系统版本号比较

#define KLN_SYSTEM_VERSION_LESS_THAN(v)                     ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)
#define KLN_SYSTEM_VERSION_GREATER_THAN(v)                  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
#define KLN_SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)      ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define KLN_SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v)         ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)
