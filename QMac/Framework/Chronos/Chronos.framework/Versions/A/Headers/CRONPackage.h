// Created by LI Chaoran on 2020/02/03.
// Copyright © 2021 Bilibili. All rights reserved.

#ifndef CHRONOS_CRON_PACKAGE_H_
#define CHRONOS_CRON_PACKAGE_H_

#import <Foundation/Foundation.h>

/// Signature for the block executed after a Chronos Package loading operation
/// completes.
typedef void (^CRONPackagePreloadCallback)(BOOL success);

/// A Chronos package.
@interface CRONPackage : NSObject

/// Initializes and returns the Chronos package object with the contents of the
/// specified file.
///
/// This method only loads the package's meta info into memory. The relevant
/// script and resource files will not be unzipped until the package is about
/// to be run. You can trigger the unzip process by running
/// `preloadWithCompletionHandler:` manually.
/// @param path The path to the file. This path should include the filename
/// extension.
/// @return An initialized `CRONPackage` object, or `nil` if the method could
/// not find the file or initialize the package from its contents.
- (nullable instancetype)initWithContentsOfFile:(nullable NSString*)path;

/// A dictionary containing package's meta info.
@property(readonly, copy, nullable, nonatomic) NSDictionary* info;

/// A path to package's sandbox directory.
@property(readonly, copy, nonnull, nonatomic) NSString* sandboxDirectory;

/// Unzip package's script and resource files asynchronously, and calling a
/// completion handler after the task completes.
///
/// Chronos creates a background task to unzip the package from the associated
/// files. After the package's script and resource files are unzipped, your
/// completion handler is called. Typically, you use this method when you want
/// to guarantee that a package is unzipped before running it.
/// @param completionHandler A block called after the texture data is loaded.
- (void)preloadWithCompletionHandler:(nullable CRONPackagePreloadCallback)completionHandler;

@end

#endif  // CHRONOS_CRON_PACKAGE_H_
