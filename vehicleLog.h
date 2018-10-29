/*
 *  vehicleLog.h
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

#ifndef _COSC052_FALL2018_P2_VEHICLE_LOG_H_
#define _COSC052_FALL2018_P2_VEHICLE_LOG_H_

#include <iostream>
#include <vector>
#include "vehicle.h"
#include "exceptions.h"

using std::vector;

class VehicleLog
    {
    private:
    
        vector<Vehicle*> vehicles;
        
    public:
    
        VehicleLog();
    
        int getTotalPassengerCapacity() const;
        double getTotalCargoCapacity() const;
   
        void print( ostream& os = cout ) const throw (invalid_argument);
        void read( string fileName ) throw ( invalid_argument, bad_vehicle_code );
    
        unsigned long size() const { return vehicles.size(); }
   
        Vehicle &at(unsigned long ndx) { return *(vehicles.at(ndx)); }
    
        
        ~VehicleLog();
        
   }; // END class VehicleLog

#endif /*  _COSC052_FALL2018_P2_VEHICLE_LOG_H_  */

