include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG += c++14
CONFIG -= qt

QMAKE_CXXFLAGS += -Wall -Wextra -Werror
QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov


HEADERS +=     tst_test1.h \
    fibonachi_test.h \
    roots_test.h \
    input_test.h \
    log.h \
    globals.h

SOURCES +=     main.cpp \
    ../app/myfunc.c \
    ../app/roots.c \
    ../app/input.c \
    log.cpp

INCLUDEPATH += ../app
