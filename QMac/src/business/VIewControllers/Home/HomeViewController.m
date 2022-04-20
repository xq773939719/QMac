//
//  HomeViewController.m
//
//  Created by XQ on 2022/4/10.
//

#import "HomeViewController.h"

@interface HomeViewController ()

@end

@implementation HomeViewController

+ (NSString *)scheme {
    return @"q://vc/home";
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
    CGFloat delayTime = 2;
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(delayTime * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        NSUInteger style = NSWindowStyleMaskTitled | NSWindowStyleMaskClosable | NSWindowStyleMaskResizable | NSWindowStyleMaskFullSizeContentView;
        NSWindow *window = [[NSWindow alloc] initWithContentRect:CGRectZero styleMask:style backing:NSBackingStoreBuffered defer:YES];
        window.contentViewController = [BaseViewController new];
        [window setTitle:@""];
        [self.entranceManager setCurrentWindow:window];
    });
    
}

@end
