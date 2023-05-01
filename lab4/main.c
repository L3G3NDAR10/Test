#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include "datatime.h"

int main() {
    while (true) {
        int year = ask_int("Enter year", "Invalid year");
        int month = ask_int("Enter month", "Invalid month");
        int day = ask_int("Enter day", "Invalid day");
        int hour = ask_int("Enter hour", "Invalid hour");
        int minute = ask_int("Enter minutes", "Invalid minutes");
        int second = ask_int("Enter seconds", "Invalid seconds");
        int millisecond = ask_int("Enter milliseconds", "Invalid milliseconds");

        DateTime dateTime = {
            .year = year,
            .month = month,
            .day = day,
            .hour = hour,
            .minute = minute,
            .second = second,
            .millisecond = millisecond
        };

        if (date_is_valid(dateTime)) {
            printf("Date is valid\n");
            char *datetime_str = get_datetime_str(dateTime);
            printf("%s\n", datetime_str);
            free(datetime_str);
        } else {
            printf("Date is invalid\n");
        }

        if (ask_yes_no("Do you want to enter new data?", "Invalid input") == NO) {
            break;
        }
    }
    return 0;
}