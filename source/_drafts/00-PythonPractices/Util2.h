//
//  Util.h
//  V3.0
//
//  Created by liuyan on 14/12/26.
//  Copyright (c) 2014年 chehang168. All rights reserved.
//

#define LRString [NSString stringWithFormat:@"%s", __FILE__].lastPathComponent
#define NSLog(...) printf("%s 第%d行: %s\n\n", [LRString UTF8String] ,__LINE__, [[NSString stringWithFormat:__VA_ARGS__] UTF8String]);

#define HTTP2 @"http://saas.chehang168.com"
//#define HTTP2 @"http://test-www.cheoo.com/saas"

#define LOCAL_TIME @"local_time"

#define SERVER_TIME @"server_time"

#define  HTTP2_VERSION @"v1.2"

#define  DEVICE_VERSION @"1"


#define WE_CHAT_REGISTER_ID @"wxfbce148ad37d8718"

#define UM_REGISTER_ID @"5a702182f29d9833e900023a"

#define BUGLY_REGISTER_ID @"4c608c43eb"

#define MAP_REGISTER_ID @"70e84724bf020729713acd3009375003"

 

#define kMaxLength 17

#define KPhoneMaxLength 11

#define Left_Margin 15

#define NUM @"0123456789"
#define ALPHA @"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
#define ALPHANUM @"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"


#import "MJRefresh.h"
#import <MessageUI/MessageUI.h>
#import "WXApi.h"
#import "UIImageView+WebCache.h"
#import "UIButton+WebCache.h"
#import "UINavigationController+Extra.h"
#import "SCCTrack.h"
#import "Masonry.h"
//自定义表格
#import "BaseViewAndTable_Controller.h"
#import "BaseView_Controller.h"
#import "BaseTableView_Controller.h"
#import "BaseGroupTableView_Controller.h"

@interface Util2 : NSObject

+ (void)globalGetDataWithUrl:(NSString *)url  loadtext:(NSString *)loadtext success:(void (^)(id json))success fail:(void (^)(void))fail;
+ (void)globalPostDataWithUrl:(NSString *)url loadtext:(NSString *)loadtext parameters:(id)parameters success:(void (^)(id json))success fail:(void (^)(void))fail;
+ (void)globalUploadWithUrl:(NSString *)url loadtext:(NSString *)loadtext parameters:(id)parameters image:(NSData *)image success:(void (^)(id json))success fail:(void (^)(void))fail;

+(void)alert:(NSString *)info;
+(UIImage*)imageWithImageSimple:(UIImage*)image;
+(UIImage*)imageWithImageSimple:(UIImage*)image size:(CGSize)imgSize;


+(BOOL)isConnectionAvailable;
+(void)showInfo:(NSString *)str;
+(void)registerIgetuiCid:(NSString *)cid;


+(NSString *)timeStr;
+(NSString*)signStr:(NSArray*)array value:(NSDictionary *)vdic post:(BOOL)post url:(NSString*)url;
+ (void)callPhoneStr:(NSString*)phoneStr  withVC:(UIViewController *)selfvc coverId:(NSString *)idstr;
+(void)numVisitUpload:(NSDictionary*)dic;
@end
