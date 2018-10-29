/*
 * vehicleLog.cpp
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

#include "vehicleLog.h"

VehicleLog::VehicleLog()
{
    cout << "Now Entering Vehicle Log Default Constructor..." <<endl;
    
}

VehicleLog::~VehicleLog()
{
    
    unsigned long deletes = 0;
    for (unsigned int i=0; i<vehicles.size(); i++)
    {
        delete vehicles.at(i);
        deletes++;
        
    }
    cout<< deletes << "deallocates memory" <<endl;
}

int VehicleLog::getTotalPassengerCapacity() const
{


    
    int totalcap = 0;
    

    for (unsigned long i = 0 ; i < vehicles.size(); i++)
    {
        Passenger *tPtr = dynamic_cast<Passenger*>(vehicles.at(i));
        if (tPtr)
        {
        totalcap += tPtr -> getCapacity();
        }
    }
    
    return totalcap;
}
double VehicleLog::getTotalCargoCapacity() const
{
    
    
    int totalcap = 0;
    
    
    for (unsigned long i = 0 ; i < vehicles.size(); i++)
    {
        Cargo *tPtr = dynamic_cast<Cargo*>(vehicles.at(i));
        if (tPtr)
        {
            totalcap += tPtr -> getCapacity();
        }
    }
    
    return totalcap;

}
void VehicleLog::print( ostream& os) const throw (invalid_argument)
{
    cout << "vehicle print" << endl;
    
    if (!os)
    {
        throw  invalid_argument ("file not open");
    }
    for (unsigned long i=0 ; i< vehicles.size(); i++)
    {
        vehicles.at (i)->print(os);
        
    }
    
    
}

void VehicleLog::read( string fileName ) throw ( invalid_argument, bad_vehicle_code )
{
    

    std::ifstream Infile;
    Infile.open (fileName.c_str());
    string open_msg = "File Did Not Open Throwing Error Invalid Argument...";
    
    if (Infile.fail())
    {
        throw invalid_argument (open_msg);
    }
    
        //Vehicle* *vehicleArray = NULL;
    
        string In_Line = " ";

        char type = ' ';
    
    
        
        //unsigned long vehiclecount = 0;
    
        
        Vehicle *vehicl = NULL;
    
    
        
        Infile >> type;
    
    
    string junk = " ";
        
    while (Infile)
    {
        
        try{
            
        
        
    
            Infile.putback(type);
            
            type =tolower(type);
                    if (type == 'i')
                    {
                        
                        vehicl = new Individual();
                            
                    }//end 'i' else if
                    else if (type == 'p')
                        {
                            
                       
                            
                        vehicl = new Passenger();
                           
                            
                        } //end 'p' else if
                    else if (type == 'c')
                        {
                           
                            
                            vehicl = new Cargo ();
                        } //end 'c' else if
                        
        
                else
                    {
                        
                        string msg = "Vehicle Code Invalid";
                        
                       
                        
                        throw bad_vehicle_code(msg);
                        
                        
                        
                    }//end else statement
        
       
        vehicl -> read(Infile);
        
         
            
            
        vehicles.push_back(vehicl);

      
        
        Infile>>type;

                    
        }//end nested try block in while
        
        catch (bad_vehicle_code &b)
        {
          
            cout << b.what() << endl;
            
            getline(Infile, junk);
            
            Infile >> type;
            
        }
        catch (invalid_argument &b)
        {
            cout<< "invalid argument" <<endl;
            
            cout << b.what() << endl;
            
            getline(Infile, junk);
            
                        
        }
        catch (...)
        {
            cout << "caught unknown exception inside while loop, terminate program" << endl;
            throw;
        }
        
    } //end while loop
    
}//close read method



    

   
    
    
    
    







