//
//  KSCallView.h
//  KSWebRTC
//
//  Created by saeipi on 2020/8/2.
//  Copyright © 2020 saeipi. All rights reserved.
//

#import "KSEventCallbackView.h"
#import <AVFoundation/AVFoundation.h>
//Configure
#import "KSConfigure.h"
#import "KSBlock.h"

//ViewModel
#import "KSTileLayout.h"
#import "KSProfileConfigure.h"

//Kit
#import "KSRemoteView.h"

@class KSCallView;

@protocol KSVideoCallViewDelegate <NSObject>
@optional
- (void)videoCallViewDidChangeRoute:(KSCallView *)view;
- (void)videoCallViewDidEnableStats:(KSCallView *)view;
- (void)videoCallViewDidHangup:(KSCallView *)view;
- (void)videoCallViewDidSwitchCamera:(KSCallView *)view;
@end

@interface KSCallView : KSEventCallbackView

@property(nonatomic,weak)id<KSVideoCallViewDelegate> delegate;
@property(nonatomic,assign)CGFloat topPadding;

- (instancetype)initWithFrame:(CGRect)frame layout:(KSTileLayout *)layout callType:(KSCallType)callType;
- (void)createLocalViewWithLayout:(KSTileLayout *)layout resizingMode:(KSResizingMode)resizingMode callType:(KSCallType)callType;
- (void)leaveOfHandleId:(NSNumber *)handleId;
- (RTCMTLVideoView *)remoteViewOfHandleId:(NSNumber *)handleId;
- (RTCMTLVideoView *)localVideoView;
//KIT:KSProfileView
- (void)setProfileConfigure:(KSProfileConfigure *)configure;
//KIT:KSAnswerBarView
- (void)setAnswerState:(KSAnswerState)state;
- (void)hideAnswerBar;
//KIT:KSCallBarView
- (void)displayCallBar;

@end
