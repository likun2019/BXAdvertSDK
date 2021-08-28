//
//  FUMI.h
//  FUMISDK
//
//  Created by tangbin on 2020/8/2.
//  Copyright © 2020 tangbin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "FUMIAdDelegate.h"
#import <AppTrackingTransparency/AppTrackingTransparency.h>
#import <AdSupport/AdSupport.h>


NS_ASSUME_NONNULL_BEGIN

@class FUMAlertModel;

typedef NS_ENUM(NSInteger, EN_DRAW_SCREEN_TYPE)
{
    EN_DRAW_FULL_SCREEN_TYPE = 0, ///< 全屏 尺寸是整个屏幕
    EN_DRAW_NONAV_SCREEN_TYPE = 1, ///< 高度不包含navbar+statusBar
    EN_DRAW_NONAVTABBAR_SCREEN_TYPE = 2, ///< 高度不包含navbar+statusBar+TABBAR
};


/// 广告调用的核心类
@interface FUMI : NSObject

@property (nonatomic, weak, nullable) id<FUMIAdDelegate> delegate;

@property (nonatomic, assign) BOOL isDebug;

/// 开屏模式。0 表示旧模式；1 表示新模式。
@property (nonatomic, assign) int splashModel;

+ (instancetype)sharedInstance;


/// 向用户申请权限时，调用
/// @param completionHandler completionHandler description
- (void)requestIDFA:(void(^)(ATTrackingManagerAuthorizationStatus status, NSString *idfa, NSString *desc))completionHandler API_AVAILABLE(ios(14)) API_AVAILABLE(ios(14));


/// 获取用户信息
/// @param userName 用户名
/// @param completion block，YES表示有网络；NO表示没有网络
- (void)getUserInfo:(NSString *)userName completion:(void(^)(BOOL isSuc, NSString *errMsg))completion;


/// 自定义展示开屏
/// @param window window description
/// @param delegate delegate description
- (void)showSpash:(UIWindow *)window withDelegate:(id<FUMIAdDelegate>)delegate;

/// 自定义展示banner
/// @param view 父视图，banner广告视图会加载这个上面(addSubview:)
/// @param controller 当前的视图控制器
/// @param tag tag description
/// @param delegate 代理，用来向外传回调方法的
/// @param frame 位置大小
- (void)showBanner:(UIView *)view controller:(UIViewController *)controller tag:(NSInteger)tag andDelegate:(id<FUMIAdDelegate>)delegate andFrame:(CGRect)frame;

/// 倒计时弹窗
/// @param controller controller description
/// @param time 倒计时时长
/// @param delegate delegate description
/// @param tag tag description
- (void)alertTimeout:(UIViewController *)controller time:(NSInteger)time andDelegate:(id<FUMIAdDelegate> _Nullable)delegate tag:(NSInteger)tag;

/// 无倒计时弹窗
/// @param controller controller description
/// @param delegate delegate description
/// @param tag tag description
- (void)alert:(UIViewController *)controller andDelegate:(id<FUMIAdDelegate>)delegate tag:(NSInteger)tag;

/// 自定义展示信息流广告 -- 信息流广告
/// @param view 信息流广告父视图
/// @param controller 当前视图控制器
/// @param delegate 代理
/// @param tag tag description
/// @param frame 父视图的bounds
- (void)showExpress:(UIView *)view controller:(UIViewController *)controller andDelegate:(id<FUMIAdDelegate>)delegate tag:(NSInteger)tag frame:(CGRect)frame;

/// 展示全屏广告  全屏视频广告
/// @param controller controller description
/// @param delegate delegate description
- (void)showFullVideo:(UIViewController *)controller delegate:(id<FUMIAdDelegate>)delegate;

/// 激励视频自动展示
/// @param controller controller description
/// @param delegate delegate description
/// @param params @{@"userId": @"用户id", @"url":@"", @"json":@""} 传递参数
- (void)showReawVideoAuto:(UIViewController *)controller delegate:(id<FUMIAdDelegate>)delegate params:(NSDictionary *)params;

/// 激励视频自动展示
/// @param controller controller description
/// @param delegate delegate description
/// @param userId 用户id，正常为nil，如没有特殊说明请填写nil
//- (void)showReawVideoAuto:(UIViewController *)controller userId:(nullable NSString *)userId delegate:(id<FUMIAdDelegate>)delegate;

/// 激励视频单词加载/预加载
/// @param delegate delegate description
- (void)loadReawVideo:(id<FUMIAdDelegate>)delegate;

/// 多次预加载后展示激励视频   激励视频单次展示/加载后展示
/// @param controller controller description
/// @param delegate delegate description
/// @param params @{@"userId": @"用户id", @"url":@"", @"json":@""} 传递参数
- (void)showReawVideos:(UIViewController *)controller delegate:(id<FUMIAdDelegate>)delegate params:(NSDictionary *)params;

/// 多次预加载后展示激励视频   激励视频单次展示/加载后展示
/// @param controller controller description
/// @param delegate delegate description
/// @param userId 用户id，正常为nil，如没有特殊说明请填写nil
//- (void)showReawVideos:(UIViewController *)controller userId:(nullable NSString *)userId delegate:(id<FUMIAdDelegate>)delegate;

/// 自定义多次展示
/// @param reaVideos reaVideos description
/// @param controller controller description
/// @param delegate delegate description
- (void)customShow:(NSArray *)reaVideos controller:(UIViewController *)controller delegate:(id<FUMIAdDelegate>)delegate;

/// 信息流插屏展示（加载和展示）
/// @param controller controller description
/// @param delegate delegate description
/// @param tag tag description
- (void)showInterstitialAuto:(UIViewController *)controller andDelegate:(id<FUMIAdDelegate>)delegate tag:(NSInteger)tag;

/// 信息流插屏广告加载
/// @param delegate delegate description
- (void)loadInterstitial:(id<FUMIAdDelegate>)delegate;

/// 信息流插屏广告展示（必须先调用loadInterstitial加载，然后再展示）
/// @param controller controller description
/// @param tag tag description
- (void)showInterstitial:(UIViewController *)controller tag:(NSInteger)tag;


/// 加载Draw信息流广告
/// @param type 高度类型
/// @param hiddenStatusBar 是否隐藏状态栏
/// @param isPresentVC 是否present
/// @param delegate delegate description
- (void)showDrawVideoType:(EN_DRAW_SCREEN_TYPE)type hiddenStatusBar:(BOOL)hiddenStatusBar isPresentVC:(BOOL)isPresentVC andDelegate:(id<FUMIAdDelegate>)delegate;


/// 客户不用理会
/// @param model model description
- (void)alertVC:(FUMAlertModel *)model;

@end

NS_ASSUME_NONNULL_END





























