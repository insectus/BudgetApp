#ifndef FILEWITHEXPENSE_H
#define FILEWITHEXPENSE_H

#include <iostream>

#include "Expense.h"
#include "XmlFile.h"
#include "AuxilaryMethod.h"

using namespace std;

class FileWithExpense : public XmlFile {

public:

    FileWithExpense(string expenseFileName) : XmlFile(expenseFileName){
        //
    };

};

#endif
