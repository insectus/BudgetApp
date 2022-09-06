#include "FileWithUsers.h"

void FileWithUsers::addUserToFile(User user) {

    CMarkup xml;

    //bool fileExistsUsers = xml.Load( getFileName());

    if (!XmlFile::isFileEmpty()) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\"?>\r\n");
        xml.AddElem("Users");
    }else if (XmlFile::isFileEmpty()) {
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
