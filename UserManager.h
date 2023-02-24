#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>

#include "User.h"
#include "FileWithUsers.h"

using namespace std;

class UserManager
{
    int loggedInUserId;

    vector <User> users;

    FileWithUsers fileWithUsers;

    User enterNewUserData();
    int getNewUserId();
    bool loginExists(string login);

public:
    UserManager(string usersFilename) : fileWithUsers(usersFilename)
    {
        loggedInUserId = 0;
        users = fileWithUsers.loadUsersFromFile();
    };

    bool isUserLoggedIn();
    void registerUser();
    int loginUser();
    int getLoggedInUserId();
    void changePassword();
    void logoutUser();

    char selectOptionsFromUserMenu();
};

#endif
