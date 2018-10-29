/*
 *  vehicle.cpp
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


#include <iostream>
#include "vehicle.h"

/** Vehicle PARENT Class Default Constructor **/

Vehicle::Vehicle()
{
 
    id = "p0000000000000000";
    name = "none";
    inspectionDate = (Date(MIN_YYYY, MIN_MM, MIN_DD));
    status = 'm';
}

Vehicle::Vehicle(string idd, string name, Date iDate, char status) throw (invalid_argument)
{
    setID( idd );
    setName( name );
    setInspectionDate( iDate );
    setStatus( status );
    
    
    
}

/** Vehicle PARENT Class Default Constructor **/

Vehicle::~Vehicle()
{
   // cout << "Base Class Deconstructor with Vehicle ID : "<< idd << endl;
    
}


/** INLINE Vehicle Parent Class Get Functions INLINE **/


/** Vehicle PARENT CLASS OSTREAM **/

void Vehicle::print( ostream& os) const throw ( invalid_argument )
{
    
    /*Vehicle ID: p1GCFC24K9JZ17963
    Make/Model: Temsa TS45
    Last Inspection: 2008/03/26
    Current Status: In Service*/
    
    if (!os)
    {
        throw invalid_argument("print function in vehicle bad invalid. check file name");
    }
    os << "             "<< endl;
    os << "Vehicle ID:" << id<<endl;
    os << "Make/Model:" << name<<endl;
    os << "Last Inspection:" << inspectionDate<<endl;
    os << "Current Status:" << status;
    if (status == 'a'){os<<" Available"<<endl;};
    if (status == 'm'){os<<" In Maintenence"<<endl;};
    if (status == 's'){os<<" In Service"<<endl;};
    os << "             "<< endl;
    
    

}

/** Vehicle PARENT CLASS ISTREAM **/

void Vehicle::read( istream& is ) throw ( invalid_argument, logic_error )
{
    
    if (!is)
    {
        throw invalid_argument ("read vehicle is stream failed");
    }
    
    string idd,nm;
    Date dat;
    char stat;
   
    is >> idd;
    readDoubleQuotedString(is, nm);
    is >> dat;
    is >> stat;
    
    setID(idd);
    setName(nm);
    setInspectionDate(dat);
    setStatus(stat);
    
    
    
}

void Vehicle::setID( string id) throw ( invalid_argument )
{
    
    int length = 17;
    
    if (length != id.length())
    {
        throw invalid_argument ("Invalid Argument! Length of the Vehicle Number is Not Equal to 17!");
        
    }
    
            
    /** NO SPECIAL CHARACTERS **/

    char good = ' ';
    istringstream goodStrm (id);
    goodStrm >> good;
    
    good = tolower(good);
    
    if ( (good != 'i' ) && (good != 'p') && (good != 'c'))
    {
        throw invalid_argument ("invalid type code");
        
    }
    
    for (int i =0; i<id.size(); i++){
        
    if (!isalpha(id[i]) && !isdigit(id[i]) )
    {
            throw invalid_argument( "invalid type code");

     
    
    }
            
    }
   
        this-> id= id;
    
}
            
void Vehicle::setName( string name)
{
   
    this ->name = name;
    
    
}
void Vehicle::setInspectionDate( Date iDate ) throw ( invalid_argument )
{
  

    inspectionDate = iDate;
    

}
void Vehicle::setStatus( char status ) throw ( invalid_argument )
{
    status = tolower(status);
    
    if ((status != 'm') && (status != 's') && (status != 'a'))
    {
        string status_bad = "invalid status";
        throw invalid_argument (status_bad);
    }
    
    this -> status = status;
    
}

bool Vehicle::readDoubleQuotedString( istream& in, string& s) throw (logic_error, invalid_argument)
{
    string errmessage = " istream in not working ";
    bool rdqs = false;
    
    

    string sdqss;
    
    char cdqss = ' ' ;
    char cdqssy = '"';
    
    
    if (!in)
    {
        throw invalid_argument (errmessage);
    }
    
    
    while (in >> std::noskipws >> cdqss)
    {
        if (cdqss == cdqssy)
        {
            while (in >> std::noskipws >> cdqss && cdqss != cdqssy)
            {
                sdqss += cdqss;
            }
        }
        if (cdqss == cdqssy)
        {
            
            s = sdqss;
            rdqs = true;
            in >> std::skipws;
            break;
            
        }
        if ((rdqs = false))
        {
            throw logic_error(errmessage);
        }
        
    }
    
    return rdqs;
}

/** Individual Class Default Constructor **/
Individual::Individual(): Vehicle()
{

}
Individual::Individual(string idd, string name, Date inspectionDate, char status) : Vehicle(idd, name, inspectionDate, status)
{
    //Body Allowed To Be Empty
}

/** Passenger Class Default Constructor **/
Passenger::Passenger(): Vehicle()
{
    passengerCapacity = 0;
}

Passenger::Passenger(string idd, string name, Date inspectionDate, char status, int cap) : Vehicle(idd, name, inspectionDate, status)
{
    setCapacity(cap);
    
}

/** Passenger Class Get Passenger Capacity **/

int Passenger::getCapacity() const
{
    return passengerCapacity;
}

/** Passenger Class Set Passenger Capacity **/

void Passenger::setCapacity(int cap)
{
    passengerCapacity = cap;

}

/** Passenger Class Ostream **/

void Passenger::print( ostream & os ) const throw ( invalid_argument )
{
    if (!os)
    {
        throw invalid_argument ("passenger print fails");
    }
    Vehicle::print(os);
    
    os<<"Max. Passengers:"<<passengerCapacity<<endl;
    
    

}

/** Passenger Class Instream **/

void Passenger::read( istream & is ) throw ( invalid_argument )
{
        Vehicle::read(is);
    
    
        is >> passengerCapacity;
    
        setCapacity(passengerCapacity);
    
    
}

/** Cargo Child Class DEFAULT CONSTRUCTOR **/

Cargo::Cargo() : Vehicle()
{
    cargoCapacity = 0.0;
}

Cargo::Cargo(string idd, string name, Date inspectionDate, char status, double cap) : Vehicle (idd, name, inspectionDate, status)
{
    setCapacity(cap);
}

/** Cargo Child Class GET CAPACITY **/

double Cargo::getCapacity() const
{
    return cargoCapacity;
}

/** Cargo Child Class SET CAPACITY **/

void Cargo::setCapacity(double cap)
{
    cargoCapacity = cap;
}

/** Cargo Child Class OSTREAM **/

void Cargo::print( ostream& os ) const throw ( invalid_argument )
{
    if (!os)
    {
        throw invalid_argument ("cargo print fails");
    }
    
    Vehicle::print(os);
    
    os<<"Max. Payload:"<<cargoCapacity<<endl;
    os << "             "<< endl;
}

/** Cargo Child Class ISTREAM **/

void Cargo::read( istream& is ) throw ( invalid_argument )
{
   

    Vehicle::read(is);
    
    is >> cargoCapacity;
    
    setCapacity(cargoCapacity);
    
   
}






