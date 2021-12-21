LOCAL_PATH := $(call my-dir)
SRC_DIR := ../../../source

include $(CLEAR_VARS)
LOCAL_MODULE := RenderingPlugin
LOCAL_C_INCLUDES += $(SRC_DIR)
LOCAL_LDLIBS := -llog
LOCAL_ARM_MODE := arm

LOCAL_SRC_FILES += $(SRC_DIR)/RenderAPI.cpp
LOCAL_SRC_FILES += $(SRC_DIR)/RenderingPlugin.cpp

# OpenGL ES
LOCAL_SRC_FILES += $(SRC_DIR)/RenderAPI_OpenGLCoreES.cpp
LOCAL_LDLIBS += -lGLESv2 -lEGL
LOCAL_CPPFLAGS += -DSUPPORT_OPENGL_ES=1


# build
include $(BUILD_SHARED_LIBRARY)
