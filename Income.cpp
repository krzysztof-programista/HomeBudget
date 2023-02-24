#include "Income.h"

void Income::setIncomeId(int newIncomeId)
{
    if (newIncomeId >= 0)
        incomeId = newIncomeId;
}

void Income::setUserId(int newUserId)
{
    if (newUserId >= 0)
        userId = newUserId;
}

void Income::setDate(int newDate)
{
    date = newDate;
}

void Income::setItem(string newItem)
{
    item = newItem;
}

void Income::setAmount(float newAmount)
{
    amount = newAmount;
}

int Income::getIncomeId()
{
    return incomeId;
}

int Income::getUserId()
{
    return userId;
}

int Income::getDate()
{
    return date;
}

string Income::getItem()
{
    return item;
}

float Income::getAmount()
{
    return amount;
}

