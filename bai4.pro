QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.

INCLUDEPATH += C:/Users/Admin/Desktop/openCV4/install/include/
LIBS +=-LC:\\\Users\\Admin\\Desktop\\openCV4\\install\\x64\\mingw\\bin\
libopencv_core450 \
libopencv_highgui450 \
libopencv_imgcodecs450 \
libopencv_imgproc450 \
libopencv_features2d450 \
libopencv_video450 \
libopencv_videoio450 \


SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
