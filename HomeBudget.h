#ifndef HOMEBUDGET_H
#define HOMEBUDGET_H

#include <iostream>

#include "UserManager.h"
#include "FinancialManager.h"
#include "AuxiliaryMethods.h"

using namespace std;

class HomeBudget
{
    UserManager userManager;
    FinancialManager *financialManager;

    const string INCOMES_FILENAME;
    const string EXPENSES_FILENAME;

public:
    HomeBudget(string usersFilename, string incomesFilename, string expensesFilename)
    : userManager(usersFilename), INCOMES_FILENAME(incomesFilename), EXPENSES_FILENAME(expensesFilename)
    {
        financialManager = NULL;
    };
    ~HomeBudget()
    {
        delete financialManager;
        financialManager = NULL;
    };

    bool isUserLoggedIn();
    void registerUser();
    void loginUser();

    void addIncome();
    void addExpense();
    void balanceForCurrentMonth();
    void balanceForPreviousMonth();
    void balanceForSelectedDates();
    void changePassword();
    void logoutUser();

    char selectOptionsFromTheMainMenu();
    char selectOptionsFromUserMenu();
};

#endif
