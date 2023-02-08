/**************************************************************
* author           : Rajani Tabor and Kanachi Weli
* date             : February 8th, 2023
* file name        : ClientFeedback.cpp
* purpose          : Implementation of the ClientFeedback class
***************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdlib> 
#include <vector>
#include <iomanip> 
#include <stdexcept>
/* overloaded bool operator that determines if two ClientFeedback objects
are equal or not*/
bool operator==(const ClientFeedback &cf1 , const ClientFeedback &cf2 ){ //first returns the lockbox aand the second returning guess 
    if (cf1.cor == cf2.cor && cf1.inc == cf2.inc) 
    {
        return true;
    }
    return false; 
}
/* constructor initializing integers c for correct and i cor incorrect*/
ClientFeedback::ClientFeedback(int c, int i): cor(c), inc(i)
{
  cor=c; 
  inc=i; 
}

/* returns incorrect integer*/
int ClientFeedback::get_incorrect(){

return inc; 
}
/* returns correct integer*/
int ClientFeedback::get_correct(){
return cor; 
}
/*sets int cor to equal the correctLocation() function
in the LockBox class 
set int inc to equal the incorrectLocation() function
in the LockBox class*/
void ClientFeedback::set_values(LockBox &guess, LockBox &lockode){
cor = lockode.correctLocation(guess); 
inc = lockode.incorrectLocation(guess); 
}
/* uses overloaded operator << to output the number of correct
and incorrect digits using the ClientFeedback objects*/
ostream& operator<<(ostream& out, const ClientFeedback &feedback)
{
    out << "The current guess has\ncorrect: " << feedback.cor << endl << "incorrect: " << feedback.inc;
    return out; 
} 

