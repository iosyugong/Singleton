

#define interfaceSinglenton(name) +(instancetype)share##name

#if __has_feature(objc_arc)

#define implementationSinglenton(name) \
+ (instancetype)share##name { \
name *instance = [[self alloc] init]; \
return instance; \
} \
\
static name *_instance = nil; \
+ (instancetype)allocWithZone:(struct _NSZone *)zone { \
static dispatch_once_t onceToken; \
dispatch_once(&onceToken, ^{ \
if (_instance == nil) { \
_instance = [super allocWithZone:zone]; \
} \
}); \
return _instance; \
} \
\
- (id)copyWithZone:(NSZone *)zone { \
return _instance; \
} \
\
- (id)mutableCopyWithZone:(NSZone *)zone { \
return _instance; \
}

#else

#define implementationSinglenton(name) \
+ (instancetype)share##name { \
name *instance = [[self alloc] init]; \
return instance; \
} \
\
static name *_instance = nil; \
+ (instancetype)allocWithZone:(struct _NSZone *)zone { \
static dispatch_once_t onceToken; \
dispatch_once(&onceToken, ^{ \
if (_instance == nil) { \
_instance = [super allocWithZone:zone]; \
} \
}); \
return _instance; \
} \
\
- (id)copyWithZone:(NSZone *)zone { \
return _instance; \
} \
\
- (id)mutableCopyWithZone:(NSZone *)zone { \
return _instance; \
}\
\
- (oneway void)release { \
\
} \
\
- (instancetype)retain { \
return _instance;\
} \
\
- (NSUInteger)retainCount { \
return MAXFLOAT; \
}

#endif
