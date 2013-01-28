//
//  MTStatusBarOverlay+TimeTracking.h
//  MTStatusBarOverlay
//
//  Created by Yasuhiro Inami on 13/01/28.
//  Copyright (c) 2013年 Yasuhiro Inami. All rights reserved.
//

#import "MTStatusBarOverlay.h"

@interface MTStatusBarOverlay (TimeTracking)

- (void)startTimeTrackingWithName:(NSString*)name;
- (void)stopTimeTrackingWithName:(NSString*)name;

// convenient methods
+ (void)startTimeTrackingWithName:(NSString*)name;
+ (void)stopTimeTrackingWithName:(NSString*)name;

@end
