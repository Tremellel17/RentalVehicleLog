/*
 *  DateTime.cpp
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

#include "DateTime.h"

/* Date Class:
   Represents a date in year, month, & day format.
 
   Year, Month, and Day are stored in an integer.
 
   Uses Overloaded Relation Operators (Bool) to compare the order of Dates.
*/

//**** DATE CLASS IMPLEMENTATION CODE BELOW ****

//CONSTRUCTORS CALL OVERLOADED SET DATE FUNCTIONS.

Date::Date ( int year,
             int month,
             int day) throw (invalid_argument)
{
#ifdef Debug_Date
#endif
    setDate(year, month, day);
#ifdef Debug_Date
#endif
    
}

Date::Date (const Date & dt) throw (invalid_argument)
{
    setDate( dt.yyyy, dt.mm, dt.dd);
    
    
}

//SET FUNCTIONS.

void Date::setDate(int year, int month, int day) throw (invalid_argument)
{
    
    yyyy = MIN_YYYY;
    mm = MIN_MM;
    dd = MIN_DD;
    
    bool goodDate = true;
    
    std::ostringstream combinedStrm;
    combinedStrm << "\tException thrown from ";
    combinedStrm << "Date::setDate(" << mm << ", " << dd << ", " << yyyy << ")\n";
    std::string combinedMessage = combinedStrm.str();
    
    // use stringstream object to create better error messages
    std::ostringstream monthRange;
    monthRange << "\tException thrown from ";
    monthRange << "Date::setDate(" << mm << ", " << dd << ", " << yyyy << ")\n";
    monthRange << "Entered: " << mm << ", ";
    monthRange << "Valid: ";
    
    
    monthRange << "[" << MIN_MM << ", " << MAX_MM << "]\n";
    
    // the complete error message is a combination of a constant generic message
    // and the variable part that was created above using the stringstream
    std::string monthErrorMsg = monthRange.str();
    
    
    std::ostringstream dayRange;
    dayRange << "\tException thrown from ";
    dayRange << "Date::setDate(" << mm << ", " << dd << ", " << yyyy << ")\n";
    
    dayRange << "Entered: " << dd << ", ";
    dayRange << "Valid: ";
    dayRange << "[" << MIN_DD << ", " << MAX_DD << "]\n";
    
    // the complete error message is a combination of a constant generic message
    // and the variable part that was created above using the stringstream
    std::string dayErrorMsg = dayRange.str();
    
    
    std::ostringstream yearRange;
    yearRange << "\tException thrown from ";
    yearRange << "Date::setDate(" << mm << ", " << dd << ", " << yyyy << ")\n";
    yearRange << "Entered: " << yyyy << ", ";
    yearRange << "Valid: ";
    yearRange << "[" << MIN_YYYY << ", " << MAX_YYYY << "]\n";
    
    // the complete error message is a combination of a constant generic message
    // and the variable part that was created above using the stringstream
    std::string yearErrorMsg = yearRange.str();
    
    
    
    if ( month < MIN_MM || month > MAX_MM )
    {
        
        combinedMessage += monthErrorMsg;
        
        goodDate= false;
        
        throw invalid_argument(monthErrorMsg);
        
        
    }
    
    
    
    if (month == JAN){
        if ( day < MIN_DD || day > MAX_DD[1])
        {
            
            combinedMessage += dayErrorMsg;
            goodDate = false;
            
            throw invalid_argument(dayErrorMsg);
            
            
        }
    }
    
    if (month == FEB){
        if ( day < MIN_DD || day > MAX_DD[2])
        {
            
            combinedMessage += dayErrorMsg;
            goodDate = false;
            
            throw invalid_argument(dayErrorMsg);
            
            
        }
    }
    
    if (month == MAR){
        if ( day < MIN_DD || day > MAX_DD[3])
        {
            combinedMessage += dayErrorMsg;
            goodDate = false;
            
            throw invalid_argument(dayErrorMsg);
            
            
        }
    }
    
    if (month == APR){
        if ( day < MIN_DD || day > MAX_DD[4])
        {
            combinedMessage += dayErrorMsg;
            goodDate = false;
            
            throw invalid_argument(dayErrorMsg);
            
            
        }
    }
    if (month == MAY){
        if ( day < MIN_DD || day > MAX_DD[5])
        {
            combinedMessage += dayErrorMsg;
            goodDate = false;
            
            throw invalid_argument(dayErrorMsg);
            
        }
    }
    if (month == JUN){
        if ( day < MIN_DD || day > MAX_DD[6])
        {
            combinedMessage += dayErrorMsg;
            goodDate = false;
            
            throw invalid_argument(dayErrorMsg);
        }
    }
    if (month == JUL){
        if ( day < MIN_DD || day > MAX_DD[7])
        {
            combinedMessage += dayErrorMsg;
            goodDate = false;
            
            throw invalid_argument(dayErrorMsg);
        }
    }
    if (month == AUG){
        if ( day < MIN_DD || day > MAX_DD[8])
        {
            combinedMessage += dayErrorMsg;
            goodDate = false;
            
            throw invalid_argument(dayErrorMsg);
        }
    }
    if (month == SEP){
        if ( day < MIN_DD || day > MAX_DD[9])
        {
            combinedMessage += dayErrorMsg;
            goodDate = false;
            
            throw invalid_argument(dayErrorMsg);
        }
    }
    if (month == OCT){
        if ( day < MIN_DD || day > MAX_DD[10])
        {
            combinedMessage += dayErrorMsg;
            goodDate = false;
            
            throw invalid_argument(dayErrorMsg);
        }
    }
    if (month == NOV){
        if ( day < MIN_DD || day > MAX_DD[11])
        {
            combinedMessage += dayErrorMsg;
            goodDate = false;
            
            throw invalid_argument(dayErrorMsg);
        }
        
    }
    if (month == DEC){
        if ( day < MIN_DD || day > MAX_DD[12])
        {
            combinedMessage += dayErrorMsg;
            goodDate = false;
            
            throw invalid_argument(dayErrorMsg);
        }
    }
    
    if ( year < MIN_YYYY || year > MAX_YYYY )
    {
        combinedMessage += dayErrorMsg;
        goodDate = false;
        
        throw invalid_argument(dayErrorMsg);
    }
    
    if (goodDate != true)
    {
        throw std::invalid_argument(combinedMessage);
    }
    
    yyyy = year;
    mm = month;
    dd = day;
}

void Date::setDate(const Date & dt) throw (invalid_argument)
{
    setDate(dt.yyyy, dt.mm, dt.dd);
    yyyy=dt.yyyy;
    mm=dt.mm;
    dd=dt.dd;
    
}

//GET FUNCTIONS ARE INLINE.

bool Date::operator==(const Date& dt) const
{
    bool valid = false;
    
    valid = this -> mm == dt.mm  && this -> yyyy == dt.yyyy && this -> dd == dt.dd;
    
    return valid;
    
};
bool Date::operator !=(const Date& dt) const
{
    bool valid = false;
    
    valid = this -> mm != dt.mm && this -> yyyy != dt.yyyy && this -> dd != dt.dd;
    
    
    return valid;
};
bool Date::operator <=(const Date & dt) const
{
    bool valid = false;
    
    if (this -> yyyy < dt.yyyy)
    {
        valid = true;
    }
    if (this-> yyyy == dt.yyyy && this -> mm < dt.mm)
    {
                valid = true;
    }
    
    if (this-> yyyy == dt.yyyy && this -> mm == dt.mm && this -> dd < dt.dd)
    {
        valid = true;
    }
    if (this-> yyyy == dt.yyyy && this -> mm == dt.mm && this -> dd == dt.dd)
    {
        valid = true;
    }
    return valid;
};

bool Date::operator < (const Date & dt) const
{
    bool valid = false;
    if (this -> yyyy < dt.yyyy)
    {
        valid = true;
    }
    if (this-> yyyy == dt.yyyy && this -> mm < dt.mm)
    {
        valid = true;
    }
    
    if (this-> yyyy == dt.yyyy && this -> mm == dt.mm && this -> dd < dt.dd)
    {
        valid = true;
    }
 
    return valid;
};

bool Date::operator >=(const Date & dt) const
{
    bool valid = false;
    
    if (this -> yyyy > dt.yyyy)
    {
        valid = true;
    }
    if (this-> yyyy == dt.yyyy && this -> mm > dt.mm)
    {
        valid = true;
    }
    
    if (this-> yyyy == dt.yyyy && this -> mm == dt.mm && this -> dd > dt.dd)
    {
        valid = true;
    }
    if (this-> yyyy == dt.yyyy && this -> mm == dt.mm && this -> dd == dt.dd)
    {
        valid = true;
    }
    
    return valid;
};

bool Date::operator >(const Date & dt) const
{
    bool valid = false;
    
    
    if (this -> yyyy > dt.yyyy)
    {
        valid = true;
    }
    if (this-> yyyy == dt.yyyy && this -> mm > dt.mm)
    {
        valid = true;
    }
    
    if (this-> yyyy == dt.yyyy && this -> mm == dt.mm && this -> dd > dt.dd)
    {
        valid = true;
    }
    
    
    return valid;
};

Date Date::operator=(const Date & dt) throw (std::invalid_argument)
{
    if (this != & dt)
    {
        setDate(dt.getYear(), dt.getMonth(), dt.getDay());
    }
    
    return *this;
    
};

//DATE CLASS ISTREAM FRIEND:

std::istream& operator>>(std::istream& in, Date& dt) throw (invalid_argument)
{

    bool valid = false;
    char ch ;
    int year;
    int month;
    int day;
    
    
    if (!in)
    {
        std::string date_bad = "invalid argument date valid istream false";
        throw invalid_argument (date_bad);
    
    }
    
    try{
    
    in >> year;
    in >> ch;
        
        
    if (!in) { valid = true; }
        
    in >> month;
    in >> ch;
        
    if (!in) { valid = true; }
        
    in >> day;
    if (!in) { valid = true; }
        
   // dt.yyyy = yyyy;
   // dt.mm = mm ;
   // dt.dd = dd;
    if (valid)
    {
        std::string runtime_bad = "runtime argument date valid istream false";
        throw std::runtime_error(runtime_bad);
    }
    dt.setDate(year, month, day);
        
    }
    
    catch (std::invalid_argument i)
    {
        std:: cout << "invalid argument in date istream";
        std::cout << i.what() <<endl;
    }
    
    catch (std::runtime_error r)
    {
        std::cout << "runtime error in date istream";
        std::cout << r.what() <<endl;
    }
    
    catch (...)
    {
        std::cout<<"uncaught exception in date istream";
        throw;
    
    }
    return in;

}

        
//DATE CLASS OSTREAM FRIEND:
        
std::ostream& operator<<(std::ostream& out, const Date& dt)
{
    
        out << std::setfill('0');
        out << std::setw(2) << dt.yyyy << ":";
        out << std::setw(2) << dt.dd << ":";
        out << std::setw(2) << dt.mm;
        
        out << std::setfill(' ');
        
    
    return out;
}


//*** TIME CLASS CODE IMPLEMENTAION BELOW ***


Time::Time (int hour, int minute) throw (invalid_argument)
{

    setTime(hour, minute);
    
    
} //END constructor with parameters for Time class




void Time::setTime(int hour, int minute) throw (invalid_argument)
{
    
    std::ostringstream errStrm;
    
    hh = MIN_HOUR;
    mm = MIN_MINUTE;
    
    bool valid = false;
    
    if ( hour < MIN_HOUR || minute < MIN_MINUTE || hour > MAX_HOUR || minute > MAX_MINUTE )
    {
        
        valid = true;
    }
    else if ( hour == MAX_HOUR && minute > 0 )
    {
       
        valid = true;
    }
    
    if (valid)
    {
        
        
        errStrm << "ERROR: in method Time::setTime( " << hour << ", " << minute << " )\n";
        
        errStrm << "hour set to MIN_HOUR (" << MIN_HOUR << "), ";
        
        errStrm << "minute set to MIN_MINUTE (" << MIN_MINUTE << ")\n";
        
        std::string errTime = errStrm.str();
        
        std::invalid_argument one (errTime);
        throw one;
    }
    
    hh = hour;
    mm = minute;
    
} //END member function Time::setTime



std::istream& operator>>(std::istream &in, Time &t)  throw (invalid_argument)
{

    
    char ch;
    int hour = -1;
    int minute = -1;
    
    
    std::string errInStream = "ERROR: in Time >>\n";
    
    errInStream += "ERROR: ISTREAM OPERATOR FAILED";
    
    if (!in)
    {
        throw std::invalid_argument(errInStream);
    }
    
    try
    {
        bool valid = false;
        
        in >> hour;
        if (!in) { valid = true; }
        
        in >> ch;
        if (!in) { valid = true; }
        
        in >> minute;
        if (!in) { valid = true; }
        
        
        if(valid)
        {
            std::string errInStream = "WARNING: in Time class overloaded operator>>\n";
            errInStream += "the input stream is in a failed state, ";
            errInStream += "possible attempt to read past end of file, ";
            errInStream += "time object data members not updated ...\n";
            throw std::runtime_error(errInStream);
        }
        
        t.setTime(hour, minute);
    }
    catch (std::runtime_error w)
    {
        std::cout << "WARNING: ";
        std::cout << "caught runtime_error exception in Time class overloaded operator>>\n";
        std::cout << w.what() << endl;
        
        }
        catch (std::invalid_argument w)
        {
            std::cout << "ERROR: ";
            std::cout << "caught invalid_argument exception in Time class overloaded operator>>\n";
            std::cout << w.what() << endl;

            throw;
        }
        catch (...)
        {
            std::cout << "ERROR: unknown exception caught in Time class overloaded operator>>\n";
            throw;
        }
        
        return in;
        
        } //END overloaded stream extraction operator for Time class
        
        
    
        
std::ostream& operator<<(std::ostream &out, const Time &t)
        {
            out << std::setfill('0');
            
            out << std::setw(2) << t.hh << ":";
            out << std::setw(2) << t.mm;
            
            out << std::setfill(' ');
            
            return out;
            
        } //END overloaded stream insertion operator for Time class
        
        
        
        
Time Time::operator=(const Time & t)
        {
            if (this != & t)
            {
                
                setTime(t.hh, t.mm);
            }
            
            return *this;
            
        }
        
        





