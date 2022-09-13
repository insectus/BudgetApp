#ifndef DATEOPERATION_H
#define DATEOPERATION_H


#include <ctime>
#include <iostream>
#include <sstream>

using namespace std;

class DateOperation {

    string year, month, day, dateAsString;
    int dayAsYear;
    int getNumberOfDays();
    bool dateFormatValidation(string inputDate);
    bool dateRange(string inputDate);

    int inputYearToInt, inputMonthToInt, inputDayToInt;
    int yearInt, monthInt, dayInt;

public:

    string getCurrentYearMonthDayAsString();
    int getCurrentYearMonthDayAsInt();
    bool dateValidation(string inputDate);
};

#endif


