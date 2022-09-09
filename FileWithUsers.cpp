#include "FileWithUsers.h"

void FileWithUsers::addUserToFile(User user) {

    CMarkup xml;

    if (!XmlFile::isFileEmpty()) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\"?>\r\n");
        xml.AddElem("Users");
    } else if (XmlFile::isFileEmpty()) {
        xml.Load(getFileName());
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("userId", AuxilaryMethod::convertIntToString(user.getUserId()));
    xml.AddElem("login", user.getLogin());
    xml.AddElem("password", user.getPassword());
    xml.AddElem("name", user.getName());
    xml.AddElem("surname", user.getSurname());

    xml.Save(getFileName());
}
vector <User> FileWithUsers::loadUsersFromFile() {

    User user;
    vector <User> users;
    CMarkup xml;

    if (xml.Load(getFileName())) {
        xml.ResetPos();
        xml.FindElem();
        xml.IntoElem();
        while(xml.FindElem("User")) {
            xml.IntoElem();
            xml.FindElem( "userId" );
            user.setUserId(atoi(MCD_2PCSZ(xml.GetData())));
            xml.FindElem( "login" );
            user.setLogin(xml.GetData());
            xml.FindElem( "password" );
            user.setPassword(xml.GetData());
            xml.FindElem( "name" );
            user.setName(xml.GetData());
            xml.FindElem( "surname" );
            user.setSurname(xml.GetData());
            xml.OutOfElem();
            users.push_back(user);
        }
    } else {
        cout << "Nie udalo sie otworzyc pliku" ;
    }
    return users;
}

void FileWithUsers::changeLoginUserPassword(int idLoginUser, string newPassword) {
    CMarkup xml;

    if(xml.Load(getFileName())) {
        xml.ResetPos();
        xml.FindElem();
        xml.IntoElem();
        while(xml.FindElem("User")) {
            xml.IntoElem();
            if(xml.FindElem( "userId" ) && (stoi(xml.GetData()) == idLoginUser)) {
                xml.FindElem( "password" );
                xml.RemoveElem();
                xml.AddElem("password", newPassword);
                xml.Save("users.xml");
            }
            xml.OutOfElem();
        }
    }
}
