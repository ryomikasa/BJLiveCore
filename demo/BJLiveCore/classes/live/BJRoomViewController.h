//
//  BJRoomViewController.h
//  BJLiveCore
//
//  Created by MingLQ on 2016-12-18.
//  Copyright © 2016 BaijiaYun. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <BJLiveCore/BJLiveCore.h>
#import <ReactiveObjC/ReactiveObjC.h>
#import "BJConsoleViewController.h"
#import "BJPlayingView.h"

@interface BJRoomViewController : UIViewController <
UINavigationControllerDelegate,
UIImagePickerControllerDelegate,
UITextFieldDelegate> {
    __weak UIScrollView *_imageScrollView;
}

- (void)enterRoomWithSecret:(NSString *)roomSecret
                   userName:(NSString *)userName;

@end

// protected
@interface BJRoomViewController ()

@property (nonatomic) BJLRoom *room;

@property (nonatomic) UIButton *recordingView;
@property (nonatomic) UIView *slideshowAndWhiteboardView;
@property (nonatomic) NSMutableArray<BJPlayingView *> *playingViews;

@property (nonatomic) BJConsoleViewController *console;

@end
