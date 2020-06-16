//
//  Flight.cpp
//  Final Project ENSF 337
//
//  Created by Rohan Amjad on 2020-06-11.
//
#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

#include "Flight.hpp"
#include "Helper_functions.hpp"
#include "Format_check.hpp"

using namespace std;

//-------------------------------- CONSTRUCTORS --------------------------------
Flight::Flight(): m_flightID(""), m_rows(1), m_columns(1){
    //SET SEAT MATRIX TO 1 ROW AND 1 COLUMN
    this->m_seats.resize(this->m_rows);
    this->m_seats.at(0).resize(this->m_columns);
    
    //FILL SEAT ID'S
    for (int i = 0; i < this->m_rows; i++) {
        for (int j = 0; j < this->m_columns; j++) {
            this->m_seats.at(i).at(j).setSeatID(i, j);
        }
    }
    
}
//------------------------------------------------------------------------------

void Flight::populateFlight(string t_filePath){
    string filePath = t_filePath;
    ifstream inputStream;
    inputStream.open(filePath);
    
    //-------------------------------- INPUT STREAM CHECK --------------------------------
    int fails = 0;
    while (inputStream.fail()) {
        fails++;
        if (fails > 3) {
            cout << "\nData File Was Not Found. \nProgram Terminating...\n";
            exit(1);
        }
        cout << "\nData File Not Found. Please enter a valid file address\n";
        cin >> filePath;
        inputStream.open(filePath);
        if (!inputStream.fail()) {
            inputStream.clear();
        }
    }
    //-------------------------------- END OF INPUT STREAM CHECK --------------------------------
    
    //READ AND SET FLIGHT ID, ROWS, AND COLUMNS
    inputStream >> this->m_flightID >> this->m_rows >> this->m_columns;
    
    //CHECK IF COLUMNS IS GREATER THAN 26 AND LIMIT COLUMNS TO MAX OF 26
    if (this->m_columns > 26) {
        this->m_columns = 26;
        cout << "Columns exceeds the max allowed: 26. Columns have been set to the max: 26\n";
    }
    
    //SET SEAT MATRIX SIZE TO ROWS AND COLUMNS
    this->m_seats.resize(this->m_rows);
    for (int i = 0; i < this->m_rows; i++) {
        this->m_seats.at(i).resize(this->m_columns);
    }
    
    //SET SEAT ID'S
    for (int i = 0; i < this->m_rows; i++) {
        for (int j = 0; j < this->m_columns; j++) {
            this->m_seats.at(i).at(j).setSeatID(i, j);
        }
    }
    
    //EMPTY ANY PREVIOUS PASSENGERS
    for (int i = 0; i < this->m_rows; i++) {
        for (int j = 0; j < this->m_columns; j++) {
            if (this->m_seats.at(i).at(j).isTheSeatTaken()) {
                this->m_seats.at(i).at(j).m_passenger.setPassengerNULL();
            }
        }
    }
    
    //READ PASSENGER DATA UNTIL END OF FILE
    while (!inputStream.eof()) {
        string firstName;
        string lastName;
        string phoneNumber;
        string seatID;
        string id;
        inputStream >> firstName >> lastName >> phoneNumber >> seatID >> id;
        if (!inputStream.eof()) {
            Flight::addPassenger(firstName, lastName, phoneNumber, seatID, id);
        }
    }
    
    //CLOSE INPUT STREAM
    inputStream.close();
}

void Flight::saveFlight(string t_filePath){
    string filePath = t_filePath;
    ofstream outputStream;
    outputStream.open(filePath);
    
    //USER INPUT
    char saveFlight;
    cout << "Do you want to save flight data to " << filePath << " enter Y/N: ";
    saveFlight = cin.get();
    cleanStdInputStream();
    cout << "\n";
    
    //RETURN AFTER TOO MANY INVALID USER INPUTS
    int fails = 0;
    while (saveFlight != 'y' && saveFlight != 'n' && saveFlight != 'Y' && saveFlight != 'N') {
        fails++;
        if (fails > 3) {
            return;
        }
        cout << "Please enter either Y/N\n";
        cout << saveFlight;
        saveFlight = cin.get();
        cleanStdInputStream();
    }
    
    //DISPLAY USER'S CHOICE
    if (saveFlight == 'N' || saveFlight == 'n') {
        cout << "Data Not Saved\n";
        return;
    }
    else{
        cout << "Data Saved!\n";
    }
    
    //OUPUT FLIGHT ID, ROWS, AND COLUMNS
    outputStream << this->m_flightID << " " << this->m_rows << " " << this->m_columns << "\n";
    
    //OUTPUT PASSENGER DATA
    for (int i = 0; i < this->m_rows; i++) {
        for (int j = 0; j < this->m_columns; j++) {
            if (this->m_seats.at(i).at(j).isTheSeatTaken()) {
                outputStream << left << setw(15) <<this->m_seats.at(i).at(j).m_passenger.getPassengerFirstName() << "\t"
                << left << setw(15) << this->m_seats.at(i).at(j).m_passenger.getPassengerLastName() << "\t"
                << left << setw(12) << this->m_seats.at(i).at(j).m_passenger.getPassengerPhoneNumber() << "\t"
                << left << setw(10) << this->m_seats.at(i).at(j).getSeatID() << "\t"
                << left << setw(10) << this->m_seats.at(i).at(j).m_passenger.getPassengerID() << "\n";
            }
        }
    }
    
    //CLOSE OUTPUT STREAM
    outputStream.close();
}

void Flight::addPassenger(string t_firstName, string t_lastName, string t_phoneNumber, string t_seatID, string t_id){
    
    bool isThereAnError = false;

    //-------------------------------- FORMAT CHECKS --------------------------------
    
    //PASSENGER ID CHECK
    if (isPassengerIDGood(t_id) == true) {
        isThereAnError = true;
    }
    
    //FIRST NAME CHECK
    if (isFirstNameGood(t_firstName) == true) {
        isThereAnError = true;
    }
    
    //LAST NAME CHECK
    if (isLastNameGood(t_lastName) == true) {
        isThereAnError = true;
    }
    
    //PHONE NUMBER CHECK
    if (isPhoneNumberGood(t_phoneNumber) == true) {
        isThereAnError = true;
    }
    //-------------------------------- END OF FORMAT CHECKS --------------------------------
    
    //-------------------------------- PASSENGER AND SEAT CHECKS --------------------------------

    //SEAT ID CHECK
    int k = 0;
    for (int i = 0; i < this->m_rows; i++) {
        for (int j = 0; j < this->m_columns; j++) {
            //CHECKS IF t_seatID EXISTS
            if (this->m_seats.at(i).at(j).getSeatID() == t_seatID) {
                k = 1;
            }
            
        }
    }
    if (k != 1) {
        isThereAnError = true;
    }
    
    //IS SEAT TAKEN CHECK
    for (int i = 0; i < this->m_rows; i++) {
        for (int j = 0; j < this->m_columns; j++) {
            
            if (this->m_seats.at(i).at(j).getSeatID() == t_seatID) {
                //CHECKS IF t_seat IS TAKEN
                if (this->m_seats.at(i).at(j).isTheSeatTaken()) {
                    isThereAnError = true;
                }
            }
            
        }
    }
    
    //DUPLICATE PASSENGER ID CHECK
    for (int i = 0; i < this->m_rows; i++) {
        for (int j = 0; j < this->m_columns; j++) {
            //CHECK IF t_id ALREADY EXISTS
            if (this->m_seats.at(i).at(j).m_passenger.getPassengerID() == t_id) {
                isThereAnError = true;
            }
            
        }
    }
    //-------------------------------- END OF PASSENGER AND SEAT CHECKS --------------------------------

    if (isThereAnError == true) {
        cout << "\nData File Is Not In The Correct Format.\nPlease fix the errors in the data file and retry\n\nProgram Terminating...\n";
        exit(1);
    }
    
    //FILL SEAT WITH PASSENGER DATA
    for (int i = 0; i < this->m_rows; i++) {
        for (int j = 0; j < this->m_columns; j++) {
            
            if (this->m_seats.at(i).at(j).getSeatID() == t_seatID) {
                this->m_seats.at(i).at(j).m_passenger.setPassengerFirstName(t_firstName);
                this->m_seats.at(i).at(j).m_passenger.setPassengerLastName(t_lastName);
                this->m_seats.at(i).at(j).m_passenger.setPassengerPhoneNumeber(t_phoneNumber);
                this->m_seats.at(i).at(j).m_passenger.setPassengerID(t_id);
            }
            
        }
    }
    
}

void Flight::addPassenger(){
    string firstName;
    string lastName;
    string phoneNumber;
    string seatID;
    string id;
    
    //USER INPUT
    cout << "\nEnter Passenger's ID: ";
    cin >> id;
    cleanStdInputStream();
    
    cout << "\nEnter Passenger's First Name: ";
    cin >> firstName;
    cleanStdInputStream();
    
    cout << "\nEnter Passenger's Last Name: ";
    cin >> lastName;
    cleanStdInputStream();
    
    cout << "\nEnter Passenger's Phone Number: ";
    cin >> phoneNumber;
    cleanStdInputStream();
    
    cout << "\nEnter Passenger's Seat: ";
    cin >> seatID;
    cleanStdInputStream();
    
    cout << "\n";
    
    bool isThereAnError = false;

    //-------------------------------- FORMAT CHECKS --------------------------------

    //PASSENGER ID CHECK
    if (isPassengerIDGood(id) == true) {
        cout << "\nPassenger ID: " << id << " is an invalid ID. Please enter Passenger ID in the format of     XXXXX integers\n";
        isThereAnError = true;
    }
    
    //FIRST NAME CHECK
    if (isFirstNameGood(firstName) == true) {
        cout << "\nPlease enter a correct first name for Passenger ID: " << id << "\n";
        isThereAnError = true;
    }
    
    //LAST NAME CHECK
    if (isLastNameGood(lastName) == true) {
        cout << "\nPlease enter a correct last name for Passenger ID: " << id << "\n";
        isThereAnError = true;
    }
    
    //PHONE NUMBER CHECK
    if (isPhoneNumberGood(phoneNumber) == true) {
        cout << "\nInvalid phone number for Passenger ID: " << id << ". Please enter phone number in the format: XXX-XXX-XXXX\n";
        isThereAnError = true;
    }
    //-------------------------------- END OF FORMAT CHECKS --------------------------------

    //-------------------------------- PASSENGER AND SEAT CHECKS --------------------------------

    //SEAT ID CHECK
    int k = 0;
    for (int i = 0; i < this->m_rows; i++) {
        for (int j = 0; j < this->m_columns; j++) {
            //CHECKS IF t_seatID EXISTS
            if (this->m_seats.at(i).at(j).getSeatID() == seatID) {
                k = 1;
            }
            
        }
    }
    if (k != 1) {
        cout << "\nSeat: " << seatID << " does not exist. Passenger ID: " << id << " cannot be added\n";
        isThereAnError = true;
    }
    
    //IS SEAT TAKEN CHECK
    for (int i = 0; i < this->m_rows; i++) {
        for (int j = 0; j < this->m_columns; j++) {
            
            if (this->m_seats.at(i).at(j).getSeatID() == seatID) {
                //CHECKS IF t_seat IS TAKEN
                if (this->m_seats.at(i).at(j).isTheSeatTaken()) {
                    cout << "\nSeat " << seatID << " is already taken by Passenger ID: "
                    << this->m_seats.at(i).at(j).m_passenger.getPassengerID() << ". Please remove the passenger or find another seat\n";
                    isThereAnError = true;
                }
            }
            
        }
    }
    
    //DUPLICATE PASSENGER ID CHECK
    for (int i = 0; i < this->m_rows; i++) {
        for (int j = 0; j < this->m_columns; j++) {
            //CHECK IF t_id ALREADY EXISTS
            if (this->m_seats.at(i).at(j).m_passenger.getPassengerID() == id) {
                cout << "\nPassenger ID: " << id << " already exists. Passenger " << firstName << " " << lastName << " was not added. Please select new Passenger ID\n";
                isThereAnError = true;
            }
            
        }
    }
    //-------------------------------- END OF PASSENGER AND SEAT CHECKS --------------------------------

    if (isThereAnError == true){
        return;
    }
    
    //-------------------------------- END OF ERROR CHECKS --------------------------------
    
    //FILL SEAT WITH PASSENGER DATA
    for (int i = 0; i < this->m_rows; i++) {
        for (int j = 0; j < this->m_columns; j++) {
            if (this->m_seats.at(i).at(j).getSeatID() == seatID) {
                this->m_seats.at(i).at(j).m_passenger.setPassengerFirstName(firstName);
                this->m_seats.at(i).at(j).m_passenger.setPassengerLastName(lastName);
                this->m_seats.at(i).at(j).m_passenger.setPassengerPhoneNumeber(phoneNumber);
                this->m_seats.at(i).at(j).m_passenger.setPassengerID(id);
            }
        }
    }
    
    //DISPLAY PASSENGER INFO THAT WAS ADDED
    cout << "Passenger ID: " << id << "\n";
    cout << "First Name: " << firstName << "\n";
    cout << "Last Name: " << lastName << "\n";
    cout << "Phone Number: " << phoneNumber << "\n";
    cout << "Seat: " << seatID << "\n\n";
    cout << "Was added successfully!\n";

}

void Flight::removePassengerUsingPassID(){
    string id;
    
    //USER INPUT
    cout << "\nEnter the Passenger ID of the passenger you want to remove: ";
    cin >> id;
    cleanStdInputStream();
    
    int k = 0;
    
    //REMOVE PASSENGER BASED ON ID
    for (int i = 0; i < this->m_rows; i++) {
        for (int j = 0; j < this->m_columns; j++) {
            if (this->m_seats.at(i).at(j).m_passenger.getPassengerID() == id) {
                this->m_seats.at(i).at(j).m_passenger.setPassengerNULL();
                cout << "Passenger ID: " << id << " was removed\n";
                k = 1;
            }
        }
    }
    
    //IF GIVEN ID DOES NOT MATCH ANY ID OF THE PASSENGERS ONBOARD, DISPLAY ERROR AND RETURN
    if (k != 1) {
        cout << "Passenger ID: " << id << " was not found\n";
        return;
    }
    
}

void Flight::removePassengerUsingSeatID(){
    string seatID;
    
    //USER INPUT
    cout << "\nEnter the Seat ID of the passenger you want to remove: ";
    cin >> seatID;
    cleanStdInputStream();
    
    int k = 0;
    
    //REMOVE PASSENGER BASED ON SEAT
    for (int i = 0; i < this->m_rows; i++) {
        for (int j = 0; j < this->m_columns; j++) {
            if (this->m_seats.at(i).at(j).getSeatID() == seatID) {
                if (this->m_seats.at(i).at(j).isTheSeatTaken()) {
                    this->m_seats.at(i).at(j).m_passenger.setPassengerNULL();
                    cout << "Passenger on seat " << seatID << " was removed\n";
                }
                else {
                    cout << "Seat " << this->m_seats.at(i).at(j).getSeatID() << " does not have a passenger\n";
                    return;
                }
                k = 1;
            }
        }
    }
    
    //IF GIVEN SEAT DOES NOT EXIST, DISPLAY ERROR AND RETURN
    if (k != 1) {
        cout << "Seat " << seatID << " does not exist. Passenger cannot be removed\n";
        return;
    }
    
}

void Flight::displayPassengerDataTable(){
    //WIDTH VARIABLES
    int firstNameWidth = 15;
    int lastNameWidth = 15;
    int phoneNumberWidth = 12;
    int seatIDWidth = 10;
    int idWidth = 10;
    int dashWidth = 72;
    
    //CREATE TABLE HEADER
    cout << setfill(' ');
    cout << left << setw(firstNameWidth) << "First Name" << "\t"
    << left << setw(lastNameWidth) << "Last Name" << "\t"
    << left << setw(phoneNumberWidth) << "Phone Number" << "\t"
    << left << setw(seatIDWidth) << "Seat" << "\t"
    << left << setw(idWidth) << "Passenger ID" << "\n";
    cout << setw(dashWidth) << setfill('-') << "-" << "\n";
    
    //PRINT PASSENGER DATA IN TABLE
    for (int i = 0; i < this->m_rows; i++) {
        for (int j = 0; j < this->m_columns; j++) {
            if (this->m_seats.at(i).at(j).isTheSeatTaken()) {
                this->m_seats.at(i).at(j).printSeatDetails(firstNameWidth, lastNameWidth, phoneNumberWidth, seatIDWidth, idWidth, dashWidth);
            }
        }
    }
    
}

void Flight::displayPlaneSeatMap(){
    //PRINT FLIGHT MAP HEADER
    cout << "   Flight Seat Map: " << this->m_flightID << "\n";
    cout << "   -----------------------\n";
    cout << "   X - Occupied Seat" << "\n\n";
    
    //PRINT COLUMN LABELS
    char column = 'A';
    cout << setw(3) << "";
    for (int j = 0; j < this->m_columns; j++) {
        cout << "  " <<column << " ";
        column++;
    }
    cout << "\n";
    
    //PRINT SEAT MAP AND ROWS
    for (int i = 0; i < this->m_rows; i++) {
        cout << setw(3) << "";
        for (int j = 0; j < this->m_columns; j++) {
            cout << "+---";
        }
        cout << "+";
        cout << "\n";
        cout << setw(3) << setfill(' ') << left << i+1;
        
        for (int k = 0; k < this->m_columns; k++) {
            if (this->m_seats.at(i).at(k).isTheSeatTaken()) {
                cout << "| X ";
            }
            else{
                cout << "|   ";
            }
        }
        cout << "|   ";
        cout << "\n";
    }
    cout << setw(3) << "";
    for (int j = 0; j < this->m_columns; j++) {
        cout << "+---";
    }
    cout << "+";
    cout << "\n";
    
}



