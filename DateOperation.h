#ifndef DATEOPERATION_H
#define DATEOPERATION_H


#include <ctime>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class DateOperation {

    int dateAsInt;
    int yearInt, monthInt, dayInt;
    int inputYearToInt, inputMonthToInt, inputDayToInt;
    string year, month, day, dateAsString;

    int getNumberOfDays();
    bool dateFormatValidation(string inputDate);
    bool dateRange(string inputDate);

public:

    int getDateAsInt(string date);
    bool dateValidation(string inputDate);
    string convertDateFromIntToString(int date);
    string getCurrentYearMonthDayAsString();

};

#endif


