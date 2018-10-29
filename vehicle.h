/*
 *  vehicle.h
 *
 *  COSC 052 Fall 2018
 *  Project #2
 *
 *  Due on: OCT 11, 2018
 *  Author: tel33
 *
 *
 *  In accordance with the class policies and Georgetown's
 *  Honor Code, I certify that, with the exception of the
 *  class resources and those items noted below, I have neither
 *  given nor received any assistance on this project.
 *
 *  References not otherwise commented within the program source code.
 *  Note that you should not mention any help from the TAs, the professor,
 *  or any code taken from the class textbooks.
 
 */

#ifndef _COSC052_FALL2018_P2_VEHICLE_H_
#define _COSC052_FALL2018_P2_VEHICLE_H_

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <exception>
#include <cstdlib>

#include "DateTime.h"

using std::string;
using std::invalid_argument;
using std::logic_error;
using std::istream;
using std::ostream;
using std::cout;
using std::endl;
using std::ostringstream;
using std::istringstream;

const int DERIVED_CLASS_COUNT = 3;
const int STATUS_CODE_COUNT = 3;
const int ID_REQUIRED_LENGTH = 17;

enum DerivedNames { _INDIVIDUAL_, _PASSENGER_, _CARGO_ };
enum StatusNames { _IN_MAINTENANCE_, _IN_SERVICE_, _AVAILABLE_ };

const char TYPE_CODES[DERIVED_CLASS_COUNT + 1] = {'i', 'p', 'c', '\0'};
const char STATUS_CODES[STATUS_CODE_COUNT + 1] = {'m', 's', 'a', '\0'};


    class Vehicle
        {
        
        protected:
            
              string id;
              string name;
              Date inspectionDate;
              char status;
            
        public:
            
              Vehicle();
            
            //computer didnt recognize id so I changed it to idd;
            
              Vehicle( string id, string name, Date iDate, char status ) throw ( invalid_argument );
            
              string getID() const {return id;}
              string getName() const {return name;}
              Date getInspectionDate() const {return inspectionDate;}
              char getStatus() const {return status;}
              void setID( string id ) throw ( invalid_argument );
              void setName( string name );
              void setInspectionDate( Date iDate ) throw ( invalid_argument );
              void setStatus( char status ) throw ( invalid_argument );
            
        
              bool readDoubleQuotedString( istream&, string&) throw (logic_error, invalid_argument);
            
              virtual void print( ostream& os = cout ) const throw ( invalid_argument );
              virtual void read( istream& is ) throw ( invalid_argument, logic_error );
            
              virtual ~Vehicle();
    
        }; // END Vehicle class declaration

class Individual : public Vehicle
        {
            
        public:
   
            Individual();
            Individual(string id, string name, Date inspectionDate, char status);
            
        
        }; // END class Individual declaration

class Passenger : public Vehicle
        {
         private:
        
         int passengerCapacity;
            
         public:
        
        Passenger();
        Passenger(string id, string name, Date inspectionDate, char status, int cap);
    
        int getCapacity() const;
        void setCapacity(int cap);
            
        virtual void print( ostream& os = cout ) const throw ( invalid_argument );
        virtual void read( istream& is ) throw ( invalid_argument );
        
    
   }; // END class Passenger declaration

class Cargo : public Vehicle
    {
    private:
    
        double cargoCapacity;
    
    public:
    
        Cargo();
        Cargo(string id, string name, Date inspectionDate, char status, double cap);
        
        double getCapacity() const;
        void setCapacity(double cap);
        
        virtual void print( ostream& os = cout ) const throw ( invalid_argument );
        virtual void read( istream& is ) throw ( invalid_argument );
        
        
        
    }; // END class Cargo declaration

#endif /*  _COSC052_FALL2018_P2_VEHICLE_H_  */

