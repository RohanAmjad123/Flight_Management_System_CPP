//
//  Flight_management.cpp
//  Final Project ENSF 337
//  version 1.0
//
//  Created by Rohan Amjad on 2020-06-11.
//
#include <iostream>

#include "Flight.hpp"
#include "Helper_functions.hpp"

using namespace std;

int main()
{
    Flight f;

    programHeader();

    f.populateFlight("");
    cleanStdInputStream();

    int choice;
    while ((choice = menu()))
    {
        switch (choice)
        {
        case 1:
            f.displayPlaneSeatMap();
            break;
        case 2:
            f.displayPassengerDataTable();
            break;
        case 3:
            f.addPassenger();
            break;
        case 4:
            f.removePassengerUsingPassID();
            break;
        case 5:
            f.removePassengerUsingSeatID();
            break;
        case 6:
            f.saveFlight("test.txt");
            break;
        case 7:
            cout << "Program Terminating...\n";
            exit(1);
            break;
        }
    }
    return 0;
}
