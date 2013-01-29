//
//  MTStatusBarOverlay+TimeTracking.h
//  MTStatusBarOverlay
//
//  Created by Yasuhiro Inami on 13/01/28.
//  Copyright (c) 2013年 Yasuhiro Inami. All rights reserved.
//

#import "MTStatusBarOverlay.h"

@interface MTStatusBarOverlay (TimeTracking)

#if defined(DEBUG) || defined(MT_DEBUG)
#   define MT_START_TIME(name)  [MTStatusBarOverlay startTimeTrackingWithName:name]
#   define MT_STOP_TIME(name)   [MTStatusBarOverlay stopTimeTrackingWithName:name]
#else
#   define MT_START_TIME(name)  ;
#   define MT_STOP_TIME(name)   ;
#endif

- (void)startTimeTrackingWithName:(NSString*)name;
- (void)stopTimeTrackingWithName:(NSString*)name;

// convenient methods
+ (void)startTimeTrackingWithName:(NSString*)name;
+ (void)stopTimeTrackingWithName:(NSString*)name;

@end
