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
    cout << "1. Dodaj przychow" << endl;
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
}
void BudgetApp::addIncome() {
    //
}
void BudgetApp::addExpense() {
    //
}
void BudgetApp::balanceSheetForThisMonth() {
    //
}
void BudgetApp::balanceSheetFromPreviousMonth() {
    //
}
void BudgetApp::balanceSheetFromSelectedTimePeriode() {
    //
}
void BudgetApp::changePassword() {
    //
}
void BudgetApp::logoutUser() {
    userManager.logoutUser();
}

int BudgetApp::getLoginUserId(){
    return userManager.getLoginUserId();
}
