#include "UserManager.h"

void UserManager::registerUser() {
    User user = getNewUserData();

    users.push_back(user);

    //plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

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

    return user;
}
int UserManager::getNewUserId() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId()+ 1;
}
bool UserManager::loginExist(string login) {

    for (long long unsigned int i = 0; i < users.size(); i++) {

        if(users[i].getLogin() == login) {
            cout << "\nIstnieje uzytkownik o takim loginie.\n";
            return true;
        }
    }
    return false;
}
