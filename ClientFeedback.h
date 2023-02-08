/*********************************************************
* author           : Rajani Tabor and Kanachi Weli
* date             : February 8th, 2023
* file name        : ClientFeedback.h
* purpose          : class that stores the number of correct/incorrect
                        digits response to a guess
***********************************************************/

#ifndef CLIENT_FEEDBACK_CLASS
#define CLIENT_FEEDBACK_CLASS
#include <iostream>
#include <vector>
#include "Lockbox.h"
using namespace std;


class ClientFeedback{
    private:
    /* class data members*/
     int cor, inc; 
    
    public:
    
    ClientFeedback(int c = 0, int i = 0 );
    int get_incorrect();
    int get_correct(); 
    void set_values(LockBox &guess, LockBox &lockode); 
   
    friend bool operator==(const ClientFeedback &cf1 , const ClientFeedback &cf2 );

    friend ostream& operator<<(ostream& out, const ClientFeedback &feedback );


};

#include "ClientFeedback.cpp" 

#endif 
