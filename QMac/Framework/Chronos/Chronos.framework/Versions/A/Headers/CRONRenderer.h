// Created by LI Chaoran on 2021/11/23.
// Copyright © 2021 Bilibili. All rights reserved.

#ifndef CHRONOS_CRON_RENDERER_H_
#define CHRONOS_CRON_RENDERER_H_

#import <CoreGraphics/CGGeometry.h>
#import <CoreVideo/CVPixelBuffer.h>
#import <Foundation/Foundation.h>

#import <Chronos/CRONPackageRunner.h>

/// A renderer for running a Chronos package, and rendering a Chronos scene to
/// a `CVPixelBuffer`.
@interface CRONRenderer : NSObject <CRONPackageRunner>

/// The size of output image (in point).
///
/// Note that the final size in pixel of output buffer will also be affected by
/// the `contentScale`.
@property(nonatomic, assign) CGSize outputImageSize;

/// The scale factor applied to the output pixel buffer.
@property(nonatomic, assign) CGFloat contentScale;

/// Initializes and returns a renderer object with specified size of output
/// image.
///
/// @param outputImageSize The size of output image in point.
/// @param contentScale The scale factor applied to the output pixel buffer.
/// @return An initialized `CRONRenderer` object.
- (nonnull instancetype)initWithOutputImageSize:(CGSize)outputImageSize
                                   contentScale:(CGFloat)contentScale;

/// Updates and renders the receiver's current scene for the specified time
/// interval synchronously.
///
/// @param timeStep The timestep for the update.
- (void)updateSyncForTimeStep:(NSTimeInterval)timeStep;

/// Updates and renders the receiver's current scene for the specified time
/// interval asynchronously.
///
/// @param timeStep The timestep for the update.
/// @param completionHandler A block called after the scene is updated and
/// rendered.
- (void)updateAsyncForTimeStep:(NSTimeInterval)timeStep
             completionHandler:(nullable void (^)(void))completionHandler;

/// Retrieves the last rendered image.
///
/// After calling this method to retrieve the image, calling this method again
/// will return `nil` until a new image is rendered.
/// @return A pixel buffer containing the image data to display, or `nil` if
/// there is no new image available. The caller is responsible for calling
/// `CVBufferRelease` on the returned data when it is no longer needed.
- (nullable CVPixelBufferRef)copyPixelBuffer;

@end

#endif  // CHRONOS_CRON_RENDERER_H_
