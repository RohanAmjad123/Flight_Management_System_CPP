//
//  Helper_functions.hpp
//  Final Project ENSF 337
//
//  Created by Rohan Amjad on 2020-06-15.
//
#ifndef HELPER_FUNCTIONS_HPP
#define HELPER_FUNCTIONS_HPP

void programHeader();
/*
 *  REQUIRES:
 *
 *  PROMISES:
 *      - Displays a program header.
 */
void pressEnter();
/*
 *  REQUIRES:
 *
 *  PROMISES:
 *      - Prompts the user to press the enter/return key.
 */
void cleanStdInputStream(void);
/*
 *  REQUIRES:
 *
 *  PROMISES:
 *      - Cleans the standard input stream
 */
int menu();
/*
 *  REQUIRES:
 *
 *  PROMISES:
 *      - Displays a menu with 7 options.
 *
 *      - Prompts the user to enter a number from 1-7 to select one of the options.
 *
 *      - Displays an error until user enters a number from 1-7.
 */
#endif
