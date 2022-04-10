//
//  BusinessEntranceManager.m
//
//  Created by XQ on 2022/1/21.
//

#import "BusinessEntranceManager.h"
#import "BusinessRouteManager.h"
#import "BusinessLaunchViewController.h"
#import "HomeViewController.h"

@interface BusinessEntranceManager () <LaunchViewControllerProtocol, NSWindowDelegate>

@end

@implementation BusinessEntranceManager

- (void)launchWithApplication:(NSApplication *)application {
    [super launchWithApplication:application];
    BusinessLaunchViewController *launchViewController = [BusinessLaunchViewController new];
    launchViewController.delegate = self;
    
    CGFloat preferWidth = 1920.f;
    CGFloat preferHeight = 1080.f;
    CGFloat width = CGRectGetWidth([NSScreen mainScreen].frame) * 2/ 3.0;
    CGFloat height = CGRectGetHeight([NSScreen mainScreen].frame) * 2 / 3.0;
    self.window.minSize = CGSizeMake(MIN(preferWidth, width), MIN(preferHeight, height));
    self.window.contentViewController = launchViewController;
    self.window.title = @"MacApp";
    [self.window center];
    NSWindowController *windowController = self.rootWindowController;
    [windowController showWindow:nil];
}

- (NSViewController *)rootViewController {
    HomeViewController *viewController = [HomeViewController new];
    return viewController;
}

- (RouteManager *)routeManager {
    return [BusinessRouteManager new];
}

- (NSArray<Class> *)businessModules {
    return @[];
}

- (void)registerViewControllers {
    [self.routeManager registerViewControllers];
}

#pragma mark - LaunchViewControllerProtocol
- (void)showRootViewController {
    self.window.contentViewController = self.rootViewController;
    self.window.delegate = [DeviceWindow share];
}

@end
