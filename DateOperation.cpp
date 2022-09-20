#include "DateOperation.h"

string DateOperation::getCurrentYearMonthDayAsString() {

    time_t t;
    stringstream ssYear, ssMonth, ssDay;

    t = time(0);
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

    if (stoi(month) <= 9) {
        month = "0" + month;
    }

    if (stoi(day) <= 9) {
        day = "0" + day;
    }

    dateAsString = year + "-" + month + "-" + day;

    return dateAsString;
}

string DateOperation::getCurrentYear() {
    getCurrentYearMonthDayAsString();
    return year;
}

string DateOperation::getCurrentMont() {
    getCurrentYearMonthDayAsString();
    return month;
}

string DateOperation::getCurrentDay() {
    getCurrentYearMonthDayAsString();
    return day;
}

int DateOperation::getDateAsInt(string date) {

    string year, month, day;

    year = date.substr(0,4);
    month = date.substr(5,2);
    day = date.substr(8,2);

    dateAsInt = stoi(year + month + day);

    return dateAsInt;
}

string DateOperation::convertDateFromIntToString(int date) {

    string year, month, day;

    year = to_string(date);
    year = year.substr(0,4);
    month = to_string(date);
    month = month.substr(4,2);
    day = to_string(date);
    day = day.substr(6,2);

    dateAsString = year + "-" + month + "-" + day;

    return dateAsString;
}

int DateOperation::getNumberOfDays() {

    if( inputMonthToInt == 2) {
        if((inputYearToInt%400==0) || (inputYearToInt%4==0 && inputYearToInt%100!=0))
            return 29;
        else
            return 28;
    } else if(inputMonthToInt== 1 || inputMonthToInt == 3 || inputMonthToInt == 5 || inputMonthToInt == 7 || inputMonthToInt == 8
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

    if (inputDate.size() < 11) {
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
    }


    if(length && separator && allDigits) {
        return true;
    } else {
        return false;
    }
}

bool DateOperation::dateRange(string inputDate) {
    getCurrentYearMonthDayAsString();
    inputYearToInt = stoi(inputDate.substr(0,4));
    inputMonthToInt = stoi(inputDate.substr(5,2));
    inputDayToInt = stoi(inputDate.substr(8,2));
    bool yearCorrect = true, monthCorrect = true, dayCorrect = true, dateToThisMonth = true;
    if((inputYearToInt < 2001) ||(yearInt < inputYearToInt)) {
        yearCorrect = false;
        cout << "Minimalny rok, to 2001 a maksymalny obecny." << endl;
    }
    if((inputMonthToInt < 1) || (inputMonthToInt > 12)) {
        monthCorrect = false;
        cout << "Podales blednie miesiac" << endl;
    }
    if((inputDayToInt < 1) || (inputDayToInt > getNumberOfDays())) {
        dayCorrect = false;
        cout << "Podales blednie dzien" << endl;
    }
    if((inputMonthToInt > monthInt) && (yearInt == inputYearToInt)) {
        dateToThisMonth = false;
        cout << "Data nie moze byc wieksza niz ostatni dzien biezacego miesiaca" << endl;

    }
    if(yearCorrect && monthCorrect && dayCorrect && dateToThisMonth) {
        return true;
    } else {
        return false;
        cout << "Niewlasciwy zakres daty.\nPoraj date z przedzialu od 2001-01-01 do ostatniego dnia obecnego miesiaca.\n";
    }
}

bool DateOperation::dateValidation(string inputDate) {

    if(dateFormatValidation(inputDate)) {
    } else {
        return false;
    }
    if(dateRange(inputDate)) {
        return true;
    } else {
        return false;
    }

}

string DateOperation::getPriviousMonth() {

    string yearAndMonth;
    string inputDate = getCurrentYearMonthDayAsString();
    inputYearToInt = stoi(inputDate.substr(0,4));
    inputMonthToInt = stoi(inputDate.substr(5,2));

    if(inputMonthToInt == 01) {
        inputMonthToInt = 12;
        inputYearToInt = inputYearToInt - 1;
        year = AuxilaryMethod::convertIntToString(inputYearToInt);
    } else {
        inputMonthToInt = inputMonthToInt - 1;
    }
    if (inputMonthToInt <= 9) {
        month = AuxilaryMethod::convertIntToString(inputMonthToInt);
        month = "0" + month;
    } else {
        month = AuxilaryMethod::convertIntToString(inputMonthToInt);
    }

    yearAndMonth = year + month;
    return yearAndMonth;
}

string DateOperation::getNumberDaysPraviousMonth() {

    string praviousDate = getPriviousMonth();
    int previousYear = stoi(praviousDate.substr(0,4));
    int previousMonth = stoi(praviousDate.substr(4,2));

    if( previousMonth == 2) {
        if((previousYear%400==0) || (previousYear%4==0 && previousYear%100!=0))
            return "29";
        else
            return "28";
    } else if(previousMonth== 1 || previousMonth == 3 || previousMonth == 5 || previousMonth == 7 || previousMonth == 8
              || previousMonth == 10 || previousMonth == 12)
        return "31";
    else
        return "30";
}
