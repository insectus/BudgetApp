#ifndef DATEOPERATION_H
#define DATEOPERATION_H


#include <ctime>
#include <iostream>
#include <sstream>

using namespace std;

class DateOperation {

    string year, month, day, dateAsString;
    int dayAsYear;

public:

    string getCurrentYearMonthDayAsString();
    int getCurrentYearMonthDayAsInt();
};

#endif


