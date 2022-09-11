#include "DateOperation.h"

string DateOperation::getCurrentYearMonthDayAsString() {

    time_t t;
    stringstream ssYear, ssMonth, ssDay;


    t = time(0);   // get time now #include <ctime>
    tm* now = localtime(&t);

    ssYear << (now->tm_year + 1900);
    year = ssYear.str();

    ssMonth << (now->tm_mon + 1);
    month = ssMonth.str();

    ssDay << (now->tm_mday);
    day = ssDay.str();

    dateAsString = year + "-" + month + "-" + day;

    return dateAsString;
}

int DateOperation::getCurrentYearMonthDayAsInt() {
//
    return 0;
}
