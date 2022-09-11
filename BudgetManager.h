#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "AuxilaryMethod.h"
#include "DateOperation.h"
#include "Expense.h"
#include "Income.h"
#include "FileWithExpense.h"
#include "FileWithIncome.h"
#include "User.h"


using namespace std;

class BudgetManager {

    FileWithIncome fileWithIncome;
    FileWithExpense fileWithExpense;

    const int ID_LOGIN_USER;

    vector <Income> incomes;

    Income addNewIncome();

public:
    BudgetManager(string INCOME_FILE_NAME, string  EXPENSE_FILE_NAME, int idLoginUser)
    : fileWithIncome(INCOME_FILE_NAME), fileWithExpense(EXPENSE_FILE_NAME), ID_LOGIN_USER(idLoginUser){
    //
    };

    void addIncome();

};

#endif
