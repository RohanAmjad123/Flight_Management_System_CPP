//
//  Seat.cpp
//  Final Project ENSF 337
//
//  Created by Rohan Amjad on 2020-06-11.
//
#include <stdio.h>
#include <string>
#include <vector>
#include <iomanip>

#include "Flight.hpp"

using namespace std;

//-------------------------------- CONSTRUCTORS --------------------------------
Flight::Seat::Seat() : m_seatID("") {}

//-------------------------------- SET FUNCTIONS --------------------------------
void Flight::Seat::setSeatID(int t_row, int t_column)
{
    //CREATE A SEAT ID BASED ON THE ROW AND COLUMN
    string id = to_string(t_row + 1);
    char column = t_column + 'A';
    id.push_back(column);
    this->m_seatID = id;
}

//-------------------------------- GET FUNCTIONS --------------------------------
string Flight::Seat::getSeatID() const
{
    return this->m_seatID;
}

//-------------------------------------------------------------------------------

bool Flight::Seat::isTheSeatTaken()
{
    //RETURN FALSE IF SEAT VARIABLES ARE EMPTY OTHERWISE RETURN TRUE
    if (this->m_passenger.getPassengerFirstName() == "" &&
        this->m_passenger.getPassengerLastName() == "" &&
        this->m_passenger.getPassengerPhoneNumber() == "" &&
        this->m_passenger.getPassengerID() == "")
    {
        return false;
    }
    return true;
}

void Flight::Seat::printSeatDetails(int t_firstNameWidth, int t_lastNameWidth, int t_phoneNumberWidth, int t_seatIDWidth, int t_idWidth, int t_dashWidth)
{
    //PRINT SEAT DATA
    cout << setfill(' ');
    cout << left << setw(t_firstNameWidth) << this->m_passenger.getPassengerFirstName() << "\t"
         << left << setw(t_lastNameWidth) << this->m_passenger.getPassengerLastName() << "\t"
         << left << setw(t_phoneNumberWidth) << this->m_passenger.getPassengerPhoneNumber() << "\t"
         << left << setw(t_seatIDWidth) << this->getSeatID() << "\t"
         << left << setw(t_idWidth) << this->m_passenger.getPassengerID() << "\n";
    cout << setw(t_dashWidth) << setfill('-') << "-"
         << "\n";
    cout << setfill(' ');
}
