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
