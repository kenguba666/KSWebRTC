//
//  KSWebRTCManager.h
//  KSWebRTC
//
//  Created by saeipi on 2020/8/12.
//  Copyright © 2020 saeipi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KSMediaCapturer.h"
#import "KSMediaConnection.h"
#import "KSCallState.h"
#import "KSMsg.h"
#import "KSMessageHandler.h"
#import "KSKitManager.h"

@class KSWebRTCManager;
@protocol KSWebRTCManagerDelegate <NSObject>
@optional
//socket
- (void)webRTCManagerHandlerEnd:(KSWebRTCManager *)webRTCManager;
- (void)webRTCManager:(KSWebRTCManager *)webRTCManager didReceivedMessage:(KSMsg *)message;
- (void)webRTCManager:(KSWebRTCManager *)webRTCManager leaveOfConnection:(KSMediaConnection *)connection;
- (void)webRTCManagerSocketDidOpen:(KSWebRTCManager *)webRTCManager;
- (void)webRTCManagerSocketDidFail:(KSWebRTCManager *)webRTCManager;

//Media
- (void)webRTCManager:(KSWebRTCManager *)webRTCManager didAddMediaConnection:(KSMediaConnection *)connection;

@end

@interface KSWebRTCManager : NSObject

@property(nonatomic,weak)id<KSWebRTCManagerDelegate>    delegate;
@property (nonatomic, weak, readonly) AVCaptureSession  *captureSession;
@property (nonatomic, weak, readonly) KSMediaConnection *localConnection;
@property (nonatomic, strong) KSMediaSetting    *mediaSetting;
@property (nonatomic, assign) KSCallType        callType;
@property (nonatomic, assign) BOOL             isConnect;
@property (nonatomic, assign) KSCallState       callState;
@property (nonatomic, strong) NSMutableArray    *mediaConnections;
@property (nonatomic, assign, readonly) int     connectCount;
+ (instancetype)shared;
- (void)initRTCWithMediaSetting:(KSMediaSetting *)mediaSetting;

//MediaCapture
+ (void)switchCamera;
+ (void)switchTalkMode;
+ (void)startCapture;
+ (void)stopCapture;
+ (void)speakerOff;
+ (void)speakerOn;
+ (void)muteAudio;
+ (void)unmuteAudio;

+ (void)clearAllRenderer;

- (void)close;
+ (void)close;

//Socket
+ (void)socketConnectServer:(NSString *)server;
+ (void)socketClose;
+ (void)socketCreateSession;
+ (void)socketSendHangup;

//data
+ (KSMediaConnection *)connectionOfIndex:(NSInteger)index;
+ (NSInteger)connectionCount;
+ (void)removeConnectionAtIndex:(int)index;

@end
