//
//  lsMediaCapture.h
//  lsMediaCapture
//
//  Created by NetEase on 15/8/12.
//  Copyright (c) 2015年 NetEase. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import "nMediaLiveStreamingDefs.h"

///直播类LSMediacapture，用于推流
@interface LSMediaCapture : NSObject

/**
 *  直播过程中发生错误的回调函数
 *
 *  @param error 具体错误信息
 */
@property (nonatomic,copy) void (^onLiveStreamError)(NSError *error);
/**
 *  初始化mediacapture
 *
 *  @param  liveStreamingURL 推流的url地址
 *
 *  @return LSMediaCapture
 */
- (instancetype)initLiveStream:(NSString *)liveStreamingURL;
/**
 *  初始化mediacapture
 *
 *  @param  liveStreamingURL 推流的url
 *  @param  videoParaCtx 推流视频参数
 *
 *  @return LSMediaCapture
 */
- (instancetype)initLiveStream:(NSString *)liveStreamingURL withVideoParaCtx:(LSVideoParaCtx)videoParaCtx ;
/**
 *  初始化mediacapture
 *
 *  @param  liveStreamingURL 推流的url
 *  @param  lsParaCtx 推流参数
 *
 *  @return LSMediaCapture
 */
- (instancetype)initLiveStream:(NSString *)liveStreamingURL withLivestreamParaCtx:(LSLiveStreamingParaCtx)lsParaCtx;

/**
 *  打开视频预览
 *
 *  @param  preview 预览窗口
 */
-(void)startVideoPreview:(UIView*)preview;

/**
 *  @warning 暂停视频预览，如果正在直播，则同时关闭视频预览以及视频推流
 *
 */
-(void)pauseVideoPreview;

/**
 *  @warning 继续视频预览，如果正在直播，则开始视频推流
 *
 *
 */
-(void)resumeVideoPreview;

/**
 *  开始直播
 *
 *  @param outError 具体错误信息
 */

- (BOOL)startLiveStreamWithError:(NSError**)outError;

/**
 *  结束推流
 */
- (BOOL)stopLiveStream;

/**
 *  中断推流，但不释放资源，推流url不切换，状态保持
 */
- (BOOL)pauseLiveStream;

/**
 *  继续推流
 */
- (BOOL)resumeLiveStream;

/**
 *  开始视频推流，
 *  @warning 需要先启动推流startLiveStreamWithError，开启视频或者音视频推流，才可以关闭视频推流，打开视频推流，
 */
- (void)startVideoLiveStream;

/**
 *  结束视频推流，
 *  @warning 需要先启动推流startLiveStreamWithError，开启视频或者音视频推流，才可以关闭视频推流，打开视频推流，
 */
- (void)stopVideoLiveStream;

/**
 *  重启开始视频推流 
 *  @warning 需要先启动推流startLiveStreamWithError，开启视频或者音视频推流，才可以中断视频推流，重启视频推流，
 */
- (void)resumeVideoLiveStream;

/**
 *  中断视频推流 
 *  @warning 需要先启动推流startLiveStreamWithError，开启视频或者音视频推流，才可以中断视频推流，重启视频推流，
 */
- (void)pauseVideoLiveStream;

/**
 *  开始音频推流，
 *  @warning 需要先启动推流startLiveStreamWithError，开启音频或者音视频推流，才可以关闭音频推流，打开音频推流，
 */
- (BOOL)startAudioLiveStream;

/**
 *  结束音频推流，
 *  @warning：需要先启动推流startLiveStreamWithError，开启音频或者音视频推流，才可以关闭音频推流，打开音频推流，
 */
- (BOOL)stopAudioLiveStream;

/**
 *  重启音频推流，
 *  @warning：需要先启动推流startLiveStreamWithError，开启音频或者音视频推流，才可以中断音频推流，重启音频推流，
 */
- (BOOL)resumeAudioLiveStream;

/**
 *  中断音频推流，
 *  @warning：需要先启动推流startLiveStreamWithError，开启音频或者音视频推流，才可以中断音频推流，重启音频推流，
 */
- (BOOL)pauseAudioLiveStream;


/**
 *  切换前后摄像头
 *
 *  @return 当前摄像头的位置，前或者后
 */
- (LSCameraPosition)switchCamera;


/**
 *  设置统计参数频率
 *
 *  @param timeInterval 统计信息计算粒度
 */
-(BOOL)setStatisticTimeInterval:(int)timeInterval;

/**
 *  得到直播过程中的统计信息
 *
 *  @param statistics 统计信息结构体 
 *
 */
-(BOOL)getStatisticInfo:(LSStatistics*)statistics;
/**
 *  设置trace 的level
 *
 *  @param loglevl trace 信息的级别
 */
-(void)setTraceLevel:(LSMediaLog)logLevel;
/**
 *  设置trace 的callback
 *
 *  @param  trace的输出回调
 */

-(void)setTraceCallBack:(void(^)(void * ctx, const char * kpFmt,va_list* va)) traceCallBackBlock;

/**
 *  获取当前sdk的版本号
 *
 */
-(NSString*) getSDKVersionID;


@end



