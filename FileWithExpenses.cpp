#include "FileWithExpenses.h"

vector <Expense> FileWithExpenses::loadExpensesFromFile(int loggedInUserId)
{
    Expense expense;
    vector <Expense> expenses;
    CMarkup file;

    bool fileExists = file.Load( "expenses.xml" );

    if (fileExists)
    {
        file.FindElem();
        file.IntoElem();

        while ( file.FindElem("Expense") )
        {
            file.IntoElem();
            file.FindElem( "ExpenseId" );
            expense.setExpenseId(AuxiliaryMethods::convertStringToInteger(file.GetData()));
            file.FindElem( "UserId" );

            if (AuxiliaryMethods::convertStringToInteger(file.GetData()) == loggedInUserId)
            {
                expense.setUserId(AuxiliaryMethods::convertStringToInteger(file.GetData()));
                file.FindElem( "Date" );
                expense.setDate(AuxiliaryMethods::convertDateToInteger(file.GetData()));
                file.FindElem( "Item" );
                expense.setItem(file.GetData());
                file.FindElem( "Amount" );
                expense.setAmount(AuxiliaryMethods::convertStringToFloat(file.GetData()));
                expenses.push_back(expense);
            }
            file.OutOfElem();
            lastExpenseId++;
        }
    }


    return expenses;
}

void FileWithExpenses::addExpenseToFile(Expense expense)
{
    CMarkup file;

    bool fileExists = file.Load( "expenses.xml" );

    if (!fileExists)
    {
        file.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        file.AddElem("Expenses");
    }

    file.FindElem();
    file.IntoElem();
    file.AddElem("Expense");
    file.IntoElem();
    file.AddElem("ExpenseId", AuxiliaryMethods::convertIntegerToString(expense.getExpenseId()));
    file.AddElem("UserId", AuxiliaryMethods::convertIntegerToString(expense.getUserId()));
    file.AddElem("Date", AuxiliaryMethods::convertDateToString(expense.getDate()));
    file.AddElem("Item", expense.getItem());
    file.AddElem("Amount", AuxiliaryMethods::convertFloatToString(expense.getAmount()));
    file.Save("expenses.xml");
    lastExpenseId = expense.getExpenseId();
}

int FileWithExpenses::getLastExpenseIdFromFile()
{
    return lastExpenseId;
}


