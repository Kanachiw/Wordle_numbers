#ifndef CLIENT_FEEDBACK_CLASS
#define CLIENT_FEEDBACK_CLASS
#include <iostream>
#include <vector>
#include "Lockbox.h"
using namespace std;

/* CilentFeedback class that stores the number of correct/incorrect
digits response to a guess*/
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
