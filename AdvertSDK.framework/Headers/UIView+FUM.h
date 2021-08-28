//
//  UIView+FUM.h
//  FUMISDKDemo
//
//  Created by tangbin on 2020/8/6.
//  Copyright © 2020 tangbin. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIView (FUM)


@property (nonatomic) CGFloat fm_left;        ///< Shortcut for frame.origin.x.
@property (nonatomic) CGFloat fm_top;         ///< Shortcut for frame.origin.y
@property (nonatomic) CGFloat fm_right;       ///< Shortcut for frame.origin.x + frame.size.width
@property (nonatomic) CGFloat fm_bottom;      ///< Shortcut for frame.origin.y + frame.size.height
@property (nonatomic) CGFloat fm_width;       ///< Shortcut for frame.size.width.
@property (nonatomic) CGFloat fm_height;      ///< Shortcut for frame.size.height.
@property (nonatomic) CGFloat fm_centerX;     ///< Shortcut for center.x
@property (nonatomic) CGFloat fm_centerY;     ///< Shortcut for center.y
@property (nonatomic) CGPoint fm_origin;      ///< Shortcut for frame.origin.
@property (nonatomic) CGSize  fm_size;        ///< Shortcut for frame.size.


@end

NS_ASSUME_NONNULL_END
