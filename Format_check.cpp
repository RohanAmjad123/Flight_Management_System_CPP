//
//  Format_check.cpp
//  Final Project ENSF 337
//
//  Created by Rohan Amjad on 2020-06-15.
//
#include <iostream>
#include <string>
#include <vector>

#include "Format_check.hpp"

using namespace std;

bool isPassengerIDGood(string t_id)
{
    //CHECK IF PASSENGER ID IS IN CORRECT FORMAT
    bool isThereAnError = false;
    if (t_id.length() != 5)
    {
        isThereAnError = true;
    }
    for (int i = 0; i < t_id.length(); i++)
    {
        if (t_id[i] < '0' || t_id[i] > '9')
        {
            isThereAnError = true;
        }
    }
    return isThereAnError;
}

bool isFirstNameGood(string t_firstName)
{
    //CHECK IF THE FIRST NAME IS IN CORRECT FORMAT
    bool isThereAnError = false;
    for (int i = 0; i < t_firstName.length(); i++)
    {
        if ((t_firstName[i] < 'A' && t_firstName[i] < 'a' && t_firstName[i] != '-') ||
            (t_firstName[i] > 'Z' && t_firstName[i] > 'z' && t_firstName[i] != '-'))
        {
            isThereAnError = true;
            break;
        }
    }
    return isThereAnError;
}

bool isLastNameGood(string t_lastName)
{
    //CHECK IF THE LAST NAME IS IN CORRECT FORMAT
    bool isThereAnError = false;
    for (int i = 0; i < t_lastName.length(); i++)
    {
        if ((t_lastName[i] < 'A' && t_lastName[i] < 'a' && t_lastName[i] != '-') ||
            (t_lastName[i] > 'Z' && t_lastName[i] > 'z' && t_lastName[i] != '-'))
        {
            isThereAnError = true;
            break;
        }
    }
    return isThereAnError;
}

bool isPhoneNumberGood(string t_phoneNumber)
{
    bool isThereAnError = false;
    if ((t_phoneNumber[3] != '-' || t_phoneNumber[7] != '-') ||
        (t_phoneNumber.length() != 12))
    {
        isThereAnError = true;
    }
    for (int i = 0; i < 3; i++)
    {
        //CHECKS TO SEE IF FIRST 3 DIGITS OF PHONE NUMBER ARE NUMBERS
        if (t_phoneNumber[i] > '9' || t_phoneNumber[i] < '0')
        {
            isThereAnError = true;
        }
    }
    for (int i = 4; i < 7; i++)
    {
        //CHECKS TO SEE IF THE NEXT 3 DIGITS OF THE PHONE NUMBER ARE NUMBERS
        if (t_phoneNumber[i] > '9' || t_phoneNumber[i] < '0')
        {
            isThereAnError = true;
        }
    }
    for (int i = 8; i < 12; i++)
    {
        //CHECKS TO SEE IF THE LAST 4 DIGITS OF THE PHONE NUMBER ARE NUMBERS
        if (t_phoneNumber[i] > '9' || t_phoneNumber[i] < '0')
        {
            isThereAnError = true;
        }
    }
    return isThereAnError;
}
