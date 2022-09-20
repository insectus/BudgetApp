#include "FileWithExpense.h"

int FileWithExpense::getLastExpenseId() {
    return lastExpenseId;
}

bool FileWithExpense::addNewExpenseToFile(Expense expense) {
    CMarkup xml;

    if (!XmlFile::isFileEmpty()) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\"?>\r\n");
        xml.AddElem("Expenses");
    } else if (XmlFile::isFileEmpty()) {
        xml.Load(getFileName());
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("userId", AuxilaryMethod::convertIntToString(expense.getUserId()));
    xml.AddElem("expenseId", AuxilaryMethod::convertIntToString(expense.getExpenseId()));
    xml.AddElem("date", dateOperation.convertDateFromIntToString(expense.getDate()));
    xml.AddElem("item", expense.getItem());
    xml.AddElem("amount", expense.getAmount());

    lastExpenseId++;

    xml.Save(getFileName());

    cout << "\nPrzychod dodany. Powrot do menu glownego.";
    Sleep(1000);

    return true;
}

vector <Expense> FileWithExpense::loadExpensesLoginUser(int idLoginUser) {
    CMarkup xml;
    Expense expense;
    vector <Expense> expenses;

    xml.Load(getFileName());
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    while(xml.FindElem("Expense")) {
        xml.IntoElem();
        xml.FindElem( "userId" );
        if( stoi(xml.GetData()) == idLoginUser) {
            expense.setUserId(idLoginUser);
            xml.FindElem( "expenseId" );
            expense.setExpenseId(stoi(xml.GetData()));
            xml.FindElem( "date" );
            expense.setDate(dateOperation.getDateAsInt(xml.GetData()));
            xml.FindElem( "item" );
            expense.setItem(xml.GetData());
            xml.FindElem( "amount" );
            expense.setAmount(xml.GetData());
            expenses.push_back(expense);
        }
        xml.OutOfElem();
    }
    lastExpenseId = expense.getExpenseId();

    return expenses;
}
