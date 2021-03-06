PRJTYPE = Executable
LIBS = gfxwnd glfw glad
ifeq ($(TARGET_OS), Windows)
	LIBS += glu32 opengl32 gdi32 winmm ole32 shell32 user32
else ifeq ($(TARGET_OS), Darwin)
	MLDFLAGS += -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo
else
	LIBS += GLU GL X11 Xcursor Xinerama Xrandr Xxf86vm Xi pthread m dl
endif
ADDINCS = ../deps/Glad/include
ADDLIBDIR = ../deps/Glfw/lib \
			../deps/Glad/lib
MOREDEPS = ..
