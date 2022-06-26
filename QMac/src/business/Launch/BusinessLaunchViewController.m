//
//  BusinessLaunchViewController.m
//  QMac
//
//  Created by XQ on 2022/4/10.
//

#import "BusinessLaunchViewController.h"

@interface BusinessLaunchViewController ()

@end

@implementation BusinessLaunchViewController

- (void)viewDidLoad {
    [super viewDidLoad];
}

- (void)loadView {
    self.view = [[NSView alloc] initWithFrame:CGRectMake(0, 0, 1600, 900)];
}

- (void)viewDidAppear {
    [super viewDidAppear];
    CGFloat delayTime = 0;
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(delayTime * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        [self.delegate showRootViewController];
    });
}



@end
