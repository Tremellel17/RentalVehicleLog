/*
 *  DateTime.h
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

#ifndef _COSC052_FALL2018_P2_DATE_TIME_H_
#define _COSC052_FALL2018_P2_DATE_TIME_H_

#define DEBUG_DATE //**Commented Out in The Documentation**

#include <iostream>
#include <iomanip>
#include <exception>
#include <stdexcept>
#include <sstream>

using std::invalid_argument;
using std::cout;
using std::endl;

enum MONTH_LIST {DUMMY, JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};

// use minimum values as defaults when necessary

const int MAX_DD[] =  { -1, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int MIN_DD = 1;
const int MIN_YYYY = 1492;
const int MAX_YYYY = 2192;
const int MIN_MM = 1;
const int MAX_MM = 12;

const int MIN_HOUR = 0;
const int MAX_HOUR = 24;    // assumes that 24:00 is valid for midnight, 00:00 would also be valid
const int MIN_MINUTE = 0;
const int MAX_MINUTE = 59;

class Date
    {
              friend std::istream& operator>>(std::istream&, Date&) throw (invalid_argument);
              friend std::ostream& operator<<(std::ostream&, const Date&);
    
            public:
        
              Date(int=MIN_YYYY, int=MIN_MM, int=MIN_DD) throw (invalid_argument); //yyyy, mm, dd
              Date(const Date&) throw (invalid_argument);
              void setDate(int, int, int) throw (invalid_argument);  //yyyy, mm, dd
              void setDate(const Date&) throw (invalid_argument);
              Date operator=(const Date&) throw (std::invalid_argument);
              int getYear() const {return yyyy;}
              int getMonth() const {return mm;}
              int getDay() const {return dd;}
              bool operator ==(const Date&) const;
              bool operator !=(const Date&) const;
              bool operator <=(const Date&) const;
              bool operator <(const Date&) const;
              bool operator >=(const Date&) const;
              bool operator >(const Date&) const;
        
            private:
        
              int yyyy;
              int mm;
              int dd;
    
    }; //Date Declaration

class Time
    {
            friend std::istream& operator>>(std::istream &in, Time &t) throw (invalid_argument);
   
            friend std::ostream& operator<<(std::ostream &os, const Time &t);
 
    private:
        
            int hh;
            int mm;
        
    public:
            Time(int = MIN_HOUR, int = MIN_MINUTE) throw (invalid_argument);

            void setTime(int, int) throw (invalid_argument);

            int getHour() const {return hh;}
        
            int getMinute() const {return mm;}
    
            Time operator=(const Time&);

    }; //Time Declaration

#endif  /*  _COSC052_FALL2018_P1_DATE_TIME_H_  */

