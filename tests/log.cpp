#include <string>
#include <sstream>
#include <ctime>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "codes.h"
#include "log.h"

using namespace std;

template <typename T>
string to_str(T);

string suffix();

void create_log(const char* module, int n, const char* msg, const char* in, double exp_result = 0, double act_result = 0, const char* e = "", const char* a = "") {
    if (!n) {
        printf(NO_ERROR);
        return;
    }

    string log_name = "LOG-" + suffix() + ".txt";
    FILE *f = fopen(log_name.c_str(), "a");
    if (access(log_name.c_str(), F_OK) == -1) {
        f = fopen(log_name.c_str(), "w");
    }
    if (!f) {
        printf(LOG_FAIL);
        return;
    }

    fprintf(f, "Module: %s\nTest: %d\nDescription: %sInput: %s\n", module, n, msg, in);
    fprintf(f, "Expected result: ");
    if (strcmp(e, ""))
        fprintf(f, "%s\n", e);
    else
        fprintf(f, "%lf\n", exp_result);

    fprintf(f, "Actual result: ");
    if (strcmp(a, ""))
        fprintf(f, "%s\n\n", a);
    else
        fprintf(f, "%lf\n\n", act_result);

    fclose(f);
}

string suffix() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    return to_str(tm.tm_hour) + "-" + to_str(tm.tm_min) + "-" + to_str(tm.tm_sec) + "-" + to_str(tm.tm_mday) + "-" + to_str(tm.tm_mon + 1) + "-" + to_str(tm.tm_year + 1900);
}

template <typename T>
string to_str(T n)
{
     ostringstream ss;
     ss << n;
     return ss.str();
}
