#include "FileWithIncome.h"

int FileWithIncome::getLastIncomeId() {
    return lastIncomeId;
}

bool FileWithIncome::addNewIncomeToFile(Income income) {
    CMarkup xml;

    if (!XmlFile::isFileEmpty()) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\"?>\r\n");
        xml.AddElem("Incomes");
    } else if (XmlFile::isFileEmpty()) {
        xml.Load(getFileName());
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("userId", AuxilaryMethod::convertIntToString(income.getUserId()));
    xml.AddElem("incomeId", AuxilaryMethod::convertIntToString(income.getIncomeId()));
    xml.AddElem("date", income.getDate());
    xml.AddElem("item", income.getItem());
    xml.AddElem("amount", income.getAmount());

    lastIncomeId++;

    xml.Save(getFileName());

    cout << "\nPrzychod dodany. Powrot do menu glownego.";
    Sleep(1000);

    return true;
}

vector <Income> FileWithIncome::loadIncomesLoginUser(int idLoginUser) {
    CMarkup xml;
    Income income;
    vector <Income> incomes;

    xml.Load(getFileName());
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    while(xml.FindElem("Income")) {
        xml.IntoElem();
        xml.FindElem( "userId" );
        if( stoi(xml.GetData()) == idLoginUser) {
            income.setUserId(idLoginUser);
            xml.FindElem( "incomeId" );
            income.setIncomeId(stoi(xml.GetData()));
            xml.FindElem( "date" );
            income.setDate(xml.GetData());
            xml.FindElem( "item" );
            income.setItem(xml.GetData());
            xml.FindElem( "amount" );
            income.setAmount(xml.GetData());
        }
        xml.OutOfElem();
        incomes.push_back(income);
    }
    lastIncomeId = income.getIncomeId();

    return incomes;
}
