LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := luajit
LOCAL_SRC_FILES := $(LOCAL_PATH)/../ext/$(TARGET_ARCH_ABI)/libluajit.a
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
 
LOCAL_MODULE    := nonlua
LOCAL_C_INCLUDES := nonlua lua luasocket 
 
LOCAL_CFLAGS := $(LOCAL_C_INCLUDES:%=-I%) -O2 -Wall -D__ANDROID__
LOCAL_CPPFLAGS := $(LOCAL_C_INCLUDES:%=-I%) -O2 -Wall -D__ANDROID__
LOCAL_LDLIBS := -lm
LOCAL_ARM_MODE  := arm
LOCAL_STATIC_LIBRARIES := luajit
 
LOCAL_SRC_FILES := luasocket/udp.c\
	luasocket/timeout.c\
	luasocket/inet.c\
	luasocket/tcp.c\
	luasocket/io.c\
	luasocket/options.c\
	luasocket/luasocket.c\
	luasocket/mime.c\
	luasocket/select.c\
	luasocket/except.c\
	luasocket/wsocket.c\
	luasocket/unix.c\
	luasocket/auxiliar.c\
	luasocket/buffer.c\
	luasocket/usocket.c\
	memcpy_wrap.c\
	nonlua/nljavalib.cpp\
	nonlua/nlsocklib.cpp\
	nonlua/nonlua.cpp\
	io.nondev.nonlua.Lua.cpp
 
include $(BUILD_SHARED_LIBRARY)
