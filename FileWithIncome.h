#ifndef FILEWITHINCOME_H
#define FILEWITHINCOME_H

#include <iostream>

#include "Income.h"
#include "XmlFile.h"
#include "AuxilaryMethod.h"

using namespace std;

class FileWithIncome : public XmlFile {

    int lastIncomeId;

public:

    FileWithIncome(string incomeFileName) : XmlFile(incomeFileName){
       lastIncomeId = 0;
    };

    int getLaseIncomeId();
};

#endif
