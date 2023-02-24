#include "FileWithUsers.h"

using namespace std;

vector <User> FileWithUsers::loadUsersFromFile()
{
    User user;
    vector <User> users;
    CMarkup file;

    bool fileExists = file.Load(FILENAME);

    if (fileExists)
    {
        file.FindElem();
        file.IntoElem();

        while ( file.FindElem("User") )
        {
            file.IntoElem();
            file.FindElem( "UserId" );
            user.setUserId(AuxiliaryMethods::convertStringToInteger(file.GetData()));
            file.FindElem( "Name" );
            user.setName(file.GetData());
            file.FindElem( "Surname" );
            user.setSurname(file.GetData());
            file.FindElem( "Login" );
            user.setLogin(file.GetData());
            file.FindElem( "Password" );
            user.setPassword(file.GetData());

            file.OutOfElem();
            users.push_back(user);
        }
    }

    return users;
}

void FileWithUsers::addUserToFile(User user)
{
    CMarkup file;

    bool fileExists = file.Load(FILENAME);

    if (!fileExists)
    {
        file.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        file.AddElem("Users");
    }

    file.FindElem();
    file.IntoElem();
    file.AddElem("User");
    file.IntoElem();
    file.AddElem("UserId", AuxiliaryMethods::convertIntegerToString(user.getUserId()));
    file.AddElem("Name", user.getName());
    file.AddElem("Surname", user.getSurname());
    file.AddElem("Login", user.getLogin());
    file.AddElem("Password", user.getPassword());
    file.Save(FILENAME);
}

void FileWithUsers::saveAllUsersToFile(vector <User> &users)
{
    CMarkup file;

    bool fileExists = file.Load(FILENAME);

    if (fileExists)
    {
        file.FindElem();
        file.IntoElem();
        while (file.FindElem())
        {
            file.RemoveElem();
        }
        file.Save(FILENAME);
    }
    else
    {
        file.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        file.AddElem("Users");
    }

    file.FindElem();
    file.IntoElem();

    for (unsigned int i = 0; i < users.size(); i++)
    {
        file.AddElem("User");
        file.IntoElem();
        file.AddElem("UserId", AuxiliaryMethods::convertIntegerToString(users[i].getUserId()));
        file.AddElem("Name", users[i].getName());
        file.AddElem("Surname", users[i].getSurname());
        file.AddElem("Login", users[i].getLogin());
        file.AddElem("Password", users[i].getPassword());
        file.OutOfElem();
    }

    file.Save(FILENAME);
}

