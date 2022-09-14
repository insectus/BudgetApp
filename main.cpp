#include <iostream>

#include "BudgetApp.h"

using namespace std;

int main() {
    BudgetApp budgetApp("users.xml", "income.xml", "expene.xml");

    char select;
    while(true) {
        if(budgetApp.getLoginUserId()==0) {
            select = budgetApp.selectOptionFromMainMenu();

            switch(select) {
            case '1':
                budgetApp.registerUser();
                break;
            case '2':
                budgetApp.loginUser();

                break;
            case '9':
                exit(0);
            default:
                cout << "\nNie ma takiej opcji w menu.\n\n";
                system("pause");
                break;
            }
        } else {
            select = budgetApp.selectOptionFromUserMenu();

            switch(select) {
            case '1':
                budgetApp.addIncome();
                break;
            case '2':
                // budgetApp.addExpense();
                break;
            case '3':
                //budgetApp.balanceSheetForThisMonth();
                break;
            case '4':
                // budgetApp.balanceSheetFromPreviousMonth();
                break;
            case '5':
                //budgetApp.balanceSheetFromSelectedTimePeriode();
                break;
            case '6':
                budgetApp.changeLoginUserPassword();
                break;
            case '7':
                budgetApp.logoutUser();
                break;
            }
        }
    }
    return 0;
}


//TEST Add Income
#include "BudgetManager.h"
#include "FileWithIncome.h"
#include "DateOperation.h"

int _main() {
    //BudgetManager budgetManager("income.xml", "expense.xml", 2);
    //budgetManager.addIncome();
    FileWithIncome fileWithIncome("income.xml");
    fileWithIncome.loadIncomesLoginUser(1);
    return 0;
}


