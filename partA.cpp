/****************************************************************************
* author           : Rajani Tabor and Kanachi Weli
* date             : February 8th, 2023
* file name        : partA.cpp
* purpose          : Main function that creates a LockBox object, generates a 
                        lock code, and prints out a response to the guess 
                        using the CorrectLocation() and IncorrectLocation()
                        functions 
****************************************************************************/

#include <iostream>
#include <cstdlib> 
#include "Lockbox.h"





int main() {
/* Part A : main program that creates a Lockbox object, generates a lock code,
and calls functions correctLocation() and incorrectLocation
in order to provide a response to the guess*/

cout <<"_____________________PART A_________________" << endl;
cout << "Welcome to a Lockbox To begin you have to\
enter the length of the lockcode and the range of \
which you want it to be randomly generated " << endl;
int l , d; 
cout <<"Enter the length "; 
cin >> l;

cout <<"Enter the max range of digits "; 

cin >> d; 
/* lockbox object representing the guess' length and range of digits*/
LockBox  obj(l , d);
/*lockbox object that generates a secret code*/
obj.LockCode();
/* lockbox object that prints the secret code*/
obj.printLockode(); 
LockBox obj2(l, d); 

// creates a try statement for error handling when the wrong value is entered for the guess 
bool success = false;
while(!success)
{
try
{
   obj2.guess();
   cout<< "For your guess Lockbox "; 
   obj2.printLockode(); 
   success = true; 
}
catch(const exception& e)
{
    cerr << e.what() << '\n';
    cout<<"Please guess again"<<endl; 
}

}



/*lockbox objects that print the number of digits in the correct location
and the number of correct digits in the incorrect location*/
cout << "correct location " << obj.correctLocation(obj2) << endl;
cout << "incorrect location " << obj.incorrectLocation(obj2) << endl;
}

