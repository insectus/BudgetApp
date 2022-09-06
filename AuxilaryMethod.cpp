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

string AuxilaryMethod::convertIntToString(int number){
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}
