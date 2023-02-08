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
   //do we want to let them put in the length and digits for the lock code in the smart client? 
    SmartClient sc;  
    sc.openLockBox(); 
    
}