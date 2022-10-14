// Created by LI Chaoran on 2021/11/23.
// Copyright © 2021 Bilibili. All rights reserved.

#ifndef CHRONOS_CRON_PACKAGE_RUNNER_H_
#define CHRONOS_CRON_PACKAGE_RUNNER_H_

#import <CoreVideo/CVPixelBuffer.h>
#import <Foundation/Foundation.h>

@class CRONPackage;

/// Signature for the block used to provide external texturex to Chronos.
/// It is usually used to import images rendered by external renderers into
/// Chronos.
//
/// The external renderer should update its internal state for the time
/// interval by `timeStep`. If the image needs to be redrawn, the corresponding
/// `CVPixelBuffer` object should be returned, otherwise `nil` should be
/// returned.
///
/// NOTE: The block is invoked on the Chronos's raster thread, not on the
/// UI thread. Do not call any API of Chronos in the callback, otherwise it may
/// cause thread competition problems or even deadlock.
///
/// NOTE: The caller (Chronos Engine) is responsible for calling
/// `CVPixelBufferRelease` on the returned data when it is no longer needed.
typedef _Nullable CVPixelBufferRef (^CRONTextureCopyCallback)(NSTimeInterval timeStep);

/// Signature for the block executed after an asynchronous message handling
/// operation completes.
typedef void (^CRONMessageHandleCompletionHandler)(NSData* _Nullable response);

/// Signature for the block executed when a meesage arrived from current
/// running package. When you finish handling the message, you should call
/// `completionHandler` to notify the message sender with a response message.
typedef void (^CRONMessageHandler)(
    NSData* _Nonnull message,
    CRONMessageHandleCompletionHandler _Nonnull completionHandler);

/// Methods and properties common to the `CRONView` and `CRONRenderer` classes.
///
/// You use an instance of one of these classes to run a Chronos package,
/// display a scene and manage Chronos's rendering and animation of the scene’s
/// contents.
///
/// Typically, you use the `CRONView` class to display a scene in a window. You
/// can create and configure a Chronos view programmatically or in Interface
/// Builder. You can also use `CRONRenderer` class to directly render the scene
/// to a `CVPixelBuffer` object for consumption by other components.
///
/// You run a package by calling the `runPackage:` method. When a package is
/// running, it alternates between running its simulation (which animates the
/// content) and rendering the content for display.
@protocol CRONPackageRunner <NSObject>
@required

/// The version of Chronos Engine.
@property(class, readonly, nonnull) NSString* version;

/// Additional resources search path.
///
/// The default value is an empty array.
@property(copy, nonnull, nonatomic) NSArray<NSString*>* searchPaths;

/// The package currently running.
///
/// The default value is `nil`. Call `runPackage:` to assign a value to this
/// property.
@property(readonly, strong, nullable, nonatomic) CRONPackage* currentPackage;

/// Run a package.
///
/// The new package immediately replaces the current package, if one exists.
/// @param package The package to run.
/// @return `YES` if the package runs successfully. Returns `NO` if an error
/// occurred.
- (BOOL)runPackage:(nullable CRONPackage*)package;

/// Run a package with the specified custom script.
///
/// The new package immediately replaces the current package, if one exists.
/// If a non-empty custom script is given, the script will be executed as soon
/// as the JavaScript context (including the context of the worker thread) is
/// initialized.
/// @param package The package to run.
/// @param customScript The custom script to execute after the JavaScript
/// context is initialized..
/// @return `YES` if the package runs successfully. Returns `NO` if an error
/// occurred.
- (BOOL)runPackage:(nullable CRONPackage*)package withCustomScript:(nullable NSString*)customScript;

/// Get the callback block corresponding to the key used to get the external
/// texture.
///
/// @param key The identifier used to identify the external texture.
/// @return The corresponding callback block, or `nil` if no callback block is
/// set before.
- (nullable CRONTextureCopyCallback)externalTextureForKey:(nonnull NSString*)key;

/// Set a callback block for the specified key to provide external texture.
///
/// @param externalTexture A callback block to provide external texture, or
/// `nil` to remove a callback block set for the key before.
/// @param key The identifier used to identify the external texture.
- (void)setExternalTexture:(nullable CRONTextureCopyCallback)externalTexture
                    forKey:(nonnull NSString*)key;

/// A block to handle the message from current running package.
@property(copy, nullable, nonatomic) CRONMessageHandler messageHandler;

/// Send a request to current running package synchronously.
///
/// @param message The request data to be sent.
/// @return The response data from current running package.
- (nullable NSData*)sendMessageSync:(nonnull NSData*)message;

/// Send a request to current running package synchronously.
///
/// @param message The request data to be sent.
/// @param timeout The time interval after which the request automatically
/// fails if it hasn’t already completed.
/// @return The response from current running package, or an empty data if
/// the request timeout.
- (nullable NSData*)sendMessageSync:(nonnull NSData*)message
                            timeout:(NSTimeInterval)timeout;

/// Send a message to current running package asynchronously.
///
/// @param message The message data to be sent.
/// @param completionHandler A complete callback that will be called if the
/// receiver has finished handling the message.
- (void)sendMessageAsync:(nonnull NSData*)message
       completionHandler:(nullable CRONMessageHandleCompletionHandler)completionHandler;

@end

#endif  // CHRONOS_CRON_PACKAGE_RUNNER_H_
