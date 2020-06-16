//
//  Format_check.hpp
//  Final Project ENSF 337
//
//  Created by Rohan Amjad on 2020-06-15.
//
#ifndef FORMAT_CHECK_HPP
#define FORMAT_CHECK_HPP

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

bool isPassengerIDGood(string t_id);
/*
 *  REQUIRES:
 *      - A valid string t_id.
 *
 *  PROMISES:
 *      - Returns true if t_id matches the format of XXXXX integers.
 */
bool isFirstNameGood(string t_firstName);
/*
 *  REQUIRES:
 *      - A valid t_fir
 *
 *  PROMISES:
 *      - Returns true if t_firstName only contains letters or '-'.
 */
bool isLastNameGood(string t_lastName);
/*
 *  REQUIRES:
 *      - A valid string t_lastName.
 *
 *  PROMISES:
 *      - Returns true if t_lastName only contains letters or '-'.
 */
bool isPhoneNumberGood(string t_phoneNumber);
/*
 *  REQUIRES:
 *      - A valid string t_phoneNumber.
 *
 *  PROMISES:
 *      - Returns true if t_phoneNumber:
 *          - Contains only 12 characters.
 *          - The 4th and 8th characters ar '-'.
 *          - Characters 1, 2, and 3 are integers.
 *          - Characters 5, 6, and 7 are integers.
 *          - Characters 9, 10, 11, and 12 are integers.
 */
#endif
