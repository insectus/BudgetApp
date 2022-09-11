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
    string incomeDate, incomeItem, incomeAmount;
    income.setIncomeId((fileWithIncome.getLastIncomeId()+1));
    income.setUserId(ID_LOGIN_USER);

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
            income.setDate(AuxilaryMethod::loadLine()); // dodaj walidacje
            incorrectMenuSelestion = false;
            break;
        default:
            cout << "\nNie ma takiej opcji w menu.\n\n";
            system("pause");
            break;
        }
    }

    cout << "Podaj zrodlo przychodu: ";
    income.setItem(AuxilaryMethod::loadLine()); // dodaj walidacje

    cout << "Podaj kwote przychodu: ";
    income.setAmount(AuxilaryMethod::loadLine());// dodaj walidacje

    cout << "\nPrzychod dodany. Powrot do menu glownego...\n";
    //sleep("1000");
    cout << income.getIncomeId() << endl;
    cout << income.getUserId() << endl;
    cout << income.getDate() << endl;
    cout << income.getAmount() << endl;
    cout << income.getItem() << endl;
    system("pause");
    return income;
}

/*
- Jeœli wybierze inn¹ datê to poproœ o wpisanie daty w formacie rrrr-mm-dd np. 2017-11-01.
- Nastêpnie sprawdŸ czy wpisa³ poprawn¹ datê.
Zak³adamy, ¿e data musi mieœciæ siê w przedziale od roku 2000-01-01
do maksymalnie ostatniego dnia bie¿¹cego miesi¹ca.
- Kolejno zapytaj o okreœlenie wysokoœci przychodu.
Kwoty u³amkowe zapisuj z kropk¹, jeœli ktoœ wpisze u³amek z przecinkiem,
to zamieñ przecinek na kropkê.

*/
