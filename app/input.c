#include <limits.h>
#include "math.h"
#include "input.h"

int input_check(char a[][MAX], int n) {
    double temp;
    int i = 0;

    for (; i < n; i++) {
        if (sscanf(a[i], "%lf", &temp) != 1)
            break;
        if (temp > INT_MAX || temp < INT_MIN) {
            printf(TYPE_OF);
            return 0;
        }
    }
    if (i != 3) {
        printf(CHECK_FAIL);
        return 0;
    }
    return 1;
}
