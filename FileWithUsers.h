#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>
#include <stdlib.h>

#include "User.h"
#include "AuxilaryMethod.h"
#include "XmlFile.h"

using namespace std;

class FileWithUsers : public XmlFile {


public:
    FileWithUsers(string fileName) : XmlFile(fileName){};

    void addUserToFile(User user);
    vector <User> loadUsersFromFile();
};

#endif
