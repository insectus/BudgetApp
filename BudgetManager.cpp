#include "BudgetManager.h"

/*
- zapytaj czy dotyczy on dnia dzisiejszego, czy jednak chce dodaæ z inn¹ dat¹.
- Jeœli wybierze dzieñ dzisiejszy to pobierz z systemu dzisiejsz¹ datê i skorzystaj z niej.
- Jeœli wybierze inn¹ datê to poproœ o wpisanie daty w formacie rrrr-mm-dd np. 2017-11-01.
- Nastêpnie sprawdŸ czy wpisa³ poprawn¹ datê.
Zak³adamy, ¿e data musi mieœciæ siê w przedziale od roku 2000-01-01
do maksymalnie ostatniego dnia bie¿¹cego miesi¹ca.
- Nastêpnie poproœ o wpisanie czego dotyczy ten przychód (np. wyp³ata, odsetki itxd.).
- Kolejno zapytaj o okreœlenie wysokoœci przychodu.
Kwoty u³amkowe zapisuj z kropk¹, jeœli ktoœ wpisze u³amek z przecinkiem,
to zamieñ przecinek na kropkê.

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
