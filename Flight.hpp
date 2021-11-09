//
//  Flight.hpp
//  Final Project ENSF 337
//
//  Created by Rohan Amjad on 2020-06-11.
//
#ifndef FLIGHT_HPP
#define FLIGHT_HPP

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//-------------------------------- FLIGHT CLASS DEFINITION --------------------------------
class Flight
{
public:
    Flight();
    /*
     *  REQUIRES:
     *
     *  PROMISES:
     *      - Sets m_rows and m_columns to 1
     *
     *      - Resizes m_seats matrix to 1 row and 1 column
     *
     */
    void populateFlight(string t_filePath);
    /*
     *  REQUIRES:
     *      - A valid string t_filePath
     *
     *  PROMISES:
     *      - Checks to see if t_filePath is a valid file address and the inputStream is connected.
     *        If it's not, it gives the user 3 attempts to enter a valid file address
     *        or else the program exits.
     *
     *      - Reads the flight ID, rows, and columns from t_filePath and stores them in m_flightID, m_rows,
     *        and m_columns.
     *
     *      - Checks if m_columns is greater than 26. If yes then it displays error and sets m_columns to 26.
     *
     *      - Resizes m_seats matrix to m_rows and m_columns.
     *
     *      - Sets the seat ID's.
     *
     *      - Empties any previous passengers.
     *
     *      - Reads each passenger's data in t_filePath and adds that passenger to their specific seat.
     */
    void saveFlight(string t_filePath);
    /*
     *  REQUIRES:
     *      - A valid string t_filePath.
     *
     *  PROMISES:
     *      - Asks the user if they want to save the flight data to t_filePath
     *        by giving the user 3 attempts to enter Y/N or y/n.
     *        If user does not enter Y/N or y/n in the 3 attempts the function terminates.
     *
     *      - Displays the user's choice.
     *
     *      - Outputs the m_flightID, m_rows, and m_columns to t_filePath.
     *
     *      - Outputs the passenger data for each occupied seat to t_filePath.
     */
    void addPassenger(string t_firstName, string t_lastName,
                      string t_phoneNumber, string t_seatID, string t_id);
    /*  USED FOR ADDING A PASSENGER FROM A DATA FILE.
     *
     *  REQUIRES:
     *      - A valid string t_firstName.
     *
     *      - A valid string t_lastName.
     *
     *      - A valid string t_phoneNumber.
     *
     *      - A valid string t_seatID.
     *
     *      - A valid string t_id.
     *
     *  PROMISES:
     *      - Completes a format check on t_firstName, t_lastName, t_PhoneNumber, t_seatID, and t_id.
     *
     *      - Completes a seat ID check to see if t_seatID exists.
     *
     *      - Completes a seat check to see if t_seatID is taken of empty.
     *
     *      - Completes a passenger ID check to see if t_id already exists.
     *
     *      - If any of the above checks fail, an error message is displayed and program terminates.
     *
     *      - Fills in the passenger data for t_seatID.
     */
    void addPassenger();
    /*  USED FOR ADDING A PASSENGER FROM USER INPUT.
     *
     *  REQUIRES:
     *      - A valid string t_firstName.
     *
     *      - A valid string t_lastName.
     *
     *      - A valid string t_phoneNumber.
     *
     *      - A valid string t_seatID.
     *
     *      - A valid string t_id.
     *
     *  PROMISES:
     *      - Reads user input for firstName, lastName, phoneNumber, seatID, and id
     *
     *      - Completes a format check on firstName, lastName, PhoneNumber, seatID, and id.
     *        Displays an error message indicating each incorrect format for each failed check.
     *
     *      - Completes a seat ID check to see if seatID exists.
     *        Displays an error message indicating that seatID does not exist if check fails.
     *
     *      - Completes a seat check to see if seatID is taken of empty.
     *        Displays an error message indicating that seatID is taken if check fails.
     *
     *      - Completes a passenger ID check to see if id already exists.
     *        Displays an error message indicating that id already exists if check fails.
     *
     *      - If any of the above checks fail, the function terminates.
     *
     *      - Fills in the passenger data for seatID.
     *
     *      - Displays the passenger data of the passenger that was added.
     */
    void removePassengerUsingPassID();
    /*
     *  REQUIRES:
     *
     *  PROMISES:
     *      - Reads user input for id.
     *
     *      - Searches for the passenger ID matching id and removes the passenger data from that seat.
     *
     *      - If the id was not found in any seat. Displays an error indicating that id does not exist.
     */
    void removePassengerUsingSeatID();
    /*
     *  REQUIRES:
     *
     *  PROMISES:
     *      - Reads user input for seatID.
     *
     *      - Searches for the seat ID matching seatID and removes the passenger data from that seat.
     *
     *      - If the seatID was not found for any seat.
     *        Displays an error indicating that seatID does not exist.
     */
    void displayPassengerDataTable();
    /*
     *  REQUIRES:
     *
     *  PROMISES:
     *      - Diplays the passenger and seat data of all the occupied seats in a table.
     */
    void displayPlaneSeatMap();
    /*
     *  REQUIRES:
     *
     *  PROMISES:
     *      - Displays a flight seat map shwoing all the empty and occupied seats.
     */
private:
    //-------------------------------- SEAT CLASS DEFINITION --------------------------------
    class Seat
    {
        friend class Flight;

    public:
        Seat();
        /*
         *  REQUIRES:
         *
         *  PROMISES:
         *      - Sets m_seatID to "".
         */
        void setSeatID(int t_row, int t_column);
        /*
         *  REQUIRES:
         *      - A valid int t_row.
         *
         *      - A valid int t_column.
         *
         *  PROMISES:
         *      - Converts t_row and t_column to a string id and sets m_seatID to the converted id.
         */
        string getSeatID() const;
        /*
         *  REQUIRES:
         *
         *  PROMISES:
         *      - Returns m_seatID.
         */
        bool isTheSeatTaken();
        /*
         *  REQUIRES:
         *
         *  PROMISES:
         *      - Checks if all the passenger data in the seat is empty.
         *        Returns false if all the passenger data in the seat is empty.
         *        Returns true if not all the passenger data in the seat is empty.
         */
        void printSeatDetails(int t_firstNameWidth, int t_lastNameWidth,
                              int t_phoneNumberWidth, int t_seatIDWidth,
                              int t_idWidth, int t_dashWidth);
        /*
         *  REQUIRES:
         *      - A valid int t_firstNameWidth.
         *
         *      - A valid int t_lastNameWidth.
         *
         *      - A valid int t_phoneNumberWidth.
         *
         *      - A valid int t_seatIDWidth.
         *
         *      - A valid int t_idWidth.
         *
         *      - A valid int t_dashWidth.
         *
         *  PROMISES:
         *      - Prints the passenger data and seat data of the seat
         */
    private:
        //-------------------------------- PASSENGER CLASS DEFINITION --------------------------------
        class Passenger
        {
        public:
            Passenger();
            /*
             *  REQUIRES:
             *
             *  PROMISES:
             *      - Sets m_firstName to "".
             *
             *      - Sets m_lastName to "".
             *
             *      - Sets m_phoneNumber to "".
             *
             *      - Sets m_id to "".
             */
            void setPassengerFirstName(string t_firstName);
            /*
             *  REQUIRES:
             *      - A valid string t_firstName.
             *
             *  PROMISES:
             *      - Sets m_firstName to t_firstName.
             */
            void setPassengerLastName(string t_lastName);
            /*
             *  REQUIRES:
             *      - A valid string t_lastName.
             *
             *  PROMISES:
             *      - Sets m_lastName to t_lastName.
             */
            void setPassengerPhoneNumeber(string t_phoneNumber);
            /*
             *  REQUIRES:
             *      - A valid string t_phoneNumber.
             *
             *  PROMISES:
             *      - Sets m_phoneNumber to t_phoneNumber.
             */
            void setPassengerID(string t_id);
            /*
             *  REQUIRES:
             *      - A valid string t_id.
             *
             *  PROMISES:
             *      - Sets m_id to t_id.
             */
            void setPassengerNULL();
            /*
             *  REQUIRES:
             *
             *  PROMISES:
             *      - Sets m_firstName to "".
             *
             *      - Sets m_lastName to "".
             *
             *      - Sets m_phoneNumber to "".
             *
             *      - Sets m_id to "".
             */
            string getPassengerFirstName() const;
            /*
             *  REQUIRES:
             *
             *  PROMISES:
             *      - Returns m_firstName.
             */
            string getPassengerLastName() const;
            /*
             *  REQUIRES:
             *
             *  PROMISES:
             *      - Returns m_lastName.
             */
            string getPassengerPhoneNumber() const;
            /*
             *  REQUIRES:
             *
             *  PROMISES:
             *      - Returns m_phoneNumber.
             */
            string getPassengerID() const;
            /*
             *  REQUIRES:
             *
             *  PROMISES:
             *      - Returns m_id.
             */
        private:
            string m_firstName;
            string m_lastName;
            string m_phoneNumber;
            string m_id;
        };
        //-------------------------------- END OF PASSENGER CLASS DEFINITION --------------------------------

        string m_seatID;
        Passenger m_passenger;
    };
    //-------------------------------- END OF SEAT CLASS DEFINITION --------------------------------

    string m_flightID;
    int m_rows;
    int m_columns;
    vector<vector<Seat> > m_seats;
};
//-------------------------------- END OF FLIGHT CLASS DEFINITION --------------------------------

#endif
