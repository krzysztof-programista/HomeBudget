#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>
#include <vector>

#include "Income.h"
#include "Markup.h"
#include "AuxiliaryMethods.h"

using namespace std;

class FileWithIncomes
{
    int lastIncomeId;
    const string FILENAME;

public:
    FileWithIncomes(string incomesFilename) : FILENAME(incomesFilename)
    {
        lastIncomeId = 0;
    };

    vector <Income> loadIncomesFromFile(int loggedInUserId);
    void addIncomeToFile(Income income);
    int getLastIncomeIdFromFile();
};

#endif

