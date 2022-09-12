#ifndef AUXILARYMETHOD_H
#define AUXILARYMETHOD_H

#include <iostream>
#include <sstream>

using namespace std;

class AuxilaryMethod {

public:

    static char loadChar();
    static string convertIntToString(int number);
    static string loadLine();
    static bool amountValidation(string amount);
    static string convertComaToDotInAmount(string amount);
};

#endif
