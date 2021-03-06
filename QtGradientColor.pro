# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Add-in.
# ------------------------------------------------------

TEMPLATE = app
TARGET = QtGradientColor
DESTDIR = ./x64/Debug
DEPENDPATH += . GeneratedFiles

MOC_DIR = GeneratedFiles/moc
RCC_DIR = GeneratedFiles/rcc
UI_DIR = GeneratedFiles/ui
OBJECTS_DIR = GeneratedFiles/obj

QT += core gui xml
CONFIG += debug
DEFINES += QT_LARGEFILE_SUPPORT QT_DLL

INCLUDEPATH += ./GeneratedFiles \
				. \
				./include \
				./GeneratedFiles/Debug

HEADERS += ./include/qtgradientutils.h \
		./include/qtgradientmanager.h \
		./include/qtgradientwidget.h \
		./include/qtgradientstopswidget.h \
		./include/qtcolorline.h \
		./include/qtcolorbutton.h \
		./include/qtgradientstopsmodel.h \
		./include/qtgradientstopscontroller.h \
		./include/qtgradienteditor.h \
		./include/gradientcolor.h \
		./include/qtgradientdialog.h \
		./include/qtgradientview.h \
		./include/qtgradientviewdialog.h
		
SOURCES += ./src/gradientcolor.cpp \
		./src/main.cpp \
		./src/qtcolorbutton.cpp \
		./src/qtcolorline.cpp \
		./src/qtgradientdialog.cpp \
		./src/qtgradienteditor.cpp \
		./src/qtgradientmanager.cpp \
		./src/qtgradientstopscontroller.cpp \
		./src/qtgradientstopsmodel.cpp \
		./src/qtgradientstopswidget.cpp \
		./src/qtgradientutils.cpp \
		./src/qtgradientview.cpp \
		./src/qtgradientviewdialog.cpp \
		./src/qtgradientwidget.cpp
		
FORMS += ./ui/qtgradientviewdialog.ui \
		./ui/qtgradientview.ui \
		./ui/qtgradientdialog.ui \
		./ui/qtgradienteditor.ui \
		./ui/gradientcolor.ui
		
RESOURCES += qtgradientmanager.qrc
