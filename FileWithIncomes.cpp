#include "FileWithIncomes.h"

vector <Income> FileWithIncomes::loadIncomesFromFile(int loggedInUserId)
{
    Income income;
    vector <Income> incomes;
    CMarkup file;

    bool fileExists = file.Load( "incomes.xml" );

    if (fileExists)
    {
        file.FindElem();
        file.IntoElem();

        while ( file.FindElem("Income") )
        {
            file.IntoElem();
            file.FindElem( "IncomeId" );
            income.setIncomeId(AuxiliaryMethods::convertStringToInteger(file.GetData()));
            file.FindElem( "UserId" );

            if (AuxiliaryMethods::convertStringToInteger(file.GetData()) == loggedInUserId)
            {
                income.setUserId(AuxiliaryMethods::convertStringToInteger(file.GetData()));
                file.FindElem( "Date" );
                income.setDate(AuxiliaryMethods::convertDateToInteger(file.GetData()));
                file.FindElem( "Item" );
                income.setItem(file.GetData());
                file.FindElem( "Amount" );
                income.setAmount(AuxiliaryMethods::convertStringToFloat(file.GetData()));
                incomes.push_back(income);
            }
            file.OutOfElem();
            lastIncomeId++;
        }
    }


    return incomes;
}

void FileWithIncomes::addIncomeToFile(Income income)
{
    CMarkup file;

    bool fileExists = file.Load( "incomes.xml" );

    if (!fileExists)
    {
        file.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        file.AddElem("Incomes");
    }

    file.FindElem();
    file.IntoElem();
    file.AddElem("Income");
    file.IntoElem();
    file.AddElem("IncomeId", AuxiliaryMethods::convertIntegerToString(income.getIncomeId()));
    file.AddElem("UserId", AuxiliaryMethods::convertIntegerToString(income.getUserId()));
    file.AddElem("Date", AuxiliaryMethods::convertDateToString(income.getDate()));
    file.AddElem("Item", income.getItem());
    file.AddElem("Amount", AuxiliaryMethods::convertFloatToString(income.getAmount()));
    file.Save("incomes.xml");
    lastIncomeId = income.getIncomeId();
}

int FileWithIncomes::getLastIncomeIdFromFile()
{
    return lastIncomeId;
}
