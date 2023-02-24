#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include <iostream>
#include <vector>

#include "Expense.h"
#include "Markup.h"
#include "AuxiliaryMethods.h"

using namespace std;

class FileWithExpenses
{
    int lastExpenseId;
    const string FILENAME;

public:
    FileWithExpenses(string expensesFilename) : FILENAME(expensesFilename)
    {
        lastExpenseId = 0;
    };

    vector <Expense> loadExpensesFromFile(int loggedInUserId);
    void addExpenseToFile(Expense expense);
    int getLastExpenseIdFromFile();
};

#endif
