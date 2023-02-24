#include "UserManager.h"

using namespace std;

bool UserManager::isUserLoggedIn()
{
    if (loggedInUserId > 0)
        return true;
    else
        return false;
}

void UserManager::registerUser()
{
    User user = enterNewUserData();

    users.push_back(user);

    fileWithUsers.addUserToFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

User UserManager::enterNewUserData()
{
    User user;
    string name, surname, login, password;

    user.setUserId(getNewUserId());

    cout << "Podaj imie: ";
    cin >> name;
    user.setName(name);

    cout << "Podaj nazwisko: ";
    cin >> surname;
    user.setSurname(surname);

    do
    {
        cout << "Podaj login: ";
        cin >> login;
        user.setLogin(login);
    }
    while (loginExists(user.getLogin()) == true);

    cout << "Podaj haslo: ";
    cin >> password;
    user.setPassword(password);

    return user;
}

int UserManager::getNewUserId()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId() + 1;
}

bool UserManager::loginExists(string login)
{
    for (unsigned int i = 0; i < users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

int UserManager::loginUser()
{
    User user;
    string login = "", password = "";

    cout << "Podaj login: ";
    login = AuxiliaryMethods::loadLine();


    for (unsigned int i = 0; i < users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
          for (int attemps = 3; attemps > 0; attemps--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << attemps << ": ";
                password = AuxiliaryMethods::loadLine();

                if (users[i].getPassword() == password)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    loggedInUserId = users[i].getUserId();
                    system("pause");
                    return loggedInUserId;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return 0;
        }
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return 0;
}

int UserManager::getLoggedInUserId()
{
    return loggedInUserId;
}

char UserManager::selectOptionsFromUserMenu()
{
    char choice;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods::loadChar();

    return choice;
}

void UserManager::logoutUser()
{
    loggedInUserId = 0;
}

void UserManager::changePassword()
{
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    newPassword = AuxiliaryMethods::loadLine();

    for (unsigned int i = 0; i < users.size(); i++)
    {
        if (users[i].getUserId() == loggedInUserId)
        {
            users[i].setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }

    fileWithUsers.saveAllUsersToFile(users);

}
