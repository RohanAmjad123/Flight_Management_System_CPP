//
//  Passenger.cpp
//  Final Project ENSF 337
//
//  Created by Rohan Amjad on 2020-06-11.
//
#include <stdio.h>

#include "Flight.hpp"

using namespace std;

//-------------------------------- CONSTRUCTORS --------------------------------
Flight::Seat::Passenger::Passenger() : m_firstName(""), m_lastName(""), m_phoneNumber(""), m_id("") {}

//-------------------------------- SET FUNCTIONS --------------------------------
void Flight::Seat::Passenger::setPassengerFirstName(string t_firstName)
{
    this->m_firstName = t_firstName;
}
void Flight::Seat::Passenger::setPassengerLastName(string t_lastName)
{
    this->m_lastName = t_lastName;
}
void Flight::Seat::Passenger::setPassengerPhoneNumeber(string t_phoneNumber)
{
    this->m_phoneNumber = t_phoneNumber;
}
void Flight::Seat::Passenger::setPassengerID(string t_id)
{
    this->m_id = t_id;
}

//-------------------------------- GET FUNCTIONS --------------------------------
string Flight::Seat::Passenger::getPassengerFirstName() const
{
    return this->m_firstName;
}
string Flight::Seat::Passenger::getPassengerLastName() const
{
    return this->m_lastName;
}
string Flight::Seat::Passenger::getPassengerPhoneNumber() const
{
    return this->m_phoneNumber;
}
string Flight::Seat::Passenger::getPassengerID() const
{
    return this->m_id;
}

void Flight::Seat::Passenger::setPassengerNULL()
{
    //EMPTY ALL PASSENGER VARIABLES
    this->m_firstName = "";
    this->m_lastName = "";
    this->m_phoneNumber = "";
    this->m_id = "";
}
