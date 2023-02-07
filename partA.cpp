#include <iostream>
#include <cstdlib> 
#include "Lockbox.h"



int main() {
cout<<"_____________________PART A_________________"<<endl;
cout<< "Welcome to a Lockbox To beigin you have to\
enter the length of the lockcode and the range of \
which you want it to be randomly geneated "<<endl;
int l , d; 
cout<<"Enter the length "; 
cin >> l;

cout<<"Enter the max range of digits "; 

cin >> d; 
LockBox  obj(l , d);
obj.LockCode();
obj.printLockode(); 
LockBox obj2(l, d); 
obj2.guess();


cout <<"correct location " << obj.correctLocation(obj2)<<endl;
cout<<"incorrect location "<< obj.incorrectLocation(obj2)<<endl;
  
}

