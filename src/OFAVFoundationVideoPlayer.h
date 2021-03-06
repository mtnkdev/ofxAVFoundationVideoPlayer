//
//  OFAVFoundationVideoPlayer.h
//  Created by lukasz karluk on 06/07/14.
//  http://julapy.com
//

//----------------------------------------------------------
#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <Accelerate/Accelerate.h>
#import "OFAVFoundationVideoPlayerView.h"

@class AVPlayer;
@class AVPlayerItem;
@class AVAsset;
@class AVAssetReader;
@class AVAssetReaderOutput;

//---------------------------------------------------------- video player delegate.
@protocol OFAVFoundationVideoPlayerDelegate <NSObject>
@optional
- (void)playerReady;
- (void)playerDidProgress;
- (void)playerDidFinishSeeking;
- (void)playerDidFinishPlayingVideo;
@end

//---------------------------------------------------------- video player.
@interface OFAVFoundationVideoPlayer : NSObject {

    id<OFAVFoundationVideoPlayerDelegate> delegate;
    
    OFAVFoundationVideoPlayerView * _playerView;
    AVPlayer * _player;
    AVPlayerItem * _playerItem;
    AVAsset * _asset;
    AVAssetReader * _assetReader;
    AVAssetReaderTrackOutput * _assetReaderVideoTrackOutput;
    AVAssetReaderTrackOutput * _assetReaderAudioTrackOutput;
    
    id timeObserver;
    int timeObserverFps;
    
	CMSampleBufferRef videoSampleBuffer;
    CMSampleBufferRef audioSampleBuffer;
    CMTime videoSampleTime;
    CMTime videoSampleTimePrev;
    CMTime audioSampleTime;
    CMTime synchSampleTime;
	CMTime duration;
    CMTime currentTime;
    float volume;
    float speed;
    float frameRate;
    
    NSInteger videoWidth;
    NSInteger videoHeight;
    
    BOOL bWillBeUpdatedExternally;
    BOOL bReady;
    BOOL bPlayStateBeforeLoad;
    BOOL bUpdateFirstFrame;
    BOOL bNewFrame;
    BOOL bPlaying;
    BOOL bFinished;
    BOOL bAutoPlayOnLoad;
    BOOL bLoop;
    BOOL bSeeking;
    BOOL bSampleVideo;
    BOOL bSampleAudio;
}

@property (nonatomic, assign) id delegate;
@property (nonatomic, retain) OFAVFoundationVideoPlayerView * playerView;
@property (nonatomic, retain) AVPlayer * player;
@property (nonatomic, retain) AVPlayerItem * playerItem;
@property (nonatomic, retain) AVAsset * asset;
@property (nonatomic, retain) AVAssetReader * assetReader;
@property (nonatomic, retain) AVAssetReaderTrackOutput * assetReaderVideoTrackOutput;
@property (nonatomic, retain) AVAssetReaderTrackOutput * assetReaderAudioTrackOutput;

- (BOOL)loadWithFile:(NSString*)file;
- (BOOL)loadWithPath:(NSString*)path;
- (BOOL)loadWithURL:(NSURL*)url;
- (void)unloadVideo;

- (void)setVideoPosition:(CGPoint)position;
- (void)setVideoSize:(CGSize)size;

- (void)update;

- (void)play;
- (void)pause;
- (void)togglePlayPause;

- (void)seekToStart;
- (void)seekToTime:(CMTime)time;
- (void)seekToTime:(CMTime)time withTolerance:(CMTime)tolerance;

- (BOOL)isReady;
- (BOOL)isPlaying;
- (BOOL)isNewFrame;
- (BOOL)isFinished;

- (void)setEnableVideoSampling:(BOOL)value;
- (void)setEnableAudioSampling:(BOOL)value;
- (void)setSynchSampleTime:(CMTime)time;
- (void)setSynchSampleTimeInSec:(double)time;
- (CMTime)getVideoSampleTime;
- (double)getVideoSampleTimeInSec;
- (CMTime)getAudioSampleTime;
- (double)getAudioSampleTimeInSec;
- (CMSampleBufferRef)getVideoSampleBuffer;
- (CMSampleBufferRef)getAudioSampleBuffer;
- (CVImageBufferRef)getCurrentFrame;

- (NSInteger)getWidth;
- (NSInteger)getHeight;
- (CMTime)getCurrentTime;
- (double)getCurrentTimeInSec;
- (CMTime)getDuration;
- (double)getDurationInSec;
- (int)getDurationInFrames;
- (int)getCurrentFrameNum;
- (float)getFrameRate;
- (void)setFrame:(int)frame;
- (void)setPosition:(float)position;
- (float)getPosition;
- (void)setVolume:(float)volume;
- (float)getVolume;
- (void)setLoop:(BOOL)bLoop;
- (BOOL)getLoop;
- (void)setSpeed:(float)speed;
- (float)getSpeed;
- (void)setAutoplay:(BOOL)bAutoplay;
- (BOOL)getAutoplay;
- (void)setWillBeUpdatedExternally:(BOOL)value;

@end
