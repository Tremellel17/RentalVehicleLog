/*
 *  main.cpp
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

#include "main.h"

int main(int argc, const char *argv[])
{ try{
    
        int argument_number =2;
        
        if (argc < argument_number) {
            
            string bad_argument_number = " ";
            
            throw invalid_argument (bad_argument_number);
            
            
        }
        
        
        
   
    
    string fileName = argv[1];
        
    string file = "file.txt";
    
    string outputFile = fileName + ".out";
    VehicleLog vehicleLog;
        
    vehicleLog.read(fileName);
    
    vehicleLog.print(cout);
    
        cout<<endl;
    
    
    }
    
    catch (bad_vehicle_code & e)
    {
        cout<< "bad vehicle code main";
        cout<< e.what() << endl;
    }
    
    catch (invalid_argument & e)
    {
        cout<< "invalid argument main";
        cout<< e.what() << endl;
    }
    
    catch (logic_error & e)
    {
        cout<< "logical error main";
        cout<< e.what() << endl;
    }
    
    catch (...)
    {
        cout<< "uncaught error main";
        throw;
    }
    return 0;
    
}
