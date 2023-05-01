#include "input.h"
#include "convert.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 256

YESNO ask_yes_no(const char *msg, const char *error_msg) {
    char input[MAX_INPUT_LENGTH];
    while (true) {
        printf("%s (y/n): ", msg);
        if (fgets(input, MAX_INPUT_LENGTH, stdin) == NULL) {
            exit(EXIT_FAILURE);
        }
        if (strlen(input) == 2 && input[0] == 'y') {
            return YES;
        }
        if (strlen(input) == 2 && input[0] == 'n') {
            return NO;
        }
        printf("%s\n", error_msg);
    }
}

int ask_int(const char *msg, const char *error_msg) {
    char input[MAX_INPUT_LENGTH];
    int result;
    while (true) {
        printf("%s: ", msg);
        if (fgets(input, MAX_INPUT_LENGTH, stdin) == NULL) {
            exit(EXIT_FAILURE);
        }
        if (try_convert_to_int(input, &result)) {
            return result;
        }
        printf("%s\n", error_msg);
    }
}

double ask_double(const char *msg, const char *error_msg) {
    char input[MAX_INPUT_LENGTH];
    double result;
    while (true) {
        printf("%s: ", msg);
        if (fgets(input, MAX_INPUT_LENGTH, stdin) == NULL) {
            exit(EXIT_FAILURE);
        }
        if (try_convert_to_double(input, &result)) {
            return result;
        }
        printf("%s\n", error_msg);
    }
}

char *ask_string(const char *msg, const char *error_msg) {
    char input[MAX_INPUT_LENGTH];
    while (true) {
        printf("%s: ", msg);
        if (fgets(input, MAX_INPUT_LENGTH, stdin) == NULL) {
            exit(EXIT_FAILURE);
        }
        size_t len = strlen(input);
        if (len > 0 && input[len-1] == '\n') {
            input[len-1] = '\0';
        }
        if (strlen(input) > 0) {
            return strdup(input);
        }
        printf("%s\n", error_msg);
    }
}
