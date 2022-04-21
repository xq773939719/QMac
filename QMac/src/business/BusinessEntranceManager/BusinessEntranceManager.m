//
//  BusinessEntranceManager.m
//
//  Created by XQ on 2022/1/21.
//

#import "BusinessEntranceManager.h"
#import "BusinessRouteManager.h"
#import "BusinessLaunchViewController.h"
#import "HomeViewController.h"

@interface BusinessEntranceManager () <LaunchViewControllerProtocol>

@end

@implementation BusinessEntranceManager

+ (Class)rootViewControllerClass {
    return [HomeViewController class];
}

+ (Class)routeManagerClass {
    return [BusinessRouteManager class];
}

- (void)launchWithApplication:(NSApplication *)application {
    [super launchWithApplication:application];
    BusinessLaunchViewController *launchViewController = [BusinessLaunchViewController new];
    launchViewController.delegate = self;
    self.window.contentViewController = launchViewController;
    self.window.title = @"MacApp";
}

- (NSArray<Class> *)businessModules {
    return @[];
}

#pragma mark - LaunchViewControllerProtocol

- (void)showRootViewController {
    self.window.contentViewController = self.rootViewController;
    if ([self.rootViewController isKindOfClass:[BaseViewController class]]) {
        ((BaseViewController *)self.rootViewController).entranceManager = self;
    }
    [self setCurrentWindow:self.window];
    self.window.delegate = [DeviceWindow share];
}

@end
