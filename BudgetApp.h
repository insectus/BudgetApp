#ifndef BUDGETAPP_H
#define BUDGETAPP_H

#include <iostream>

#include "BudgetManager.h"
#include "UserManager.h"

using namespace std;

class BudgetApp {
    UserManager userManager;
    BudgetManager *budgetManager;

    const string INCOME_FILE_NAME;
    const string EXPENSE_FILE_NAME;

public:
    BudgetApp(string USER_FILE_NAME, string incomeFileName, string expenseFileName)
        : userManager(USER_FILE_NAME), INCOME_FILE_NAME(incomeFileName), EXPENSE_FILE_NAME(expenseFileName) {
        budgetManager = NULL;
    };

    ~BudgetApp() {
        delete budgetManager;
        budgetManager = NULL;
    };

    char selectOptionFromMainMenu();
    char selectOptionFromUserMenu();
    void registerUser();
    void loginUser();
    void addIncome();
    void addExpense();
    void balanceSheetForThisMonth();
    void balanceSheetFromPreviousMonth();
    void balanceSheetFromSelectedTimePeriode();
    void changeLoginUserPassword();
    void logoutUser();
    int getLoginUserId();

};

#endif
