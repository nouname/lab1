#include <math.h>
#include <limits.h>
#include "roots.h"
#include "codes.h"

res solve(double a, double b, double c) {
    res r;
    r.msg = "";
    if (a == 0.0) {
        r.msg = NOT_QE;
        return r;
    }
    double d = b * b - 4 * a * c;
    if (d > 0) {
        r.x1 = (-b - sqrt(d))/(2 * a);
        r.x2 = (-b + sqrt(d))/(2 * a);
    } else if (d < 0) {
       r.msg = NO_SOLUTION;
    } else {
       r.x1 = -b/(2 * a);
       r.x2 = INT_MAX;
    }
    return r;
}

double print(res r) {
    if (r.msg[0] != '\0') {
        printf("%s", r.msg);
        return -1;
    }
    else if (r.x2 >= INT_MAX) {
        printf("%.3f\n", r.x1);
        return 1;
    }
    else {
        printf("%.3f %.3f\n", r.x1, r.x2);
        return 0;
    }
}
