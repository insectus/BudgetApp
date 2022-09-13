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
            income.setDate(dateOperation.getCurrentYearMonthDayAsString());
            incorrectMenuSelestion = false;
            break;
        case '2':
            cout << "Podaj date w formacie rrrr-mm-dd: ";
            incomeDate = AuxilaryMethod::loadLine();
            while(!dateOperation.dateValidation(incomeDate)){
                cout << "Podaj date w formacie rrrr-mm-dd: ";
                incomeDate = AuxilaryMethod::loadLine();
            }
            income.setDate(incomeDate); // dodaj walidacje
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

/*
- Nastêpnie sprawdŸ czy wpisa³ poprawn¹ datê.
Zak³adamy, ¿e data musi mieœciæ siê w przedziale od roku 2000-01-01
do maksymalnie ostatniego dnia bie¿¹cego miesi¹ca.
*/
