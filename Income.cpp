#include "Income.h"

void Income::setIncomeId(int newIncomeId) {
    if(newIncomeId >= 0) {
        newIncomeId = incomeId;
    }
}
void Income::setUserId(int newUserId) {
    if(newUserId >= 0) {
        newUserId = userId;
    }
}
void Income::setDate(string newDate) {
    newDate = date;
}
void Income::setItem(string newItem) {
    newItem = item;
}
void Income::setAmount(string newAmount) {
    newAmount = amount;
}

int Income::getIncomeId() {
    return incomeId;
}
int Income::getUserId() {
    return userId;
}
string Income::getDate() {
    return date;
}
string Income::getItem() {
    return item;
}
string Income::getAmount() {
    return amount;
}
