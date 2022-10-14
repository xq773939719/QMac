// Created by LI Chaoran on 2019/05/31.
// Copyright © 2021 Bilibili. All rights reserved.

#ifndef CHRONOS_CRON_VIEW_H_
#define CHRONOS_CRON_VIEW_H_

#import <TargetConditionals.h>

#import <Chronos/CRONPackageRunner.h>

#if defined(TARGET_OS_IPHONE) && TARGET_OS_IPHONE

#import <UIKit/UIKit.h>
#define CRON_OS_VIEW UIView
#define CRON_OS_IMAGE UIImage

#else

#import <AppKit/AppKit.h>
#define CRON_OS_VIEW NSView
#define CRON_OS_IMAGE NSImage

#endif

/// A view subclass that runs a Chronos package.
///
/// You run a package by calling the view’s `runPackage:` method. When a
/// package is running by the view, it alternates between running its
/// simulation (which animates the content) and rendering the content for
/// display.
@interface CRONView : CRON_OS_VIEW <CRONPackageRunner>

/// Draws the contents of the view and returns them as a new image object in
/// UIKit coordinate systems.
///
/// @return An image object.
- (nullable CRON_OS_IMAGE*)snapshot;

/// Draws the contents of the view and returns them as a new image object.
///
/// @param flipped `YES` to have Chronos flip the coordinates of the image
/// vertically to convert between Chronos and UIKit coordinate systems.
/// @return An image object.
- (nullable CRON_OS_IMAGE*)snapshot:(BOOL)flipped;

@end

#endif  // CHRONOS_CRON_VIEW_H_
