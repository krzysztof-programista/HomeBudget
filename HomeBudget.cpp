#include "HomeBudget.h"

using namespace std;

bool HomeBudget::isUserLoggedIn()
{
    return userManager.isUserLoggedIn();
}

void HomeBudget::registerUser()
{
    userManager.registerUser();
}

void HomeBudget::loginUser()
{
    userManager.loginUser();
    if (userManager.isUserLoggedIn())
    {
        financialManager = new FinancialManager(INCOMES_FILENAME, EXPENSES_FILENAME, userManager.getLoggedInUserId());
    }
}

void HomeBudget::addIncome()
{
    if (userManager.isUserLoggedIn())
    {
        financialManager->addIncome();
    }
    else
    {
        cout << "Aby dodac przychod, nalezy najpier sie zalogowac" << endl;
        system("pause");
    }
}

void HomeBudget::addExpense()
{
    if (userManager.isUserLoggedIn())
    {
        financialManager->addExpense();
    }
    else
    {
        cout << "Aby dodac wydatek, nalezy najpier sie zalogowac" << endl;
        system("pause");
    }
}

void HomeBudget::balanceForCurrentMonth()
{
    if (userManager.isUserLoggedIn())
    {
        financialManager->balanceForCurrentMonth();
    }
    else
    {
        cout << "Aby wyswietlic bilans, nalezy najpier sie zalogowac" << endl;
        system("pause");
    }
}

void HomeBudget::balanceForPreviousMonth()
{
    if (userManager.isUserLoggedIn())
    {
        financialManager->balanceForPreviousMonth();
    }
    else
    {
        cout << "Aby wyswietlic bilans, nalezy najpier sie zalogowac" << endl;
        system("pause");
    }
}

void HomeBudget::balanceForSelectedDates()
{
    if (userManager.isUserLoggedIn())
    {
        financialManager->balanceForSelectedDates();
    }
    else
    {
        cout << "Aby wyswietlic bilans, nalezy najpier sie zalogowac" << endl;
        system("pause");
    }
}


char HomeBudget::selectOptionsFromTheMainMenu()
{
    char choice;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods::loadChar();

    return choice;
}
char HomeBudget::selectOptionsFromUserMenu()
{
    return userManager.selectOptionsFromUserMenu();
}

void HomeBudget::logoutUser()
{
    userManager.logoutUser();
}

void HomeBudget::changePassword()
{
    userManager.changePassword();
}
