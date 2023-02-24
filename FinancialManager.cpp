#include "FinancialManager.h"

using namespace std;

void FinancialManager::addIncome()
{
    Income income = enterNewIncomeData();

    incomes.push_back(income);

    fileWithIncomes.addIncomeToFile(income);

    cout << endl << "Przychod zostal pomyslnie dodany" << endl << endl;
    system("pause");
}

void FinancialManager::addExpense()
{
    Expense expense = enterNewExpenseData();

    expenses.push_back(expense);

    fileWithExpenses.addExpenseToFile(expense);

    cout << endl << "Wydatek zostal pomyslnie dodany" << endl << endl;
    system("pause");
}

Income FinancialManager::enterNewIncomeData()
{
    Income income;
    string date = "";
    char choice = {0};

    income.setIncomeId(fileWithIncomes.getLastIncomeIdFromFile()+1);
    income.setUserId(LOGGED_IN_USER_ID);

    while (choice != '1' && choice != '2')
    {
        choice = selectOptionsOfDateInput();

        switch (choice)
        {
        case '1':
            date = AuxiliaryMethods::getCurrentDate();
            break;
        case '2':
            date = inputDate();
            break;
        default:
            cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
            system("pause");
            system("cls");
            break;
        }
    }
    income.setDate(AuxiliaryMethods::convertDateToInteger(date));

    cout << "Podaj czego dotyczy przychod: ";
    income.setItem(AuxiliaryMethods::loadLine());

    cout << "Podaj kwote(kwoty ulamkowe zapisz poprzedzajac je kropka): ";
    income.setAmount(AuxiliaryMethods::loadFloat());

    return income;
}

char FinancialManager::selectOptionsOfDateInput()
{
    char choice;

    cout << "Czy dotyczy on dnia dzisiejszego, czy chcesz podac inna date? " << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dzien dzisiejszy" << endl;
    cout << "2. Inna data" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods::loadChar();

    return choice;
}

string FinancialManager::inputDate()
{
    string date = "";
    cout << "Podaj date w formacie (RRRR-MM-DD): ";

    while (true)
    {
        date = AuxiliaryMethods::loadLine();

        if (AuxiliaryMethods::isDateCorrect(date) == true)
        {
            break;
        }
    }
    return date;
}

Expense FinancialManager::enterNewExpenseData()
{
    Expense expense;
    string date = "";
    char choice = {0};

    expense.setExpenseId(fileWithExpenses.getLastExpenseIdFromFile()+1);
    expense.setUserId(LOGGED_IN_USER_ID);

    while (choice != '1' && choice != '2')
    {
        choice = selectOptionsOfDateInput();

        switch (choice)
        {
        case '1':
            date = AuxiliaryMethods::getCurrentDate();
            break;
        case '2':
            date = inputDate();
            break;
        default:
            cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
            system("pause");
            system("cls");
            break;
        }
    }
    expense.setDate(AuxiliaryMethods::convertDateToInteger(date));

    cout << "Podaj czego dotyczy wydatek: ";
    expense.setItem(AuxiliaryMethods::loadLine());

    cout << "Podaj kwote(kwoty ulamkowe zapisz poprzedzajac je kropka): ";
    expense.setAmount(AuxiliaryMethods::loadFloat());

    return expense;
}

void FinancialManager::balanceForCurrentMonth()
{
    string currentYear = AuxiliaryMethods::getCurrentDate().substr(0,4);
    string currentMonth = AuxiliaryMethods::getCurrentDate().substr(5,2);
    int beginningOfCurrentMonth = AuxiliaryMethods::convertStringToInteger(currentYear + currentMonth + "01");
    int endOfCurrentMonth = beginningOfCurrentMonth + AuxiliaryMethods::getNumberOfDaysInMonth(AuxiliaryMethods::convertStringToInteger(currentMonth),AuxiliaryMethods::convertStringToInteger(currentYear)) - 1;

    showBalance(beginningOfCurrentMonth, endOfCurrentMonth);
}

void FinancialManager::balanceForPreviousMonth()
{
    string currentYear = AuxiliaryMethods::getCurrentDate().substr(0,4);
    string currentMonth = AuxiliaryMethods::getCurrentDate().substr(5,2);
    string previousMonth =  AuxiliaryMethods::getPreviousMonth(AuxiliaryMethods::convertStringToInteger(currentMonth));
    int beginningOfPreviousMonth = AuxiliaryMethods::convertStringToInteger(currentYear + previousMonth + "01");
    int endOfPreviousMonth = beginningOfPreviousMonth + AuxiliaryMethods::getNumberOfDaysInMonth(AuxiliaryMethods::convertStringToInteger(previousMonth), AuxiliaryMethods::convertStringToInteger(currentYear)) - 1;

    showBalance(beginningOfPreviousMonth, endOfPreviousMonth);
}

void FinancialManager::balanceForSelectedDates()
{
    string startDate = "";
    string endDate = "";

    cout << "Podaj date poczatkowa(wczesniejsza) dla bilansu w formacie (RRRR-MM-DD):" << endl;
    while (true)
    {
        startDate = AuxiliaryMethods::loadLine();

        if (AuxiliaryMethods::isDateCorrect(startDate) == true)
        {
            break;
        }
    }

    cout << "Podaj date koncowa(pozniejsza) dla bilansu w formacie (RRRR-MM-DD):" << endl;
    while (true)
    {
        endDate = AuxiliaryMethods::loadLine();

        if (AuxiliaryMethods::isDateCorrect(endDate) == true)
        {
            break;
        }
    }

    showBalance(AuxiliaryMethods::convertDateToInteger(startDate), AuxiliaryMethods::convertDateToInteger(endDate));
}

void FinancialManager::showBalance(int beginning, int ending)
{
    float sumOfIncomes = 0;
    float sumOfExpenses = 0;

    if(!incomes.empty())
    {
        sort(incomes.begin(), incomes.end());
        cout << endl<< "    >>> PRZYCHODY  <<<" << endl;
        for (unsigned int i = 0; i < incomes.size(); i++)
        {
            if(incomes[i].getDate() >= beginning && incomes[i].getDate() <= ending)
            {
                cout <<incomes[i].getIncomeId()<<" ";
                cout <<incomes[i].getDate()<<" ";
                cout <<incomes[i].getItem()<<" ";
                cout <<incomes[i].getAmount()<<" " << endl;
                sumOfIncomes = sumOfIncomes + incomes[i].getAmount();
            }
        }
    }
    else
    {
        cout << endl << "Brak wprowadzonych przychodow" << endl << endl;
    }

    if(!expenses.empty())
    {
        sort(expenses.begin(), expenses.end());
        cout << endl << "    >>> WYDATKI <<<" << endl;
        for (unsigned int i = 0; i < expenses.size(); i++)
        {
            if(expenses[i].getDate() >= beginning && expenses[i].getDate() <= ending)
            {
                cout <<expenses[i].getExpenseId()<<" ";
                cout <<expenses[i].getDate()<<" ";
                cout <<expenses[i].getItem()<<" ";
                cout <<expenses[i].getAmount()<<" " << endl;
                sumOfExpenses = sumOfExpenses + expenses[i].getAmount();
            }
        }
    }
    else
    {
        cout << endl << "Brak wprowadzonych wydatkow" << endl << endl;
    }
    cout << endl << "Suma przychodow wynosi: " << sumOfIncomes  << endl;
    cout << "Suma wydatkow wynosi: " << sumOfExpenses  << endl;
    cout << endl << "Bilans  wynosi: " << sumOfIncomes - sumOfExpenses  << endl;
    system("pause");
    cout<< endl <<endl;
}
