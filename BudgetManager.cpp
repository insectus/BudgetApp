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

void BudgetManager::balanceSheetForThisMonth() {

    int startBalansDate = stoi(dateOperation.getCurrentYear() + dateOperation.getCurrentMont() + "01");
    int stopBalansDate = stoi(dateOperation.getCurrentYear() + dateOperation.getCurrentMont() + AuxilaryMethod::convertIntToString(dateOperation.getNumberOfDays()));
    incomeSum = incomeSorting(startBalansDate, stopBalansDate);
    expenseSum = expenseSorting(startBalansDate, stopBalansDate);

    balance = incomeSum - expenseSum;

    cout << "\t<<<BILANS>>>\n";
    cout << "\nBilans z obecnego miesiaca to: " << setprecision(2) << fixed << balance <<  "zl" << endl << endl;
    system ("pause");
}

bool compareIncome(Income date1, Income date2) {
    return (date1.getDate() < date2.getDate());
}

float BudgetManager::incomeSorting(int startDate, int stopDate) {

    Income income;
    incomeSum = 0;

    for (vector <Income>::iterator itr = incomes.begin(); itr != incomes.end(); itr++) {
        if ((itr -> getUserId() == ID_LOGIN_USER)&&(itr -> getDate() >= startDate) &&(itr -> getDate() <= stopDate)) {
            income.setDate(itr -> getDate());
            income.setItem(itr -> getItem());
            income.setAmount(itr -> getAmount());
            incomeSum += stof(itr -> getAmount());
            curentTimeIncomes.push_back(income);
        }
    }

    if(curentTimeIncomes.empty()) {
        cout << "\t<<<PRZYCHODY>>>\n\n";
        cout << "Brak przychodow za wybrany okres czasu.\n\n";
    } else {
        sort(curentTimeIncomes.begin(), curentTimeIncomes.end(), compareIncome);

        cout << "\t<<<PRZYCHODY>>>\n\n";
        for (vector <Income>::iterator itr = curentTimeIncomes.begin(); itr != curentTimeIncomes.end(); itr++) {
            cout << "Dnia: " << dateOperation.convertDateFromIntToString(itr -> getDate());
            cout << "\nWplynela z tytulu: " << itr -> getItem();
            cout << "\nkwota w wysokosci: " << itr -> getAmount() << endl << endl;
        }
    }

    curentTimeIncomes.clear();
    return incomeSum;
}

bool compareExpense(Expense date1, Expense date2) {
    return (date1.getDate() < date2.getDate());
}

float BudgetManager::expenseSorting(int startDate, int stopDate) {

    Expense expense;
    expenseSum = 0;

    int i = 0;

    for (vector <Expense>::iterator itr = expenses.begin(); itr != expenses.end(); itr++) {
        if ((itr -> getUserId() == ID_LOGIN_USER)&&(itr -> getDate() >= startDate) &&(itr -> getDate() <= stopDate)) {
            expense.setDate(itr -> getDate());
            expense.setItem(itr -> getItem());
            expense.setAmount(itr -> getAmount());
            expenseSum += stof(itr -> getAmount());
            curentTimeExpense.push_back(expense);
            i++;
        }
    }

    if(curentTimeExpense.empty()) {
        cout << "\t<<<WYDATKI>>>\n\n";
        cout << "Brak wydatkow za wybrany okres czasu.\n\n";
    } else {

        sort(curentTimeExpense.begin(), curentTimeExpense.end(), compareExpense);

        cout << "\t<<<WYDATKI>>>\n\n";
        for (vector <Expense>::iterator itr = curentTimeExpense.begin(); itr != curentTimeExpense.end(); itr++) {
            cout << "Dnia: " << dateOperation.convertDateFromIntToString(itr -> getDate());
            cout << "\nWyplacono z tytulu: " << itr -> getItem();
            cout << "\nkwote w wysokosci: " << itr -> getAmount() << endl << endl;
        }
    }
    curentTimeExpense.clear();
    return expenseSum;
}

void BudgetManager::balanceSheetForPreviousMonth() {

    int startBalansDate = stoi(dateOperation.getPriviousMonth() + "01");
    int stopBalansDate = stoi(dateOperation.getPriviousMonth() + dateOperation.getNumberDaysPraviousMonth());
    incomeSum = incomeSorting(startBalansDate, stopBalansDate);
    expenseSum = expenseSorting(startBalansDate, stopBalansDate);

    balance = incomeSum - expenseSum;

    cout << "\t<<<BILANS>>>\n";
    cout << "\nBilans z poprzedniego miesiaca to: " << setprecision(2) << fixed << balance <<  "zl" << endl << endl;
    system ("pause");
}

void BudgetManager::balanceSheetFromSelectedTimePeriode() {

    int startBalansDate, stopBalansDate;
    string startBalansDateString, stopBalansDateString;

    cout << "Podaj date poczatku bilansu w formacie rrrr-mm-dd: ";
    startBalansDateString = AuxilaryMethod::loadLine();
    while(!dateOperation.dateValidation(startBalansDateString)) {
        cout << "Podaj date poczatku bilansu w formacie rrrr-mm-dd: ";
        startBalansDateString = AuxilaryMethod::loadLine();
    }
    startBalansDate = dateOperation.getDateAsInt(startBalansDateString);

    cout << "Podaj date konca bilansu w formacie rrrr-mm-dd: ";
    stopBalansDateString = AuxilaryMethod::loadLine();
    while(!dateOperation.dateValidation(stopBalansDateString)) {
        cout << "Podaj date poczatku bilansu w formacie rrrr-mm-dd: ";
        stopBalansDateString = AuxilaryMethod::loadLine();
    }
    stopBalansDate = dateOperation.getDateAsInt(stopBalansDateString);

    if(startBalansDate > stopBalansDate) {

        cout << "\nData konca bilansu nie moze byc wczesniejsza od daty poczatku bilansu!\n";
        system ("pause");
    } else {

        incomeSum = incomeSorting(startBalansDate, stopBalansDate);
        expenseSum = expenseSorting(startBalansDate, stopBalansDate);

        balance = incomeSum - expenseSum;

        cout << "\t<<<BILANS>>>\n";
        cout << "\nBilans z wybranego przedzialu czasu to: " << setprecision(2) << fixed << balance <<  "zl" << endl << endl;
        system ("pause");

    }
}

