//
//  BusinessApplicationDelegate.m
//
//  Created by XQ on 2022/1/19.
//

#import "BusinessApplicationDelegate.h"
#import "BusinessEntranceManager.h"

@interface BusinessApplicationDelegate ()

@end

@implementation BusinessApplicationDelegate

- (BaseEntranceManager *)onDelegateInit {
    // 提供整体的业务切换
    BusinessEntranceManager *manager = [BusinessEntranceManager new];
    return manager;
}

@end
