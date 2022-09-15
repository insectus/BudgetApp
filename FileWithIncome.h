#ifndef FILEWITHINCOME_H
#define FILEWITHINCOME_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "Income.h"
#include "XmlFile.h"
#include "AuxilaryMethod.h"
#include "DateOperation.h"

using namespace std;

class FileWithIncome : public XmlFile {

    DateOperation dateOperation;

    int lastIncomeId;

public:

    FileWithIncome(string incomeFileName) : XmlFile(incomeFileName) {
        lastIncomeId = 0;
    };

    int getLastIncomeId();
    bool addNewIncomeToFile(Income income);
    vector <Income> loadIncomesLoginUser(int idLoginUser);
};

#endif
