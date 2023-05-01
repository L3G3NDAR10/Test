#include "convert.h"
#include <stdlib.h>

bool try_convert_to_int(const char *string, int *result) {
    char *endptr;
    long value = strtol(string, &endptr, 10);
    if (*endptr != '\0') {
        return false;
    }
    if (value < INT_MIN || value > INT_MAX) {
        return false;
    }
    *result = (int)value;
    return true;
}

bool try_convert_to_long(const char *string, long *result) {
    char *endptr;
    *result = strtol(string, &endptr, 10);
    return (*endptr == '\0');
}

bool try_convert_to_double(const char *string, double *result) {
    char *endptr;
    *result = strtod(string, &endptr);
    return (*endptr == '\0');
}