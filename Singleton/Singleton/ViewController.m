//
//  ViewController.m
//  Singleton
//
//  Created by liupeng on 2018/5/22.
//  Copyright © 2018年 winchannel. All rights reserved.
//

#import "ViewController.h"
#import "Tools.h"
@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    Tools *t1 = [[Tools alloc] init];
    Tools *t2 = [Tools new];
    Tools *t3 = [Tools shareTools];
    Tools *t4 = [t3 copy];
    Tools *t5 = [t3 mutableCopy];
    NSLog(@"%p, %p, %p, %p, %p", t1, t2, t3, t4, t5);
    
#if __has_feature(objc_arc)
    NSLog(@"arc");
#else
    NSLog(@"MRC");
#endif
}


@end
