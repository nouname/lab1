#ifndef INPUT_TEST_H
#define INPUT_TEST_H

#include "globals.h"

TEST(inputTest, correctArgs) {
    module_name = "input";

    char a[][MAX] = {"1", "2", "3"};
    double r = input_check(a, 3), e = 1;
    EXPECT_EQ(r, e);

    fail = HasFailure();
    create_log(module_name, fail, CHECK_FAIL, "1, 2, 3", e, r, "", "");
}

TEST(inputTest, incorrectArgs) {
    char a[][MAX] = {"a", "hello", "0"};
    double r = input_check(a, 3), e = 0;
    EXPECT_EQ(r, e);

    fail = HasFailure();
    create_log(module_name, fail * 2, CHECK_FAIL, "a, hello, 0", e, r, "", "");
}

TEST(inputTest, fewArgs) {
    char a[][MAX] = {"1", "2"};
    double r = input_check(a, 2), e = 0;
    EXPECT_EQ(r, e);

    fail = HasFailure();
    create_log(module_name, fail * 3, CHECK_FAIL, "1, 2", e, r, "", "");
}


TEST(inputTest, manyArgs) {
    char a[][MAX] = {"1", "2",  "3", "4"};
    double r = input_check(a, 4), e = 0;
    EXPECT_EQ(r, e);

    fail = HasFailure();
    create_log(module_name, fail * 4, CHECK_FAIL, "1, 2", e, r, "", "");
}


TEST(inputTest, minValue) {
    char a[][MAX] = {"1", "2", "-21474836470"};
    double r = input_check(a, 3), e = 0;
    EXPECT_EQ(r, e);

    fail = HasFailure();
    create_log(module_name, fail * 5, TYPE_OF, "1, 2, -21474836470", e, r, "", "");
}

TEST(inputTest, maxValue) {
    char a[][MAX] = {"1", "2", "21474836470"};
    double r = input_check(a, 3), e = 0;
    EXPECT_EQ(r, e);

    fail = HasFailure();
    create_log(module_name, fail * 6, TYPE_OF, "1, 2, 21474836470", e, r, "", "");
}
#endif // INPUT_TEST_H
