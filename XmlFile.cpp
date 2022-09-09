#include "XmlFile.h"

bool XmlFile::isFileEmpty(){

    CMarkup xml;

    bool fileExistsUsers = xml.Load(FILE_NAME);

    return fileExistsUsers;
}

string XmlFile::getFileName(){
    return FILE_NAME;
}
