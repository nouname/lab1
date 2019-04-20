TEMPLATE = subdirs

CONFIG -= app_bundle
CONFIG -= qt

CONFIG += c++14

QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage -O0

SUBDIRS = app tests

CONFIG += ordered
