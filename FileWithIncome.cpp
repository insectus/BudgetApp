#include "FileWithIncome.h"

int FileWithIncome::getLastIncomeId(){
    return lastIncomeId;
}

bool FileWithIncome::addNewIncomeToFile(Income income){
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
    xml.AddElem("incomeId", AuxilaryMethod::convertIntToString(income.getIncomeId()));
    xml.AddElem("userId", AuxilaryMethod::convertIntToString(income.getUserId()));
    xml.AddElem("date", income.getDate());
    xml.AddElem("item", income.getItem());
    xml.AddElem("amount", income.getAmount());

    xml.Save(getFileName());

    return true;
}
