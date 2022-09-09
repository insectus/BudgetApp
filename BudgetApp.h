#ifndef BUDGETAPP_H
#define BUDGETAPP_H

#include <iostream>
#include "BudgetManager.h"
#include "UserManager.h"

using namespace std;

class BudgetApp {
    UserManager userManager;

public:
    BudgetApp(string USER_FILE_NAME) : userManager(USER_FILE_NAME) {};

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
