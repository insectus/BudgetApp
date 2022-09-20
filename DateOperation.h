#ifndef DATEOPERATION_H
#define DATEOPERATION_H


#include <ctime>
#include <iostream>
#include <sstream>
#include <string>

#include "AuxilaryMethod.h"

using namespace std;

class DateOperation {

    int dateAsInt;
    int yearInt, monthInt, dayInt;
    int inputYearToInt, inputMonthToInt, inputDayToInt;
    string year, month, day, dateAsString;


    bool dateFormatValidation(string inputDate);
    bool dateRange(string inputDate);

public:

    int getNumberOfDays();
    int getDateAsInt(string date);
    bool dateValidation(string inputDate);
    string getCurrentYear();
    string getCurrentMont();
    string getCurrentDay();
    string convertDateFromIntToString(int date);
    string getCurrentYearMonthDayAsString();
    string getPriviousMonth();
    string getNumberDaysPraviousMonth();

};

#endif
