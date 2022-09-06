#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "AuxilaryMethod.h"
#include "User.h"
#include "FileWithUsers.h"

using namespace std;

class UserManager {

    vector <User> users;

    User getNewUserData();
    int getNewUserId();
    bool loginExist(string login);
    FileWithUsers fileWithUsers;

public:
    UserManager(string USER_FILE_NAME) : fileWithUsers(USER_FILE_NAME){};

    void registerUser();
};

#endif
