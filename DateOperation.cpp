#include "DateOperation.h"

string DateOperation::getCurrentYearMonthDayAsString() {

    time_t t;
    stringstream ssYear, ssMonth, ssDay;

    t = time(0);   // get time now #include <ctime>
    tm* now = localtime(&t);

    ssYear << (now->tm_year + 1900);
    year = ssYear.str();
    yearInt = stoi(year);

    ssMonth << (now->tm_mon + 1);
    month = ssMonth.str();
    monthInt = stoi(month);

    ssDay << (now->tm_mday);
    day = ssDay.str();
    dayInt = stoi(day);

    if (stoi(month) <= 9){
        month = "0" + month;
    }

    if (stoi(day) <= 9){
        day = "0" + day;
    }

    dateAsString = year + "-" + month + "-" + day;

    return dateAsString;
}

int DateOperation::getCurrentYearMonthDayAsInt() {
//
    return 0;
}

int DateOperation::getNumberOfDays() {
        //leap year condition, if month is 2
        if( inputMonthToInt == 2) {
            if((inputYearToInt%400==0) || (inputYearToInt%4==0 && inputYearToInt%100!=0))
                return 29;
            else
                return 28;
        }
        //months which has 31 days
        else if(inputMonthToInt== 1 || inputMonthToInt == 3 || inputMonthToInt == 5 || inputMonthToInt == 7 || inputMonthToInt == 8
                || inputMonthToInt == 10 || inputMonthToInt == 12)
            return 31;
        else
            return 30;
}

bool DateOperation::dateFormatValidation(string inputDate) {
    bool length = true, separator = true, allDigits = true;
    if(inputDate.size()!= 10) {
        cout << "Zla dlugosc " << endl;
        length = false;
    }

    if((inputDate[4] != '-') && (inputDate[7] != '-')) {
        cout << "Zly format" << endl;
        separator = false;
    }

    for(int i = 0; i < inputDate.size(); i++) {
        if(i==4 || i==7) {
            continue;
        } else {
            if(!isdigit(inputDate[i])) {
                cout << "Data zawiera inne znaki niz cyfry i pauzy." << endl;
                allDigits = false;
            }
        }
    }

    if(length && separator && allDigits) {
        return true;
    }else{
        return false;
    }
}

bool DateOperation::dateRange(string inputDate) {
    //int inputYearToInt, inputMonthToInt, inputDayToInt;
    inputYearToInt = stoi(inputDate.substr(0,4));
    inputMonthToInt = stoi(inputDate.substr(5,2));
    inputDayToInt = stoi(inputDate.substr(8,2));
    bool yearCorrect = true, monthCorrect = true, dayCorrect = true, dateToThisMonth = true;
    if((inputYearToInt < 2001) ||(yearInt < inputYearToInt)) {
        yearCorrect = false;
        //cout << "Year" << endl;
    }
    if((inputMonthToInt < 1) && (inputMonthToInt > 12)) {
        monthCorrect = false;
        //cout << "month" << endl;
    }
    if((inputDayToInt > 0) && (inputDayToInt > getNumberOfDays())) {
        dayCorrect = false;
        //cout << "day" << endl;
    }
    if(inputMonthToInt > monthInt) {
        dateToThisMonth = false;
    }
    if(yearCorrect && monthCorrect && dayCorrect && dateToThisMonth) {
        return true;
        //cout << "Sukces" << endl;
    } else {
        return false;
        cout << "Niew³asciwy zakres daty.\nPoraj date z przedzialu od 2001-01-01 do ostatniego dnia obecnego miesiaca.\n";
    }
}

bool DateOperation::dateValidation(string inputDate) {
    /*
    if(dateFormatValidation(inputDate)) {
    } else {
        return false;
    }
    if(dateRange(inputDate)) {
        return true;
    } else {
        return false;
    }
    */

    inputYearToInt = stoi(inputDate.substr(0,4));
    inputMonthToInt = stoi(inputDate.substr(5,2));
    inputDayToInt = stoi(inputDate.substr(8,2));
    bool yearCorrect = true, monthCorrect = true, dayCorrect = true, dateToThisMonth = true;
    if((inputYearToInt < 2001) ||(yearInt < inputYearToInt)) {
        yearCorrect = false;
        cout << "Year" << endl << inputYearToInt << endl << yearInt << endl;
    }
    if((inputMonthToInt < 1) && (inputMonthToInt > 12)) {
        monthCorrect = false;
        cout << "month" << endl;
    }
    if((inputDayToInt > 0) && (inputDayToInt > getNumberOfDays())) {
        dayCorrect = false;
        cout << "day" << endl;
    }
    if(inputMonthToInt > monthInt) {
        dateToThisMonth = false;
    }
    if(yearCorrect && monthCorrect && dayCorrect && dateToThisMonth) {
        return true;
        cout << "Sukces" << endl;
    } else {
        return false;
        cout << "Niew³asciwy zakres daty.\nPoraj date z przedzialu od 2001-01-01 do ostatniego dnia obecnego miesiaca.\n";
    }
}
