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
    //sprawdz czy uzytkownik jest zalogowany
    budgetManager = new BudgetManager(INCOME_FILE_NAME, userManager.getLoginUserId());
}

void BudgetApp::changeLoginUserPassword() {
    //sprawdz czy uzytkownik jest zalogowany
    userManager.changeLoginUserPassword();

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
    //sprawdz czy uzytkownik jest zalogowany
    budgetManager->addIncome();
}
void BudgetApp::addExpense() {
    //sprawdz czy uzytkownik jest zalogowany
    //
}
void BudgetApp::balanceSheetForThisMonth() {
    //sprawdz czy uzytkownik jest zalogowany
    //
}
void BudgetApp::balanceSheetFromPreviousMonth() {
    //sprawdz czy uzytkownik jest zalogowany
    //
}
void BudgetApp::balanceSheetFromSelectedTimePeriode() {
    //sprawdz czy uzytkownik jest zalogowany
    //
}
