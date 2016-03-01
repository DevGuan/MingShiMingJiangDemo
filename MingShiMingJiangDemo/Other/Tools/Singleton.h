//
//  Singleton.h
//  单例模式整合（ARC与非ARC）
//
//  Created by 管复生 on 16/1/12.
//  Copyright © 2016年 GFS. All rights reserved.
//

#define Singleton_h(name) + (instancetype)shared##name;

#if __has_feature(objc_arc)
#define Singleton_m(name) \
static id _instance; \
+ (id)allocWithZone:(struct _NSZone *)zone \
{ \
    static dispatch_once_t onceToken; \
    dispatch_once(&onceToken, ^{ \
        _instance = [super allocWithZone:zone]; \
    }); \
    return _instance; \
} \
+ (instancetype)shared##name{ \
     \
    static dispatch_once_t onceToken; \
    dispatch_once(&onceToken, ^{ \
        _instance = [[self alloc]init]; \
    }); \
    return _instance; \
}
#else
#define Singleton_m(name) \
static id _instance; \
+ (id)allocWithZone:(struct _NSZone *)zone \
{ \
static dispatch_once_t onceToken; \
dispatch_once(&onceToken, ^{ \
_instance = [super allocWithZone:zone]; \
}); \
return _instance; \
} \
+ (instancetype)shared##name{ \
\
static dispatch_once_t onceToken; \
dispatch_once(&onceToken, ^{ \
_instance = [[self alloc]init]; \
}); \
return _instance; \
} \
- (oneway void)release \
{ \
    \
} \
\
- (id)autorelease \
{ \
    return _instance; \
} \
\
- (id)retain \
{ \
    return _instance; \
} \
\
- (NSUInteger)retainCount \
{ \
    return 1; \
} \
\
+ (id)copyWithZone:(struct _NSZone *)zone \
{ \
    return _instance; \
}
#endif