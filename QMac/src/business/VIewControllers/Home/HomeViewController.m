//
//  HomeViewController.m
//
//  Created by XQ on 2022/4/10.
//

#import "HomeViewController.h"

@interface HomeViewController ()

@property (nonatomic, strong) NSTextField *textfield;

@end

@implementation HomeViewController

+ (NSString *)scheme {
    return @"q://vc/home";
}

- (void)viewDidLoad {
    [super viewDidLoad];
    [self addSubview:self.textfield];
    [self.textfield mas_makeConstraints:^(MASConstraintMaker *make) {
        make.width.mas_equalTo(self.rootContainer);
        make.height.mas_equalTo(@(300));
    }];
}

- (NSTextField *)textfield {
    if (_textfield) {
        return _textfield;
    }
    _textfield = [NSTextField new];
    _textfield.font = [NSFont systemFontOfSize:40];
    return _textfield;
}

@end
