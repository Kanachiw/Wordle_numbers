#include <iostream>
#include <cstdlib> 
#include "Lockbox.h"


/* main program that creates a Lockbox object, generates a lock code,
and calls functions correctLocation() and incorrectLocation
in order to provide a response to the guess*/
int main() {
cout <<"_____________________PART A_________________" << endl;
cout << "Welcome to a Lockbox To beigin you have to\
enter the length of the lockcode and the range of \
which you want it to be randomly geneated " << endl;
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
obj2.guess();

/*lockbox objects that print the number of digits in the correct location
and the number of correct digits in the incorrect location*/
cout << "correct location " << obj.correctLocation(obj2) << endl;
cout << "incorrect location " << obj.incorrectLocation(obj2) << endl;
  
}

