#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "AuxilaryMethod.h"
#include "User.h"

using namespace std;

class UserManager {

    vector <User> users;

    User getNewUserData();
    int getNewUserId();
    bool loginExist(string login);

public:
    void registerUser();
};

#endif
