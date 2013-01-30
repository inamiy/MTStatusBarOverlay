//
//  MTStatusBarOverlayMacros.h
//  MTStatusBarOverlay
//
//  Created by Yasuhiro Inami on 13/01/30.
//  Copyright (c) 2013年 Yasuhiro Inami. All rights reserved.
//

#ifndef MTStatusBarOverlay_MTStatusBarOverlayMacros_h
#define MTStatusBarOverlay_MTStatusBarOverlayMacros_h

#if defined(DEBUG) || defined(MT_DEBUG)
#   define MT_POST(message)     [[MTStatusBarOverlay sharedInstance] postMessage:message]
#   define MT_FINISH(message)   [[MTStatusBarOverlay sharedInstance] postFinishMessage:message duration:2]
#   define MT_ERROR(message)    [[MTStatusBarOverlay sharedInstance] postErrorMessage:message duration:2]
#   define MT_CLEAR             [[MTStatusBarOverlay sharedInstance] postImmediateMessage:nil animated:NO]
#   define MT_START_TIME(name)  [MTStatusBarOverlay startTimeTrackingWithName:name]
#   define MT_STOP_TIME(name)   [MTStatusBarOverlay stopTimeTrackingWithName:name duration:2]
#else
#   define MT_POST(message)     ;
#   define MT_FINISH(message)   ;
#   define MT_ERROR(message)    ;
#   define MT_CLEAR             ;
#   define MT_START_TIME(name)  ;
#   define MT_STOP_TIME(name)   ;
#endif

#endif