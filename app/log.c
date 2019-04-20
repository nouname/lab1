#include <stdio.h>
#include "log.h"
#include "codes.h"

void printErrorLog(int n, char* err, char* data) {
    FILE *f = fopen("log.txt", "w");
    if (!f) {
        printf(LOG_FAIL);
        return;
    }
    fprintf(f, "Description: %s\nTest: %d\n%s", err, n, data);
}
