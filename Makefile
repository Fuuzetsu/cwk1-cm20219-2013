#############################################################################
# Makefile for building: qtgl1
# Generated by qmake (2.01a) (Qt 4.8.5) on: Sun Oct 27 21:41:23 2013
# Project:  qtgl.pro
# Template: app
# Command: /usr/bin/qmake -o Makefile qtgl.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_OPENGL_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtOpenGL -I/usr/include/qt4 -I. -I/usr/X11R6/include -I. -I.
LINK          = g++
LFLAGS        = -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib/qt4 -L/usr/X11R6/lib -lQtOpenGL -L/usr/lib/qt4 -L/usr/X11R6/lib -lQtGui -lQtCore -lgthread-2.0 -lglib-2.0 -lGL -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = glwidget.cpp \
		main.cpp \
		window.cpp \
		shape.cpp \
		square.cpp \
		circle.cpp moc_glwidget.cpp \
		moc_window.cpp
OBJECTS       = glwidget.o \
		main.o \
		window.o \
		shape.o \
		square.o \
		circle.o \
		moc_glwidget.o \
		moc_window.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/opengl.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		qtgl.pro
QMAKE_TARGET  = qtgl1
DESTDIR       = 
TARGET        = qtgl1

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_MainWindow.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: qtgl.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/opengl.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/qt4/libQtOpenGL.prl \
		/usr/lib/qt4/libQtGui.prl \
		/usr/lib/qt4/libQtCore.prl
	$(QMAKE) -o Makefile qtgl.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/shared.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/opengl.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/qt4/libQtOpenGL.prl:
/usr/lib/qt4/libQtGui.prl:
/usr/lib/qt4/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile qtgl.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/qtgl11.0.0 || $(MKDIR) .tmp/qtgl11.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/qtgl11.0.0/ && $(COPY_FILE) --parents glwidget.h window.h shape.h square.h version.h circle.h .tmp/qtgl11.0.0/ && $(COPY_FILE) --parents glwidget.cpp main.cpp window.cpp shape.cpp square.cpp circle.cpp .tmp/qtgl11.0.0/ && $(COPY_FILE) --parents MainWindow.ui .tmp/qtgl11.0.0/ && (cd `dirname .tmp/qtgl11.0.0` && $(TAR) qtgl11.0.0.tar qtgl11.0.0 && $(COMPRESS) qtgl11.0.0.tar) && $(MOVE) `dirname .tmp/qtgl11.0.0`/qtgl11.0.0.tar.gz . && $(DEL_FILE) -r .tmp/qtgl11.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_glwidget.cpp moc_window.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_glwidget.cpp moc_window.cpp
moc_glwidget.cpp: shape.h \
		glwidget.h
	/usr/bin/moc $(DEFINES) $(INCPATH) glwidget.h -o moc_glwidget.cpp

moc_window.cpp: ui_MainWindow.h \
		glwidget.h \
		shape.h \
		window.h
	/usr/bin/moc $(DEFINES) $(INCPATH) window.h -o moc_window.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_MainWindow.h
compiler_uic_clean:
	-$(DEL_FILE) ui_MainWindow.h
ui_MainWindow.h: MainWindow.ui \
		glwidget.h \
		shape.h
	/usr/bin/uic MainWindow.ui -o ui_MainWindow.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

glwidget.o: glwidget.cpp circle.h \
		shape.h \
		glwidget.h \
		square.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o glwidget.o glwidget.cpp

main.o: main.cpp window.h \
		ui_MainWindow.h \
		glwidget.h \
		shape.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

window.o: window.cpp version.h \
		window.h \
		ui_MainWindow.h \
		glwidget.h \
		shape.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o window.o window.cpp

shape.o: shape.cpp shape.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o shape.o shape.cpp

square.o: square.cpp square.h \
		shape.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o square.o square.cpp

circle.o: circle.cpp circle.h \
		shape.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o circle.o circle.cpp

moc_glwidget.o: moc_glwidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_glwidget.o moc_glwidget.cpp

moc_window.o: moc_window.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_window.o moc_window.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

