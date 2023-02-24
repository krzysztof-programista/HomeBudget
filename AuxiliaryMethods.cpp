#include "AuxiliaryMethods.h"
#include <sstream>
#include <algorithm>
#include <ctime>
#include <string>
#include <stdlib.h>
#include <string.h>

using namespace std;

string AuxiliaryMethods::convertIntegerToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string AuxiliaryMethods::convertFloatToString(float number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

int AuxiliaryMethods::convertStringToInteger(string number)
{
    int intNumber;
    istringstream iss(number);
    iss >> intNumber;

    return intNumber;
}

float AuxiliaryMethods::convertStringToFloat(string number)
{
    float floatNumber;
    istringstream iss(number);
    iss >> floatNumber;

    return floatNumber;
}

char AuxiliaryMethods::loadChar()
{
    string input = "";
    char sign  = {0};

    while (true)
    {
        cin.sync();
        getline(cin, input);

        if (input.length() == 1)
        {
            sign = input[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return sign;
}

string AuxiliaryMethods::loadLine()
{
    string input = "";
    cin.sync();
    getline(cin, input);
    return input;
}

float AuxiliaryMethods::loadFloat()
{
    string input = "";
    float number = 0;

    while (true)
    {
        getline(cin, input);

        for (unsigned int i = 0; i < input.length(); i++)
        {
            if (input[i] == ',')
            {
                input[i] = '.';
            }
        }

        stringstream myStream(input);
        if (myStream >> number)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return number;
}

int AuxiliaryMethods::getNumberOfDaysInMonth (int month, int year)
{
    int daysInMonth [12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
    {
        return 29;
    }

    return daysInMonth[month - 1];
}

string AuxiliaryMethods::getPreviousMonth(int month)
{
    if (month == 1)
    {
        return "12";
    }
    else if (month > 1 && month <= 10)
    {
        return "0" + convertIntegerToString(month -1);
    }
    else if (month > 10 && month <= 12)
    {
        return convertIntegerToString(month -1);
    }
    else
    {
        return "wprowadzono niepoprawny numer miesiaca";
    }
}

string AuxiliaryMethods::compareDates (string d1, string d2) //zwraca pozniejsza date
{
    const char *date1 = d1.c_str();
    const char *date2 = d2.c_str();

    int comparision = strcmp(date1, date2);

    if (comparision == 0)
    {
        return "dates are equal";
    }
    else if (comparision > 0 )
    {
        return d1;
    }
    else
    {
        return d2;
    }

}

string AuxiliaryMethods::getCurrentDate()
{
    string date = "";
    time_t now = time(0);
    tm *ltm = localtime(&now);

    if (ltm->tm_mon < 9 && ltm->tm_mday > 9)
    {
        date = convertIntegerToString(1900 + ltm->tm_year) + '-' + '0'+ convertIntegerToString(1 + ltm->tm_mon) + '-' + convertIntegerToString(ltm->tm_mday);
    }
    else if(ltm->tm_mon >= 9 && ltm->tm_mday <= 9)
    {
        date = convertIntegerToString(1900 + ltm->tm_year) + '-' + convertIntegerToString(1 + ltm->tm_mon) + '-' + '0' + convertIntegerToString(ltm->tm_mday);
    }
    else if(ltm->tm_mon < 9 && ltm->tm_mday <= 9)
    {
        date = convertIntegerToString(1900 + ltm->tm_year) + '-' + '0' + convertIntegerToString(1 + ltm->tm_mon) + '-' + '0' + convertIntegerToString(ltm->tm_mday);
    }
    else
    {
        date = convertIntegerToString(1900 + ltm->tm_year) + '-' + convertIntegerToString(1 + ltm->tm_mon) + '-' + convertIntegerToString(ltm->tm_mday);
    }

    return date;
}

bool AuxiliaryMethods::isDateCorrect(string checkedDate)
{
    string currentDate = getCurrentDate();
    int currentYear = atoi(currentDate.substr(0,4).c_str());
    int currentMonth = atoi(currentDate.substr(5,2).c_str());
    int daysInCurrentMonth = getNumberOfDaysInMonth(currentMonth, currentYear);
    int digitsPositions[8] = {0,1,2,3,5,6,8,9};
    int dashesPositions[2] = {4,7};

    if (checkedDate.length() != 10) //sprawdzenie, czy podano ciag znakow o odpowiedniej dlugosci
    {
        cout << "Wprowadzono date o nieprawidlowej dlugosci!" <<endl;
        return false;
    }

    for (int i : digitsPositions) //sprawdzenie, czy podano same cyfry poza rozdzielnikami
    {
        if(!isdigit(checkedDate[i]))
        {
            cout << "Wprowadzono nieodpowiedni format daty!" <<endl;
            return false;
        }
    }

    for (int i : dashesPositions) //sprawdzenie, czy podano odpowiednie rozdzielniki
    {
        if((checkedDate[i]) != '-')
        {
            cout << "Wprowadzono nieodpowiedni format daty!" <<endl;
            return false;
        }
    }

    int checkedYear = atoi(checkedDate.substr(0,4).c_str());
    int checkedMonth = atoi(checkedDate.substr(5,2).c_str());
    int checkedDay = atoi(checkedDate.substr(8,2).c_str());
    int daysInCheckedMonth = getNumberOfDaysInMonth(checkedMonth, checkedYear);
    string maxDateInCurrentMonth = currentDate.replace(8,2,convertIntegerToString(daysInCurrentMonth));

    if (checkedMonth < 1 || checkedMonth >12 ) // sprawdzenie, podano poprawny miesiac
    {
        cout <<"Wpisano niepoprawna date"<< endl;
        return false;
    }

    if (checkedDay == 0 || checkedDay > daysInCheckedMonth ) // sprawdzenie, istnial taki dzien w miesiacu
    {
        cout <<"Wpisano niepoprawna date"<< endl;
        return false;
    }

    if ((compareDates(checkedDate,"2000-01-01") == "2000-01-01") || ((compareDates(checkedDate,maxDateInCurrentMonth)) == checkedDate)) // sprawdzenie, czy data jest wieksza ni¿ 2000-01-01 i mnijesza, ni¿ koniec biezacego miesiaca
    {
        cout <<"Wpisano date mniejsza niz 2000-01-01 lub wieksza niz ostatni dzien biezacego miesiaca" << endl;
        return false;
    }

    return true;
}

int AuxiliaryMethods::convertDateToInteger (string date) //funkcja potrzebna przy wczytywaniu z pliku do wektora w celu sortowania lub do wczytania po dodaniu przychodu/wydatku
{
    if (isDateCorrect(date))
    {
        string newDate = date;
        newDate.erase(4,1);
        newDate.erase(6,1);
        return convertStringToInteger(newDate);
    }
    return 0;
}

string AuxiliaryMethods::convertDateToString (int date) //funkcja potrzebna przy zapisie z wektora do pliku xml
{
    string newDate = convertIntegerToString(date);
    newDate.insert(4,"-");
    newDate.insert(7,"-");
    return newDate;
}
