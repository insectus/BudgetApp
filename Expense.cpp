#include "Expense.h"

void Expense::setExpenseId(int newExpenseId) {
    if(newExpenseId >= 0) {
        newExpenseId = expenseId;
    }
}
void Expense::setUserId(int newUserId) {
    if(newUserId >= 0) {
        newUserId = userId;
    }
}
void Expense::setDate(string newDate) {
    newDate = date;
}
void Expense::setItem(string newItem) {
    newItem = item;
}
void Expense::setAmount(string newAmount) {
    newAmount = amount;
}

int Expense::getExpenseId() {
    return expenseId;
}
int Expense::getUserId() {
    return userId;
}
string Expense::getDate() {
    return date;
}
string Expense::getItem() {
    return item;
}
string Expense::getAmount() {
    return amount;
}
