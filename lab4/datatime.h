#ifndef DATETIME_H
#define DATETIME_H

#include <stdbool.h>
#include <time.h>

typedef enum {
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
} WeekDay;

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    int millisecond;
} DateTime;

bool date_is_valid(DateTime dateTime);
WeekDay get_weekday(DateTime dateTime);
char *get_month(DateTime dateTime);
char *get_weekday_str(WeekDay weekDay);
char *get_datetime_str(DateTime dateTime);

#endif