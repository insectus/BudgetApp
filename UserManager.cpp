#include "UserManager.h"

void UserManager::registerUser() {
    User user = getNewUserData();

    users.push_back(user);

    fileWithUsers.addUserToFile(user);

    cout << "\nKonto zalozono pomyslnie!";
    Sleep(1000);
    cin.ignore();
}

User UserManager::getNewUserData() {
    User user;

    user.setUserId(getNewUserId());
    string login;
    do {
        cout << "\nPodaj login: ";
        cin >> login;
        user.setLogin(login);
    } while (loginExist(user.getLogin()) == true);

    string password;
    cout << "Podaj haslo: ";
    cin >> password;
    user.setPassword(password);

    string name;
    cout << "Podaj swoje imie: ";
    cin >> name;
    user.setName(name);

    string surname;
    cout << "Podaj swoje nazwisko: ";
    cin >> surname;
    user.setSurname(surname);

    return user;
}

int UserManager::getNewUserId() {
    if (users.empty() == true) {
        return 1;
    } else {
        return users.back().getUserId()+ 1;
    }
}

bool UserManager::loginExist(string login) {

    for (auto itr = users.begin(); itr != users.end(); itr++) {

        if(itr -> getLogin() == login) {
            cout << "\nIstnieje uzytkownik o takim loginie.\n";
            return true;
        }
    }
    return false;
}

int UserManager::loginUser() {
    string login = "", password = "";

    cout << "\nPodaj login: ";
    login = AuxilaryMethod::loadLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end()) {
        if (itr -> getLogin() == login) {
            for (int numberOfAttempt = 3; numberOfAttempt > 0; numberOfAttempt--) {
                cout << "Podaj haslo. Pozostalo prob: " << numberOfAttempt << ": ";
                password = AuxilaryMethod::loadLine();

                if (itr -> getPassword() == password) {
                    cout << endl << "Zalogowales sie! Przechodze do Menu Uzytkownika.";
                    Sleep(1500);
                    idLoginUser = itr -> getUserId();
                    return idLoginUser;

                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            idLoginUser = 0;
            return idLoginUser;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    idLoginUser = 0;
    return idLoginUser;
}

void UserManager::logoutUser() {
    idLoginUser = 0;
}

int UserManager::getLoginUserId() {
    return idLoginUser;
}

void UserManager::changeLoginUserPassword() {
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    newPassword = AuxilaryMethod::loadLine();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
        if (itr -> getUserId() == idLoginUser) {
            itr -> setPassword(newPassword);
            cout << "Haslo zostalo zmienione.\n\n";
            system("pause");
        }
    }
    fileWithUsers.changeLoginUserPassword(idLoginUser, newPassword);
}

bool UserManager::isUserLogin() {
    if(idLoginUser > 0) {
        return true;
    } else {
        return false;
    }
}
