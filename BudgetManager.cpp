#include "BudgetManager.h"

/*
- zapytaj czy dotyczy on dnia dzisiejszego, czy jednak chce doda� z inn� dat�.
- Je�li wybierze dzie� dzisiejszy to pobierz z systemu dzisiejsz� dat� i skorzystaj z niej.
- Je�li wybierze inn� dat� to popro� o wpisanie daty w formacie rrrr-mm-dd np. 2017-11-01.
- Nast�pnie sprawd� czy wpisa� poprawn� dat�.
Zak�adamy, �e data musi mie�ci� si� w przedziale od roku 2000-01-01
do maksymalnie ostatniego dnia bie��cego miesi�ca.
- Nast�pnie popro� o wpisanie czego dotyczy ten przych�d (np. wyp�ata, odsetki itxd.).
- Kolejno zapytaj o okre�lenie wysoko�ci przychodu.
Kwoty u�amkowe zapisuj z kropk�, je�li kto� wpisze u�amek z przecinkiem,
to zamie� przecinek na kropk�.

*/
void BudgetManager::addIncome(){
    system("cls");
    cout << " >>> DODAJ NOWY PRZYCHOD <<<\n\n";
    Income income = addNewIncome();

    incomes.push_back(income);

    //fileWithIncome.addNewIncomeToFile(income);
}

Income BudgetManager::addNewIncome() {

    Income income;
    char dateSelection;

    income.setIncomeId(fileWithIncome.getLaseIncomeId()+1);
    income.setUserId(ID_LOGIN_USER);

    cout << "Czy przychow dotyczy:\n1. Dnia dzisiejszego\n2. Innego dnia\nTwoj wybor: ";

    //data
    while(true) {
        dateSelection = DateOperation::getCurrentDate();
        switch(dateSelection) {
        case '1':
            //
            break;
        case '2':
            //
            break;
        default:
            cout << "\nNie ma takiej opcji w menu.\n\n";
            system("pause");
            break;
        }
    }
    //typ przychodu
    //kwota
    //adresat.ustawImie(MetodyPomocnicze::wczytajLinie());
    //adresat.ustawImie(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzImie()));

    return income;
}
