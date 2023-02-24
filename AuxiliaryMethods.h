#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>

using namespace std;

class AuxiliaryMethods
{
public:
    static string convertIntegerToString(int number);
    static string convertFloatToString(float number);
    static int convertStringToInteger(string number);
    static float convertStringToFloat(string number);
    static int convertDateToInteger (string date);
    static string convertDateToString (int date);

    static char loadChar();
    static string loadLine();
    static float loadFloat();

    static int getNumberOfDaysInMonth (int month, int year);
    static string getPreviousMonth(int month);
    static string getCurrentDate();
    static bool isDateCorrect(string checkedDate);
    static string compareDates (string d1, string d2);
};

#endif
