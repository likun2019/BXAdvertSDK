//
//  FUMIAdDelegate.h
//  FUMISDK
//
//  Created by tangbin on 2020/8/1.
//  Copyright © 2020 tangbin. All rights reserved.
//

#import <Foundation/Foundation.h>
//#import "ReawVideo.h"

NS_ASSUME_NONNULL_BEGIN

/// 广告的各种回调代理方法
@protocol FUMIAdDelegate <NSObject>

@optional

/// banner广告加载失败
/// @param error error description
/// @param tag tag description
- (void)bannerFail:(NSError *)error tag:(NSInteger)tag;

/// banner广告加载成功
- (void)bannerSuccess;

/// 关闭banner广告
- (void)bannerDismiss;

/// 点击banner
/// @param type type 1 广点通；2 穿山甲
- (void)bannerDidClick:(int)type;



#pragma mark - 开屏

/// 开屏广告加载失败
/// @param error error description
- (void)splashFail:(NSError * _Nullable)error;

/// 开屏广告加载成功
- (void)splashSuccess;

/// 将要关闭
- (void)splashWillDismiss;

/// 开屏广告关闭
- (void)splashDismiss;

/// 开屏广告点击
/// @param type 1 广点通；2 穿山甲
- (void)splashDidClick:(int)type;


#pragma mark - 信息流广告

/// 信息流广告加载失败
/// @param error error description
/// @param tag tag description
- (void)expressFail:(NSError *)error tag:(NSInteger)tag;

/// 信息流加载成功
- (void)expressSuccess;

/// 信息流广告关闭
- (void)expressDismiss;

/// 信息流广告点击
- (void)expressDidClick;


#pragma mark - 全屏视频

/// 全屏视频加载失败
/// @param error error description
- (void)fullVideoFail:(NSError *)error;

/// 全屏视频加载成功
- (void)fullVideoSuccess;

/// 全屏视频关闭
- (void)fullVideoDismiss;

/// 全屏视频点击
/// @param type type 1 广点通；2 穿山甲
- (void)fullVideoClick:(int)type;



#pragma mark - 弹窗广告

/// 弹窗关闭
- (void)alertDismiss;


#pragma mark 激励视频

/// 激励视频请求成功
- (void)reawVideoLoadSuccess;

/// 激励视频加载失败
/// @param error error description
- (void)reawVideoLoadFail:(NSError *)error;

/// 激励视频下载成功
- (void)reawVideoDownSuccess;

/// 达到奖励条件
- (void)reawVideoFinish;

/// 激励视频关闭
- (void)reawVideoDismiss;

/// 激励视频将要展示
- (void)reawVideoWillVisible;

/// 激励视频播放完成
- (void)reawVideoPlayed;

/// 激励视频以及展示
- (void)reawVideoDidVisible;

/// 激励视频点击
/// @param type type 1 广点通；2 穿山甲
- (void)reawVideoDidClick:(int)type;

/// 获取激励视频对象
/// 可以在需要的地方条用此方法展现  sdkclass.customShow(reaVideos: reawVideos, controller: self)
/// @param reawVideos reawVideos description
- (void)reawVideo:(NSArray *)reawVideos;


#pragma mark - 信息流插屏广告

/// 原生插屏加载成功
- (void)interstitialSuccess;

/// 信息流插屏广告加载视频
/// @param error error description
/// @param tag tag
- (void)interstitialLoadFail:(NSError *)error tag:(NSInteger)tag;

/// 信息流插屏广告点击
- (void)interstitialDidClick;

/// 信息流插屏广告关闭
- (void)interstitialClosed;


#pragma mark - Draw信息流广告
/// 视图成功加载
- (void)drawAdSuccessToLoad;

///  广告加载失败或者渲染失败
/// @param error error description
- (void)drawAdFailToLoad:(NSError *)error;

/// 广告渲染成功
- (void)drawAdViewRenaderSuccess:(UIViewController *)drawAdVC;

/// 点击广告的时候
- (void)drawAdViewDidClick;


@end

NS_ASSUME_NONNULL_END




























