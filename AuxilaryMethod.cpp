#include "AuxilaryMethod.h"

char AuxilaryMethod::loadChar() {
    string input = "";
    char sign  = {0};
    while (true) {
        getline(cin, input);

        if (input.length() == 1) {
            sign = input[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return sign;
}

string AuxilaryMethod::convertIntToString(int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string AuxilaryMethod::loadLine() {
    string input = "";
    getline(cin, input);
    return input;
}

bool AuxilaryMethod::amountValidation(string amount) {

    bool penny = false, notDigit = true;
    int numberOfPenny = 0;

    for (int i = 0; i < amount.size(); i++) {
        if (amount[i] == '.' || amount[i] == ',' ) {
            penny = true;
        }
        if(penny) {
            numberOfPenny++;
        }
        if(amount[i] == '.' || amount[i] == ',') {
            continue;
        } else if(isdigit(amount[i])) {
            notDigit = false;
        } else {
            notDigit = true;
            break;
        }
    }

    if (notDigit) {
        cout << "Zly format kwoty. Kwota musi zawierac cyfry i kropke jako separator liczby groszy \n";
        return false;
    } else if (!penny) {
        cout << "Zly format kwoty. Podaj liczbe groszy. \n";
        return false;
    } else if((1 == numberOfPenny)|| (numberOfPenny == 2)) {
        cout << "Zly format kwoty. Podaj kwote z dokladnoscia do jednego grosza. \n";
        return false;
    } else if(numberOfPenny > 3) {
        cout << "Zly format kwoty. Liczba groszy jest niewlasciwa. \n";
        return false;
    } else {
        return true;
    }
}

string AuxilaryMethod::convertComaToDotInAmount(string amount) {

    for (int i = 0; i < amount.size(); i++) {
        if(amount[i] == ',' ) {
            amount[i] = '.';
        }
    }
    return amount;
}
