TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
SOURCES += main.c \
    myfunc.c \
    roots.c \
    input.c
HEADERS += myfunc.h \
    roots.h \
    input.h \
    codes.h
QMAKE_CFLAGS += -Wall \
    -Wextra \
    -Werror

# gcov
QMAKE_CFLAGS += -fprofile-arcs \
    -ftest-coverage
LIBS += -lgcov
