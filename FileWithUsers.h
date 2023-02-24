#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>

#include "User.h"
#include "Markup.h"
#include "AuxiliaryMethods.h"

using namespace std;

class FileWithUsers
{
    const string FILENAME;

public:
    FileWithUsers(string usersFilename) : FILENAME(usersFilename) {};

    vector <User> loadUsersFromFile();
    void addUserToFile(User user);
    void saveAllUsersToFile(vector <User> &users);

};

#endif
