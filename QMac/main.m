//
//  main.m
//  QMac
//
//  Created by XQ on 2022/4/10.
//

#import <Cocoa/Cocoa.h>
#import "BusinessApplicationDelegate.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        NSApplication *application = [NSApplication sharedApplication];
        BusinessApplicationDelegate *delegate = [BusinessApplicationDelegate new];
        application.delegate = delegate;
    }
    return NSApplicationMain(argc, argv);
}
