//
//  MTStatusBarOverlay+TimeTracking.m
//  MTStatusBarOverlay
//
//  Created by Yasuhiro Inami on 13/01/28.
//  Copyright (c) 2013年 Yasuhiro Inami. All rights reserved.
//

#import "MTStatusBarOverlay+TimeTracking.h"

const char MTTrackingTimeDictionaryKey;

@implementation MTStatusBarOverlay (TimeTracking)

- (NSMutableDictionary*)trackingTimeDictionary
{
    NSMutableDictionary* trackingTimeDictionary = objc_getAssociatedObject(self, &MTTrackingTimeDictionaryKey);
    if (!trackingTimeDictionary) {
        trackingTimeDictionary = [@{} mutableCopy];
        objc_setAssociatedObject(self, &MTTrackingTimeDictionaryKey, trackingTimeDictionary, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    }
    return trackingTimeDictionary;
}

- (void)startTimeTrackingWithName:(NSString*)name
{
    if (![self.trackingTimeDictionary objectForKey:name]) {
        [self postMessage:[NSString stringWithFormat:@"%@...",name] animated:YES];
        
        CFAbsoluteTime startTime = CFAbsoluteTimeGetCurrent();
        [self.trackingTimeDictionary setObject:@(startTime) forKey:name];
    }
}

- (void)stopTimeTrackingWithName:(NSString*)name
{
    CFAbsoluteTime startTime = [[self.trackingTimeDictionary objectForKey:name] doubleValue];
    CFAbsoluteTime elapsedTime = CFAbsoluteTimeGetCurrent() - startTime;
    
    if ([self.trackingTimeDictionary objectForKey:name]) {
        [self.trackingTimeDictionary removeObjectForKey:name];
        
        [self postFinishMessage:[NSString stringWithFormat:@"%@: %f",name,elapsedTime] duration:2 animated:YES];
    }
}

+ (void)startTimeTrackingWithName:(NSString*)name
{
    MTStatusBarOverlay* overlay = [MTStatusBarOverlay sharedInstance];
    overlay.animation = MTStatusBarOverlayAnimationFallDown;
    overlay.detailViewMode = MTDetailViewModeHistory;

    [overlay startTimeTrackingWithName:name];
}

+ (void)stopTimeTrackingWithName:(NSString*)name
{
    MTStatusBarOverlay* overlay = [MTStatusBarOverlay sharedInstance];
    [overlay stopTimeTrackingWithName:name];
}

@end
