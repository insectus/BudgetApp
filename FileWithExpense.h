#ifndef FILEWITHEXPENSE_H
#define FILEWITHEXPENSE_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "Expense.h"
#include "XmlFile.h"
#include "AuxilaryMethod.h"

using namespace std;

class FileWithExpense : public XmlFile {
    int lastExpenseId;

public:

    FileWithExpense(string expenseFileName) : XmlFile(expenseFileName) {
        lastExpenseId =0;
    };

    int getLastExpenseId();
    bool addNewExpenseToFile(Expense expense);
    vector <Expense> loadExpensesLoginUser(int idLoginUser);

};

#endif
