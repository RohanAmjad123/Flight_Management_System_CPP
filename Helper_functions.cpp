//
//  Helper_functions.cpp
//  Final Project ENSF 337
//
//  Created by Rohan Amjad on 2020-06-15.
//
#include <stdio.h>
#include <iostream>
#include <string>

#include "Helper_functions.hpp"

using namespace std;

void programHeader(){
    //PRINT PROGRAM HEADER
    cout << "Version 1.0\n";
    cout << "Term Project - Flight Management System in C++\n";
    cout << "Produced by: Rohan Amjad\n";
}

void pressEnter(){
    //PRESS ENTER
    cout << "\n<<<<Press Return to Continue>>>>";
    cin.get();
}

void cleanStdInputStream(void){
    //CLEAR STANDARD INPUT STREAM
    char leftover;
    do {
        leftover = cin.get();
    } while (leftover != '\n' && leftover != EOF);
}

int menu(){
    char choice;
        
    pressEnter();
    
    //MENU OPTIONS
    cout << "\nPlease select one of the following options: \n";
    cout << "1. Display Flight Seat Map\n";
    cout << "2. Display Passenger Info\n";
    cout << "3. Add Passenger\n";
    cout << "4. Remove Passenger (Passenger ID)\n";
    cout << "5. Remove Passenger (Seat ID)\n";
    cout << "6. Save Data\n";
    cout << "7. Quit\n\n";
    
    cout << "Select one of the options (1, 2, 3, 4, 5, 6, or 7): ";
    
    //READ USER INPUT UNTIL CORRECT INPUT IS RECIEVED
    cin >> choice;
    cout << "\n";
    while (choice <= '0' || choice > '7') {
        cout << "Invalid input. Please choose options (1, 2, 3, 4, 5, 6, or 7): ";
        cleanStdInputStream();
        choice = cin.get();
        cout << "\n";
    }
    
    cleanStdInputStream();
    int i;
    i = choice - '0';
    return i;
}


