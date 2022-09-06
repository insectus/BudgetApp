#ifndef BUDGETAPP_H
#define BUDGETAPP_H

#include <iostream>
#include "BudgetManager.h"
#include "UserManager.h"

using namespace std;

class BudgetApp {
    UserManager userManager;

public:

    char selectOptionFromMainMenu();
    char selectOptionFromUserMenu();
    void registerUser();
    void loginUser();
    void addIncome();
    void addExpense();
    void balanceSheetForThisMonth();
    void balanceSheetFromPreviousMonth();
    void balanceSheetFromSelectedTimePeriode();
    void changePassword();
    void logoutUser();

};

#endif
