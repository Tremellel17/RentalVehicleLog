/*
 *  exceptions.cpp
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

#include "exceptions.h"

/*The bad_vehicle_code class.

This is a user-defined exception class derived from the system exception class invalid_argument.
 
As with any derived class, bad_vehicle_code inherits all of the members of its base class invalid_argument.

Also, as with any derived class bad_vehicle_code has the option to add any members it may need.
 
However, in this case, the derived class really does not need any additional members. We simply want a new class to provide additional specificity when throwing exceptions.

Class bad_vehicle_code does provide its own constructor having a single string parameter.
 
We shall use this string parameter as the argument to a call to the base class constructor via a member initialization list in the heading of the implementation code for bad_vehicle_code's constructor. */


bad_vehicle_code::bad_vehicle_code(string msg):invalid_argument(msg)
{
    msg = " ";
    
};
