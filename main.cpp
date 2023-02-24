#include <iostream>

#include "HomeBudget.h"

using namespace std;

int main()
{
    char choice;

    HomeBudget homeBudget("users.xml", "incomes.xml", "expenses.xml");

    while (true)
        {
            if (homeBudget.isUserLoggedIn() == false)
            {
                choice = homeBudget.selectOptionsFromTheMainMenu();

                switch (choice)
                {
                case '1':
                    homeBudget.registerUser();
                    break;
                case '2':
                    homeBudget.loginUser();
                    break;
                case '9':
                    exit(0);
                    break;
                default:
                    cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                    system("pause");
                    break;
                }
            }
            else
            {
                choice = homeBudget.selectOptionsFromUserMenu();

                switch (choice)
                {
                case '1':
                    homeBudget.addIncome();
                    break;
                case '2':
                    homeBudget.addExpense();
                    break;
                case '3':
                    homeBudget.balanceForCurrentMonth();
                    break;
                case '4':
                    homeBudget.balanceForPreviousMonth();
                    break;
                case '5':
                    homeBudget.balanceForSelectedDates();
                    break;
                case '6':
                    homeBudget.changePassword();
                    break;
                case '7':
                    homeBudget.logoutUser();
                    break;
                default:
                    cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                    system("pause");
                    break;
                }
            }
        }

    return 0;
}
