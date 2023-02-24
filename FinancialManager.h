#ifndef FINANCIALMANAGER_H
#define FINANCIALMANAGER_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>

#include "Income.h"
#include "Expense.h"
#include "FileWithIncomes.h"
#include "FileWithExpenses.h"


using namespace std;

class FinancialManager
{
    const int LOGGED_IN_USER_ID;
    vector <Income> incomes;
    vector <Expense> expenses;

    FileWithIncomes fileWithIncomes;
    FileWithExpenses fileWithExpenses;

    Income enterNewIncomeData();
    Expense enterNewExpenseData();


public:

    FinancialManager(string incomesFilename, string expensesFilename, int loggedInUserId)
        : LOGGED_IN_USER_ID(loggedInUserId), fileWithIncomes(incomesFilename), fileWithExpenses(expensesFilename)
    {
        incomes = fileWithIncomes.loadIncomesFromFile(LOGGED_IN_USER_ID);
        expenses = fileWithExpenses.loadExpensesFromFile(LOGGED_IN_USER_ID);
    };

    void addIncome();
    void addExpense();
    char selectOptionsOfDateInput();
    string inputDate();
    void balanceForCurrentMonth();
    void balanceForPreviousMonth();
    void balanceForSelectedDates();
    void showBalance(int beginning, int ending);
};

#endif
