#include <iostream>
#include <algorithm>
#include <cstdlib> 
#include <vector>
#include <iomanip> 
#include <stdexcept>
#include "SmartClient.h"

/* main function thay calls a SmartClient object and also calls 
the OpenLockBox() function which takes client thru the game */
int main(){
    
    cout <<"_____________________PART B_________________"<<endl;
    bool customize;
    SmartClient sc;
   cout << "Would you like to customize your Lockbox length and range of digits\n\
   press 0 for No and 1 for yes ";
   cin >> customize;
   if (customize){
    int n , d;
    cout<<"Please enter the Length "; 
    cin>> n ; 
    cout<<"Please enter the Range of digits  "; 
    cin>> d;
    SmartClient sc(n,d);
    }  
    sc.openLockBox(); 
    
}