#ifndef GLOBALS_H
#define GLOBALS_H

#include <gtest/gtest.h>
#include <limits.h>
#include "log.h"

extern "C" {
#include "input.h"
#include "roots.h"
#include "codes.h"
}

static int fail = 0;
static const char* module_name;

#endif // GLOBALS_H
