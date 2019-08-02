Change Log
==========

- 标记为 **粗体** 的改动需要特别留意；
- 被标记 `DEPRECATED` 的代码 **将在大版本升级时移除**；
- 带有 `alpha`、`beta`、`rc` 等字样的版本，代码和功能都不稳定，**请勿随意升级**；

## 1.3.6

- native PPT和H5 PPT动态切换

## 1.3.5

- 支持设置专属域名
- 支持定制信令
- 支持切换主讲
- 支持画笔授权
- PPT支持设置裁剪参数

## 1.3.3

- 支持答题器，参考 `BJLRoomVM`；
- 支持切换清晰度，参考 `BJLPlayingVM`；
- 支持教室内分组；
- 支持大小班切换；
- Native PPT 优化重试逻辑，支持切换 CDN；
- 设置上下行链路类型失败时返回错误，参考 `BJLMediaVM` 的 `updateUpLinkType:` 和 `updateDownLinkType:` 方法；

## 1.3.2

- 解决播放本地回放时 PPT 显示相关问题；

## 1.3.1

- 增加上麦路数限制，`BJLRecordingVM`；
- 音视频推流、拉流优化；
- 支持私聊，参考 `BJLChatVM` 的 `sendMessage:toUser:` 等方法；
- `BJLOnlineUser` 标记为 `DEPRECATED`，使用 `BJLUser`代替，音视频相关的用户使用 `BJLMediaUser`;
- 解决 Bug。

## 1.3.0

- 去除对非百家云开源库的依赖；
- 其他用户视频可用时支持自动播放，参考 `BJLPlayingVM` 的 `videoPlayingBlock` 属性；
- 改进获取 PPT 图片 URL 的方式，参考 `BJLSlideshowVM`、`BJLSlidePage`；

## 1.2.0

- 支持音视频前向纠错；
- 支持跑马灯，参考 `BJLRoom` 的 `lampContent` 属性；
- 大小班切换(内部使用)；
- 不再依赖 `YYModel`；
- PPT 动画视图不再内置翻页指示箭头，如果需要可以自行设置：
```objc
self.room.slideshowViewController.prevPageIndicatorImage = ...;
self.room.slideshowViewController.nextPageIndicatorImage = ...;
```

## 1.1.0

- 支持竖屏/横屏状态下采集横屏/竖屏视频，参考 `BJLRecordingVM` 的 `videoOrientation` 属性；
- 支持后台配置举手自动超时时间；
- 非动画 PPT 组件支持缩放；
- 解决 BUG；

## 1.0.0 

- **新功能**：支持禁止举手、邀请/强制发言，支持直播添加水印，增加老师开始共享屏幕/播放本地视频的通知；

- **进教室流程优化**：减少加载步骤，是否使用 3/4G 网络交给上层自行判断，支持同时多个助教进教室；

- **音视频优化**：取消播放视频个数的限制，更好地支持海外直播线路，App 退入后台时停止采集音频、避免泄露隐私，支持静音，解决花屏等音视频质量问题，解决直播同时播放本地音频时崩溃的问题；

- **画笔优化**：画笔数据压缩使用新算法、涂鸦轨迹显示更平滑、支持圆和椭圆、支持填充颜色等，解决 iOS 8 使用画笔时偶现的崩溃问题；

- **PPT 优化**：支持 PPT 动画，支持快速跳转到某一页，图片尺寸优化、图片加载增加重试逻辑、解决有时图片无法显示的问题，支持 WebP 格式加载 PPT 图片；

支持 WebP 格式需要在 `Podfile` 中加入 `BJLiveBase` 的 `SDWebImage` 或者 `YYWebImage` 模块
```
// SDWebImage
pod 'BJLiveBase/WebImage/SDWebImage'
// YYWebImage
pod 'BJLiveBase/WebImage/YYWebImage'
```

- 整理通用的工具类代码并已 **开源** [BJLiveBase](https://github.com/baijia/BJLiveBase/)，其中包括 `KVO` 和方法监听、`Foundation` 和 `UIKit` 常用类扩展等，欢迎贡献代码、帮忙改进；

- 去掉对 `JRSwizzle`、`libextobjc`、`SDWebImage` 等开源库的强制 **依赖**，改为不依赖或可选依赖；

- 标记为 `DEPRECATED` 的 `class`、`protocol`、`method`、`property`、`const`、`enum` 等 **全部删除**；

删除的内容及替代实现：
```objc
// BJLConstants.h
BJLVideoBeautifyLevel0 DEPRECATED_ATTRIBUTE = BJLVideoBeautifyLevel_0,
BJLVideoBeautifyLevel1 DEPRECATED_ATTRIBUTE = BJLVideoBeautifyLevel_1,
BJLVideoBeautifyLevel2 DEPRECATED_ATTRIBUTE = BJLVideoBeautifyLevel_2,
BJLVideoBeautifyLevel3 DEPRECATED_ATTRIBUTE = BJLVideoBeautifyLevel_3,
BJLVideoBeautifyLevel4 DEPRECATED_ATTRIBUTE = BJLVideoBeautifyLevel_4,
BJLVideoBeautifyLevel5 DEPRECATED_ATTRIBUTE = BJLVideoBeautifyLevel_5,
BJLVideoBeautifyLevel_close DEPRECATED_ATTRIBUTE = BJLVideoBeautifyLevel_off,
BJLVideoBeautifyLevel_min DEPRECATED_ATTRIBUTE = BJLVideoBeautifyLevel_1,
BJLVideoBeautifyLevel_max DEPRECATED_ATTRIBUTE = BJLVideoBeautifyLevel_5

// BJLLoadingVM.h
- (BJLObservable)loadingDidUpdateProgress:(CGFloat)progress DEPRECATED_MSG_ATTRIBUTE("use `loadingUpdateProgress:` instead");
- (BJLObservable)loadingDidSuccess DEPRECATED_MSG_ATTRIBUTE("use `loadingSuccess` instead");
- (BJLObservable)loadingDidFailureWithError:(nullable BJLError *)error DEPRECATED_MSG_ATTRIBUTE("use `loadingFailureWithError:` instead");

// BJLPlayingVM.h
- (BJLObservable)playingUserDidUpdate:(BJLTuple<void (^)(BJLUser *old, BJLUser *now)> *)tuple DEPRECATED_MSG_ATTRIBUTE("use `playingUserDidUpdate:old:`");
- (nullable BJLError *)remoteUpdatePlayingUserWithID:(NSString *)userID audioOn:(BOOL)audioOn videoOn:(BOOL)videoOn DEPRECATED_MSG_ATTRIBUTE("use `BJLRecordingVM` - `remoteChangeRecordingWithUser:audioOn:videoOn:` insetad");

// BJLRecordingVM.h
- (BJLObservable)recordingDidRemoteChanged:(BJLTuple<void (^)(BOOL recordingAudio, BOOL recordingVideo, BOOL recordingAudioChanged, BOOL recordingVideoChanged)> *)tuple DEPRECATED_MSG_ATTRIBUTE("use `recordingDidRemoteChangedRecordingAudio:recordingVideo:recordingAudioChanged:recordingVideoChanged:`");

// BJLRoomVM.h
@property (nonatomic, readonly, copy, nullable) NSObject<BJLRoomInfo> *roomInfo DEPRECATED_MSG_ATTRIBUTE("use `BJLRoom.roomInfo` instead");
@property (nonatomic, readonly, copy, nullable) BJLUser *loginUser DEPRECATED_MSG_ATTRIBUTE("use `BJLRoom.loginUser` instead");
@property (nonatomic, readonly, copy, nullable) NSString *noticeText DEPRECATED_MSG_ATTRIBUTE("use `notice` instead");
- (void)loadNoticeText DEPRECATED_MSG_ATTRIBUTE("use `loadNotice` instead");
- (nullable BJLError *)sendNoticeText:(nullable NSString *)noticeText DEPRECATED_MSG_ATTRIBUTE("use `sendNoticeWithText:linkURL:` instead");
- (BJLObservable)rollcallDidCancel DEPRECATED_MSG_ATTRIBUTE("use `rollcallDidFinish` instead");
- (BJLObservable)didReceiveCustomizedSignal:(NSString *)key value:(nullable id)value DEPRECATED_MSG_ATTRIBUTE("use `didReceiveCustomizedSignal:value:isCache:` instead");

// BJLSlideshowVM.h
- (BJLObservable)didTurnToSlidePage:(BJLSlidePage *)slidePage DEPRECATED_MSG_ATTRIBUTE("KVO `currentSlidePage` instead");

// BJLSpeakingRequestVM.h
extern const NSTimeInterval BJLSpeakingRequestTimeoutInterval DEPRECATED_MSG_ATTRIBUTE("use property `speakingRequestTimeoutInterval`");
extern const NSTimeInterval BJLSpeakingRequestCountdownStep DEPRECATED_MSG_ATTRIBUTE("use property `speakingRequestCountdownStep`");
@protocol BJLSpeakingReply; // @see `speakingRequestDidReplyEnabled:isUserCancelled:user:`
- (void)stopSpeaking DEPRECATED_MSG_ATTRIBUTE("use `stopSpeakingRequest` instead");
- (BJLObservable)speakingRequestDidReply:(NSObject<BJLSpeakingReply> *)reply DEPRECATED_MSG_ATTRIBUTE("use `speakingRequestDidReplyEnabled:isUserCancelled:user:`");
- (BJLObservable)speakingDidRemoteEnabled:(BOOL)enabled DEPRECATED_MSG_ATTRIBUTE("use `speakingDidRemoteControl:`");
- (BJLObservable)speakingBeRemoteEnabled:(BOOL)enabled DEPRECATED_MSG_ATTRIBUTE("use `speakingDidRemoteEnabled:`");

// BJLSlideshowUI.h
@property (nonatomic) BOOL whiteboardEnabled DEPRECATED_MSG_ATTRIBUTE("use `drawingEnabled` instead");
- (void)clearWhiteboard DEPRECATED_MSG_ATTRIBUTE("use `clearDrawing` instead");
```

## 0.5.0-beta

- 支持播放 1+5 路他人视频（1 路老师/主讲、5 路其他用户），参考 `BJLPlayingVM`；
- 支持切换主讲人（暂不支持助教被切换成主讲），参考 `BJLOnlineUsersVM`；
- 增加小班课类型，参考 `BJLFeatureConfig`；
- 简化加载流程，参考 `BJLLoadingVM`；
- 客户定制信令可区分是否是缓存，参考 `BJLRoomVM`；
- 白板增加是否空白参数，支持程序设置本地页数，参考 `BJLSlideshowUI`；
- 支持禁止举手，参考 `BJLSpeakingRequestVM`；
- 合并 `BJLUser` 和 `BJLOnlineUser`，`BJLOnlineUser` 将废弃；
- 支持新的画笔压缩格式；

## 0.4.3

- 解决视频画面黑暗的问题；
- 支持静音；

## 0.4.2

- 上课状态下老师不再教室学生也可以举手、发言；

## 0.4.1

- 统计模块升级；

## 0.4.0

- **底层音视频 SDK 使用动态库，iOS 版本要求最低 8.0**；
- 支持分辨率、码率、音频编码格式等参数可服务端配置；
- 支持 MS 服务器调度、支持动态 CDN；
- 优化统计上报；
- 支持新版小测；
- 支持踢人功能；

## 0.3.0

- 支持助教登录；
- 支持加载客服信息；
- **`BJLUser` 由 `protocol` 改为 `class`；**；
- **`BJLMessage` 由 `protocol` 改为 `class`**，聊天支持自定义表情，支持老师、助教和非大班课的学生发图片；
- `BJLSpeakingRequestVM` 的 `speakingRequestUsers` 改为倒序，后举手的学生排在数组的前面，与发言用户逻辑保持一致；
- PPT 翻页相关 API 改进，参考 `BJLSlideshowVM`、`BJLSlideshowUI`；
- 优化 PPT 图片加载逻辑；
- 解决 BUG；

### 0.2.6-internal

- 美颜级别枚举优化，参考 `BJLConstants` 的 `BJLVideoBeautifyLevel`；
- 解决升级 XCode 8.3 后发现的警告；
- 解决 Swift 集成时的编译错误问题；
- 解决 BUG；

### 0.2.5-internal

- 增加采集和播放视频的比例，参考 `BJLRecordingVM` 的 `inputVideoAspectRatio` 和 `BJLPlayingVM` 的 `outputVideoAspectRatio`；
- `BJLRecordingVM` 的 `inputVolumeLevel` 属性的类型由 `NSInteger` 改为 `CGFloat`，取值从 `[0-9]` 改为 `[0.0-1.0]`；
- `BJLDocument` 和 `BJLDocumentPageInfo` 由 protocol 改为 class，影响到 `BJLSlideVM` 和 `BJLSlideshowVM` 中的相关属性和方法；
- `BJLSlideVM` 的 `uploadImageFile:progress:finish:` 方法改为 `uploadImageFile:progress:finish:`，只单个上传图片、不自动添加课件，添加课件需自行调用 `addDocument:` 方法；
- `BJLSlideshowUI` 的 `whiteboardEnabled` 属性改名为 `drawingEnabled`、`clearWhiteboard` 改名为 `clearDrawing`，原属性、方法标记为 `DEPRECATED`；
- PPT 支持显示激光笔功能；
- 解决 BUG；

## 0.2.4

- 解决上课状态错误问题；

## 0.2.3

- 公告支持设置链接，参考 `BJLRoomVM`；
- 增加进教室房间已满的错误码 `BJLErrorCode_enterRoom_roomIsFull`；
- 升级 AVSDK、解决声音从听筒发出的问题；
- 解决收不到拒绝举手的回调的问题；
- 解决 PPT 图片可能加载多个清晰度、以及清晰度较低的问题；

## 0.2.2

- 增加未上课时不能开启录课的错误码 `BJLErrorCode_serverRecording_not_liveStarted`；
- 增加测验功能，参考 `BJLRoomVM`；
- 解决 `BJLTuple` 的 BUG；

## 0.2.1

- 解决进教室时加载的消息是倒序的问题；
- 解决非 iOS10 系统上的崩溃问题；

## 0.2.0

- **`BJLRoom` 的 `vmsAvailable` 属性原来在 `enterRoomSuccess` 时才变成 YES，为了避免错过一些事件现在改为在 `enterRoomSuccess` 之前**；  
需要注意现在 `vmsAvailable` 变为 YES 时 vm 并没有与 server 建立连接，vm 的状态、数据没有与服务端同步，调用 vm 方法时发起的网络请求会被丢弃、甚至产生不可预期的错误，断开重连时类似；  
如果不想影响到原来逻辑、仍然想通过 KVO 监听进教室可简单地将使用 `vmsAvailable` 的地方改为 `inRoom`；

- **`BJLRoom` 增加 `inRoom` 属性，在 `enterRoomSuccess` 是变为 YES、`roomDidExitWithError:` 是变为 NO，断开重连过程中仍然为 YES**；  
`inRoom` 变为 YES 时 vm 的状态、数据已经和服务端同步，并可调用 vm 方法；

- `BJLRoom` 增加 `roomInfo`、`loginUser` 属性，原 `BJLRoomVM` 的这两个属性标记为 `DEPRECATED`，将移除；

- 完善注释，特别是 `BJLRoom`，请仔细阅读；

- `BJLRoom` 增加 `slideshowVM` 用于监听课件相关信息；

- `BJLRoomVM` 支持点名答到功能；

- `BJLRoomVM` 支持客户定制信令；

- `BJLChatVM` 收发消息支持 `channel`；

- 对一些可能增量更新的数组属性增加了覆盖更新回调，只有覆盖更新才调用，增量更新不调用；
```objc
- [BJLChatVM receivedMessagesDidOverwrite:] // receivedMessages
- [BJLGiftVM receivedGiftsDidOverwrite:] // receivedGifts
- [BJLOnlineUsersVM onlineUsersDidOverwrite:] // onlineUsers
- [BJLPlayingVM playingUsersDidOverwrite:] // playingUsers
- [BJLSlideshowVM allDocumentsDidOverwrite:] // allDocuments
````

## 0.1.4

- BUG 修复；

## 0.1.3

- 改进 vm 初始化的监听方式，增加 vmsAvailable 属性、并且可 KVO 监听；
- 减少对开源库的依赖 之 Masonry；
- 内部逻辑优化；
- BUG 修复；

## 0.1.1

- 支持对单个用户禁言；
- 用户对象增加登录客户端类型；

## 0.1.0

- 此版本对 Block 的使用进行了全面升级，解决了使用中暴露出来的严重问题、改善了 API 调用，因此集成 SDK 的代码需要做一些升级；
- 原有使用 Block 进行 `KVO` 和 `监听方法调用` 的相关方法被标记 `DEPRECATED`，个别方法因为不合理被直接废弃、有更好的替代实现；
- 新方法参考的定义及使用，可参考 `NSObject+BJLObserving.h`、[Block 的使用](./blocks.md) 以及 [Demo](https://github.com/baijia/BJLiveCore-iOS) 中的源码；

##### 1. 重新实现 Block KVO

- KVO 调用方式：

属性名支持代码自动完成，而不再是 selector 或者 keypath，从而避免出错；
```objc
weakdef(self);
[self bjl_kvo:BJLMakeProperty(self.room.roomVM, // 对象
                              liveStarted) // 属性名
       filter:^BOOL(NSNumber *old, NSNumber *now) { // 过滤
           return old.boolValue != now.boolValue;  // 返回 NO 丢弃
       }
     observer:^BOOL(NSNumber *old, NSNumber *now) { // 处理
       strongdef(self);
       [self.console printFormat:@"liveStarted: %@", NSStringFromBOOL(now.boolValue)];
       return YES; // 返回 NO 停止监听
   }];
```
对比以前：
```objc
weakdef(self);
[self bjl_KVObserve:self.room.roomVM // 对象
             getter:@selector(liveStarted) // 属性对应的 selector，属性名和 getter 方法名不一样可使用带有 keypath: 的方法
             filter:^BOOL(NSNumber *old, NSNumber *now) { // 过滤
                 return old.boolValue != now.boolValue;
             }
         usingBlock:^BOOL(NSNumber *old, NSNumber *now) { // 处理
             strongdef(self);
             [self.console printFormat:@"liveStarted: %@", NSStringFromBOOL(now.boolValue)];
             return YES;
         }];
```

- 支持两种方式取消某次 KVO；
```objc
weakdef(self);
id<BJLObservation> observation =
    [self bjl_kvo:BJLMakeProperty(self.room.roomVM, liveStarted)
         observer:^BOOL(NSNumber *old, NSNumber *now) {
           strongdef(self);
           [self.console printFormat:@"liveStarted: %@", NSStringFromBOOL(now.boolValue)];
           return YES; // 1. 返回 NO 取消 KVO
       }];
[observation stopObserving]; // 2. 取消 KVO
```

- **不在支持** 通过 `object+keyPath` 取消 KVO 的方法，因为同一 `对象+属性` 可能被多次 KVO，该方法无法区分，很容易衍生 BUG：
```objc
- (void)bjl_stopKVObserving:(nullable NSObject *)object forKeyPath:(nullable NSString *)keyPath NS_UNAVAILABLE;
```

##### 2. 重新实现 Block 监听方法调用

- 监听方法调用，支持 filter - 可选：

`BJLMakeMethod(TARGET, METHOD)` 会断言 TARGET 是否实现了 METHOD 方法，以便发现错误；
```objc
weakdef(self);
[self bjl_observe:BJLMakeMethod(self.room, // 对象
                                roomWillExitWithError:) // 方法
           filter:^BOOL(BJLError *error) { // 过滤
               return !!error; // 返回 NO 丢弃
           }];
         observer:^BOOL(BJLError *error) { // 处理
             strongdef(self);
             [self.console printFormat:@"roomWillExitWithError: %@", error];
             return YES; // 返回 NO 停止监听
         }];
```
对比以前：
```objc
weakdef(self);
[self bjl_observe:self.room // 对象
            event:@selector(roomWillExitWithError:) // 事件 selector
       usingBlock:^(BJLError *error) { // 处理
           strongdef(self);
           if (error) {
               [self.console printFormat:@"roomWillExitWithError: %@", error];
           }
       }];
```

- 支持 **简单类型参数**：
> 使用 `BOOL`、`char`、`short`、`float` 等类型会产生警告，将 block 强转为 `BJLMethodFilter` 或 `BJLMethodObserver` 既可解决；
```objc
weakdef(self);
[self bjl_observe:BJLMakeMethod(self.room.speakingRequestVM, speakingBeRemoteEnabled:)
         observer:(BJLMethodObserver)^BOOL(BOOL enabled) {
             [self.console printFormat:@"发言状态被%@", enabled ? @"开启" : @"关闭"];
             return YES;
         }];
```
以前需要使用 `NSNumber` 包装：
```objc
weakdef(self);
[self bjl_KVObserve:self.room.speakingRequestVM
             getter:@selector(speakingDidRemoteEnabled:)
         usingBlock:^BOOL(NSNumber *enabled) {
             strongdef(self);
             [self.console printFormat:@"发言状态被%@", enabled.boolValue ? @"开启" : @"关闭"];
             return YES;
         }];
```

- 支持 **多个参数**：
```objc
weakdef(self);
[self bjl_observe:BJLMakeMethod(self.room.playingVM, playingUserDidUpdate:old:)
         observer:^BOOL(NSObject<BJLOnlineUser> *old,
                        NSObject<BJLOnlineUser> *now) {
             strongdef(self);
             [self.console printFormat:@"playingUserDidUpdate:old: %@ >> %@", old, now];
         }];
```
以前需要使用稍显晦涩的模拟元组：
```objc
weakdef(self);
[self bjl_observe:self.room.playingVM
            event:@selector(playingUserDidUpdate:)
       usingBlock:^BOOL(BJLTuple *tuple) {
           BJLTupleUnpack(tuple) = ^(NSObject<BJLOnlineUser> *old,
                                     NSObject<BJLOnlineUser> *now) {
               strongdef(self);
               [self.console printFormat:@"playingUserDidUpdate: %@ >> %@", old, now];
           };
       }];
```

- 支持两种方式取消某次监听；
```objc
weakdef(self);
id<BJLObservation> observation =
    [self bjl_observe:BJLMakeMethod(self.room, roomWillExitWithError:)
             observer:^BOOL(BJLError *error) {
                 strongdef(self);
                 [self.console printFormat:@"roomWillExitWithError: %@", error];
                 return YES; // 1. 返回 NO 取消监听
             }];
[observation stopObserving]; // 2. 取消监听
```

- **不再支持** 通过 `object+selector` 取消监听的方法，因为同一 `对象+方法` 可能被多次监听，该方法无法区分，很容易衍生 BUG：
```objc
- (void)bjl_stopObserving:(nullable id)object event:(nullable SEL)event NS_UNAVAILABLE;
```

- 个别 ViewModel 的方法升级：
```objc
// BJLHelpVM.h
- (BJLObservable)requestForHelpFinished:(BOOL)success;
// BJLPlayingVM.h
- (BJLObservable)playingUserDidUpdate:(NSObject<BJLOnlineUser> *)now
                                  old:(NSObject<BJLOnlineUser> *)old;
// BJLRecordingVM.h
- (BJLObservable)recordingDidRemoteChangedRecordingAudio:(BOOL)recordingAudio
                                          recordingVideo:(BOOL)recordingVideo
                                   recordingAudioChanged:(BOOL)recordingAudioChanged
                                   recordingVideoChanged:(BOOL)recordingVideoChanged;
// BJLSpeakingRequestVM.h
- (BJLObservable)speakingBeRemoteEnabled:(BOOL)enabled;
```
对应的原方法标记 `DEPRECATED`：
```objc
// BJLHelpVM.h
- (BJLObservable)requestForHelpDidFinished:(NSNumber *)success DEPRECATED_MSG_ATTRIBUTE("use `requestForHelpFinished:`");
// BJLPlayingVM.h
 - (BJLObservable)playingUserDidUpdate:(BJLTuple<void (^)(NSObject<BJLOnlineUser> *old,
                                                         NSObject<BJLOnlineUser> *now)> *)tuple DEPRECATED_MSG_ATTRIBUTE("use `playingUserDidUpdate:old:`");
// BJLRecordingVM.h
- (BJLObservable)recordingDidRemoteChanged:(BJLTuple<void (^)(BOOL recordingAudio,
                                                              BOOL recordingVideo,
                                                              BOOL recordingAudioChanged,
                                                              BOOL recordingVideoChanged)> *)tuple;
                                                              BOOL recordingVideoChanged)> *)tuple DEPRECATED_MSG_ATTRIBUTE("use `recordingDidRemoteChangedRecordingAudio:recordingVideo:recordingAudioChanged:recordingVideoChanged:`");
// BJLSpeakingRequestVM.h
- (BJLObservable)speakingDidRemoteEnabled:(NSNumber *)enabled DEPRECATED_MSG_ATTRIBUTE("use `speakingWasRemoteEnabled:`");
```

## 0.0.4

- **`BJLBlockKVO` 重要升级**：  
`BJLKVOBlock` 返回值类型由 `void` 改为 `BOOL`，以便更容易地取消 KVO；  
解决一个对象对自己 KVO 时可能会产生崩溃的问题；  
解决取消 KVO 时可能出现 `Exception` 的问题；  

- **新增进教室成功、失败回调，原成功事件方法废弃，原失败事件方法只用于退出教室**；
```objc
- (BJLOEvent)enterRoomSuccess;
- (BJLOEvent)enterRoomFailureWithError:(BJLError *)error;
```

- **优化错处理，主动退出教室时 `error` 为 `nil`**，删除原来表示主动退出教室的错误码 ~~`BJLErrorCode_exitRoom_exitRoom`~~；

- **简化错误码**，参考 [NSError+BJLError.h](../BJLiveCore/Headers/NSError+BJLError.h)；

- **内部不主动调用的一些方法，改为进入教室后、掉线重连成功后自动调用一次**，包括
```objc
- [BJLGiftVM loadReceivedGifts];
- [BJLOnlineUsersVM loadMoreOnlineUsersWithCount:];
- [BJLPlayingVM loadPlayingUsers];
- [BJLSlideshowVM loadAllDocuments];
```

- 方法命名优化，**几个标记 `DEPRECATED` 的方法将在正式发版时移除、请及时改用正确的方法**；

- **支持教室连接断开重连**，上层可自由决定是否重连，监听重连进度、结果；

- 完善云端录课逻辑，开始录课时将发起网络请求、检查云端录课是否可用；
```objc
 /** 开始/停止云端录课
 上课状态下才能录课
 此方法需要发起网络请求、检查云端录课是否可用
 - 如果可以录课则开始、并设置 serverRecording
 - 否则发送失败通知 requestServerRecordingDidFailed: */
- (nullable BJLError *)requestServerRecording:(BOOL)on;
/** 检查云端录课不可用的通知
 包括网络请求失败 */
- (BJLOEvent)requestServerRecordingDidFailed:(NSString *)message;
```

- 课件显示支持更多参数设置，参考 [BJLSlideshowUI.h](../BJLiveCore/Headers/BJLSlideshowUI.h)；

- `BJLMediaVM` 支持获取音视频流调试信息；
```objc
/** 调试: 获取音视频流信息 */
- (NSArray<NSString *> *)avDebugInfo;
```

- BUG 修复，主要解决音视频问题；

