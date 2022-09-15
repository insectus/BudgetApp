#include "BudgetManager.h"

void BudgetManager::addIncome() {
    system("cls");
    cout << " >>> DODAJ NOWY PRZYCHOD <<<\n\n";

    Income income = addNewIncome();

    incomes.push_back(income);

    fileWithIncome.addNewIncomeToFile(income);
}

Income BudgetManager::addNewIncome() {

    Income income;
    bool incorrectMenuSelestion = true;
    char dateSelection;
    string incomeDate, incomeAmount;
    income.setUserId(ID_LOGIN_USER);
    income.setIncomeId((fileWithIncome.getLastIncomeId()+1));

    cout << "Czy przychod dotyczy:\n\t1. Dnia dzisiejszego\n\t2. Innego dnia\n\nTwoj wybor: ";

    while(incorrectMenuSelestion) {
        dateSelection = AuxilaryMethod::loadChar();
        switch(dateSelection) {
        case '1':
            incomeDate = dateOperation.getCurrentYearMonthDayAsString();
            income.setDate(dateOperation.getDateAsInt(incomeDate));
            incorrectMenuSelestion = false;
            break;
        case '2':
            cout << "Podaj date w formacie rrrr-mm-dd: ";
            incomeDate = AuxilaryMethod::loadLine();
            while(!dateOperation.dateValidation(incomeDate)) {
                cout << "Podaj date w formacie rrrr-mm-dd: ";
                incomeDate = AuxilaryMethod::loadLine();
            }
            income.setDate(dateOperation.getDateAsInt(incomeDate));
            incorrectMenuSelestion = false;
            break;
        default:
            cout << "\nNie ma takiej opcji w menu.\n\n";
            system("pause");
            break;
        }
    }

    cout << "Podaj zrodlo przychodu: ";
    income.setItem(AuxilaryMethod::loadLine());

    cout << "Podaj kwote przychodu: ";
    incomeAmount = AuxilaryMethod::loadLine();
    while(!AuxilaryMethod::amountValidation(incomeAmount)) {
        cout << "Podaj kwote przychodu: ";
        incomeAmount = AuxilaryMethod::loadLine();
    }
    income.setAmount(AuxilaryMethod::convertComaToDotInAmount(incomeAmount));

    return income;
}

void BudgetManager::addExpense() {
    system("cls");
    cout << " >>> DODAJ NOWY WYDATEK <<<\n\n";

    Expense expense = addNewExpense();

    expenses.push_back(expense);

    fileWithExpense.addNewExpenseToFile(expense);
}

Expense BudgetManager::addNewExpense() {

    Expense expense;
    bool incorrectMenuSelestion = true;
    char dateSelection;
    string expenseDate, expenseAmount;
    expense.setUserId(ID_LOGIN_USER);
    expense.setExpenseId((fileWithExpense.getLastExpenseId()+1));

    cout << "Czy wydatek dotyczy:\n\t1. Dnia dzisiejszego\n\t2. Innego dnia\n\nTwoj wybor: ";

    while(incorrectMenuSelestion) {
        dateSelection = AuxilaryMethod::loadChar();
        switch(dateSelection) {
        case '1':
            expenseDate = dateOperation.getCurrentYearMonthDayAsString();
            expense.setDate(dateOperation.getDateAsInt(expenseDate));
            incorrectMenuSelestion = false;
            break;
        case '2':
            cout << "Podaj date w formacie rrrr-mm-dd: ";
            expenseDate = AuxilaryMethod::loadLine();
            while(!dateOperation.dateValidation(expenseDate)) {
                cout << "Podaj date w formacie rrrr-mm-dd: ";
                expenseDate = AuxilaryMethod::loadLine();
            }
            expense.setDate(dateOperation.getDateAsInt(expenseDate));
            incorrectMenuSelestion = false;
            break;
        default:
            cout << "\nNie ma takiej opcji w menu.\n\n";
            system("pause");
            break;
        }
    }

    cout << "Podaj zrodlo wydatku: ";
    expense.setItem(AuxilaryMethod::loadLine());

    cout << "Podaj kwote wydatku: ";
    expenseAmount = AuxilaryMethod::loadLine();
    while(!AuxilaryMethod::amountValidation(expenseAmount)) {
        cout << "Podaj kwote wydatku: ";
        expenseAmount = AuxilaryMethod::loadLine();
    }
    expense.setAmount(AuxilaryMethod::convertComaToDotInAmount(expenseAmount));

    return expense;
}
