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
#include "UserManager.h"

using namespace std;

class BudgetManager {

    FileWithIncome fileWithIncome;
    FileWithExpense fileWithExpense;
    DateOperation dateOperation;

    const int ID_LOGIN_USER;
    int lastIncomeId;
    //int lastExpenseId;

    vector <Income> incomes;
    //vector <Expense> expenses;

    Income addNewIncome();
    //Income addNewExpense();

public:
    BudgetManager(string INCOME_FILE_NAME, string  EXPENSE_FILE_NAME, int idLoginUser)//
        : fileWithIncome(INCOME_FILE_NAME), fileWithExpense(EXPENSE_FILE_NAME), ID_LOGIN_USER(idLoginUser) { //
        incomes = fileWithIncome.loadIncomesLoginUser(ID_LOGIN_USER);
        //expenses = fileWithExpense.loadExpensesLoginUser(ID_LOGIN_USER);
    };

    void addIncome();
    //void addExpense();
};

#endif
