#ifndef ROOTS_TEST_H
#define ROOTS_TEST_H

#include "globals.h"

TEST(rootsTest, twoRoots) {
    module_name = "roots";

    double r = solve(2, 3, 1).x1, e = -1;
    EXPECT_EQ(r, e);

    fail = HasFailure();
    create_log(module_name, fail, U_ERR, "2, 3, 1", e, r, "", "");
}

TEST(rootsTest, oneRoot) {
    double r = solve(1, 2, 1).x2, e = INT_MAX;
    EXPECT_GE(r, e);

    fail = HasFailure();
    create_log(module_name, fail * 3, U_ERR, "1, 2, 1", e,  r, "", "");
}

TEST(rootsTest, notQE) {
    const char* m = solve(0, 0, 0).msg, *e = NOT_QE;
    EXPECT_STREQ(m, e);

    fail = HasFailure();
    create_log(module_name, fail * 4, NOT_QE, "0, 0, 0", 0, 0, e, m);
}

TEST(rootsTest, noSolution) {
    const char* m = solve(4, 2, 1).msg, *e = NO_SOLUTION;
    EXPECT_STREQ(m, e);

    fail = HasFailure();
    create_log(module_name, fail * 5, NO_SOLUTION, "4, 2, 1", 0, 0, e, m);
}

/* Add tests for the print function */

TEST(rootsTest, printMsg) {
    double r = print(solve(0, 0, 0)), e = -1;
    EXPECT_EQ(r, e);

    fail = HasFailure();
    create_log(module_name, fail * 6, NOT_QE, "0, 0, 0", e, r, "", "");
}

TEST(rootsTest, printOR) {
    double r = print(solve(1, 2, 1)), e = 1;
    EXPECT_EQ(r, e);

    fail = HasFailure();
    create_log(module_name, fail * 7, NOT_QE, "1, 2, 1", e, r, "", "");
}

TEST(rootsTest, printTR) {
    double r = print(solve(2, 3, 1)), e = 0;
    EXPECT_EQ(r, e);

    fail = HasFailure();
    create_log(module_name, fail * 8, NOT_QE, "2, 3, 1", e, r, "", "");
}

#endif // ROOTS_TEST_H
