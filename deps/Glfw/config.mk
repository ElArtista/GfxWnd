PRJTYPE = StaticLib
VERSION = 3.2.1
SRC = \
	src/context.c \
	src/init.c    \
	src/input.c   \
	src/monitor.c \
	src/vulkan.c  \
	src/window.c
ifeq ($(TARGET_OS), Windows_NT)
	SRC += \
		src/win32_init.c     \
		src/win32_joystick.c \
		src/win32_monitor.c  \
		src/win32_time.c     \
		src/win32_tls.c      \
		src/win32_window.c   \
		src/wgl_context.c    \
		src/egl_context.c
else ifeq ($(TARGET_OS), Darwin)
	SRC += \
		src/cocoa_init.m     \
		src/cocoa_joystick.m \
		src/cocoa_monitor.m  \
		src/cocoa_window.m   \
		src/cocoa_time.c     \
		src/posix_tls.c      \
		src/nsgl_context.m
else
	SRC += \
		src/x11_init.c       \
		src/x11_monitor.c    \
		src/x11_window.c     \
		src/xkb_unicode.c    \
		src/linux_joystick.c \
		src/posix_time.c     \
		src/posix_tls.c      \
		src/glx_context.c    \
		src/egl_context.c
endif

DEFINES = _GLFW_USE_OPENGL
ifeq ($(TARGET_OS), Windows_NT)
	DEFINES += _GLFW_WIN32
else ifeq ($(TARGET_OS), Darwin)
	DEFINES += _GLFW_COCOA
else
	DEFINES += _GLFW_X11
endif

ADDINCS = contrib/GL/include
