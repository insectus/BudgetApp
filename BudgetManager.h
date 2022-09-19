#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <algorithm>
#include <iomanip>
#include <cmath>

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
    int lastExpenseId;
    float incomeSum,  expenseSum, balance;

    vector <Income> incomes;
    vector <Expense> expenses;
    vector <Income> curentTimeIncomes;
    vector <Expense> curentTimeExpense;

    Income addNewIncome();
    Expense addNewExpense();
    float incomeSorting(int startDate, int stopDate);
    float expenseSorting(int startDate, int stopDate);

public:
    BudgetManager(string INCOME_FILE_NAME, string  EXPENSE_FILE_NAME, int idLoginUser)//
        : fileWithIncome(INCOME_FILE_NAME), fileWithExpense(EXPENSE_FILE_NAME), ID_LOGIN_USER(idLoginUser) { //
        incomes = fileWithIncome.loadIncomesLoginUser(ID_LOGIN_USER);
        expenses = fileWithExpense.loadExpensesLoginUser(ID_LOGIN_USER);
    };

    void addIncome();
    void addExpense();
    void balanceSheetForThisMonth();
    //void balanceSheetForPreviousMonth();
    //void balanceSheetForThisMonth();
};

#endif
