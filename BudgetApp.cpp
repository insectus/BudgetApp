#include "BudgetApp.h"

char BudgetApp::selectOptionFromMainMenu() {
    char select;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    select = AuxilaryMethod::loadChar();

    return select;
}
char BudgetApp::selectOptionFromUserMenu() {
    char select;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z obecnego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego przedzialu czasowego" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    select = AuxilaryMethod::loadChar();

    return select;
}
void BudgetApp::registerUser() {
    userManager.registerUser();
}

void BudgetApp::loginUser() {
    userManager.loginUser();
    if (userManager.isUserLogin()) {
        budgetManager = new BudgetManager(INCOME_FILE_NAME, EXPENSE_FILE_NAME, userManager.getLoginUserId());
    } else {
        cout << "Aby zmienic haslo uzytkownika nalezy najpierw sie zalogowac\n.";
        Sleep(1500);
    }
}

void BudgetApp::changeLoginUserPassword() {
    if (userManager.isUserLogin()) {
        userManager.changeLoginUserPassword();
    } else {
        cout << "Aby zmienic haslo uzytkownika nalezy najpierw sie zalogowac\n.";
        Sleep(1500);
    }
}

void BudgetApp::logoutUser() {
    userManager.logoutUser();
    delete budgetManager;
    budgetManager = NULL;

}

int BudgetApp::getLoginUserId() {
    return userManager.getLoginUserId();
}

void BudgetApp::addIncome() {
    if (userManager.isUserLogin()) {
        budgetManager->addIncome();
    } else {
        cout << "Aby zmienic haslo uzytkownika nalezy najpierw sie zalogowac\n.";
        Sleep(1500);
    }
}

void BudgetApp::addExpense() {
    if (userManager.isUserLogin()) {
        //
    } else {
        cout << "Aby zmienic haslo uzytkownika nalezy najpierw sie zalogowac\n.";
        Sleep(1500);
    }
}
void BudgetApp::balanceSheetForThisMonth() {
    if (userManager.isUserLogin()) {
        //
    } else {
        cout << "Aby zmienic haslo uzytkownika nalezy najpierw sie zalogowac\n.";
        Sleep(1500);
    }
}
void BudgetApp::balanceSheetFromPreviousMonth() {
    if (userManager.isUserLogin()) {
        //
    } else {
        cout << "Aby zmienic haslo uzytkownika nalezy najpierw sie zalogowac\n.";
        Sleep(1500);
    }
}
void BudgetApp::balanceSheetFromSelectedTimePeriode() {
    if (userManager.isUserLogin()) {
        //
    } else {
        cout << "Aby zmienic haslo uzytkownika nalezy najpierw sie zalogowac\n.";
        Sleep(1500);
    }
}
