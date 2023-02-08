/*********************************************************************
* author           : Rajani Tabor and Kanachi Weli
* date             : February 8th, 2023
* file name        : ClientFeedback.h - ClientFeedback header file
* purpose          : class that stores the number of correct/incorrect
                        digits response to a guess
*********************************************************************/

#ifndef CLIENT_FEEDBACK_CLASS
#define CLIENT_FEEDBACK_CLASS
#include <iostream>
#include <vector>
#include "Lockbox.h"
using namespace std;


class ClientFeedback{
    private:
     int cor, inc; 
    
    public:
    
    /* Create an object and set the initial integers i and c to 0
    * @post A new ClientFeedback object is created 
    * @param c number of correct digits 
    * @param i for number of incorrect digits  
    */
    ClientFeedback(int c = 0, int i = 0 );

    /* Function to return the number of incorrect digits response to a guess
    * @return number of incorrect digits
    */
    int get_incorrect();

    /* Function to return the number of incorrect digits response to a guess
    * @return number of incorrect digits
    */
    int get_correct(); 

    /* Function to set correct and incorrect digits within a response
    * @param guess - client's guess
    * @param lockcode - randomly generated secret code */
    void set_values(LockBox &guess, LockBox &lockode); 
   
    /* Overloaded operator == that compares responses to guess and returns 
            true if they're equal
    * @param cf1 - ClientFeedback object 1
    * @param cf2 - ClientFeedback object 2 
    */
    friend bool operator==(const ClientFeedback &cf1 , const ClientFeedback &cf2 );

    /* Overloaded operator << that prints a CLientFeedback response
    * @param feedback - object representing the correct and incorrect digits
    */
    friend ostream& operator<<(ostream& out, const ClientFeedback &feedback );


};

#include "ClientFeedback.cpp" 

#endif
