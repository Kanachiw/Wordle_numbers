/*********************************************************
* author           : Rajani Tabor and Kanachi Weli
* date             : February 8th, 2023
* file name        : PartB.cpp
* purpose          : Main function that calls a SmartClient object and the 
                        OpenLockBox() function which takes a client through
                        the game
***********************************************************/

#include <iostream>
#include <algorithm>
#include <cstdlib> 
#include <vector>
#include <iomanip> 
#include <stdexcept>
#include "SmartClient.h"

int main(){
    
    cout <<"_____________________PART B_________________"<<endl;
   //do we want to let them put in the length and digits for the lock code in the smart client? 
    SmartClient sc;  
    sc.openLockBox(); 
    
}