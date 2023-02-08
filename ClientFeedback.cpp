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
/* A global Overloaded operator == that compares responses to guess and returns 
            true if they're equal
    * @param cf1 - ClientFeedback object 1
    * @param cf2 - ClientFeedback object 2 
    * @return true if the clientfeeback of the lockode is the same as the cliet feedback of the gues 
    the client feedback of the lockode would have all correct and 0 incorrects. 
    This is done to ensure we are not accessing the private members of the lockcode class
    */
bool operator==(const ClientFeedback &cf1 , const ClientFeedback &cf2 ){ //first returns the lockbox aand the second returning guess 
    if (cf1.cor == cf2.cor && cf1.inc == cf2.inc) 
    {
        return true;
    }
    return false; 
}
/* constructor initializing integers c for correct and i cor incorrect
* @post a new ClientFeedback object is created 
* @param c for number of correct digits 
* @param i for number of incorrect digits
*/
ClientFeedback::ClientFeedback(int c, int i): cor(c), inc(i)
{
  cor=c; 
  inc=i; 
}

/* Function to return the number of incorrect digits response to a guess
    * @return number of incorrect digits
    */
int ClientFeedback::get_incorrect(){

return inc; 
}
/* Function to return the number of incorrect digits response to a guess
    * @return number of incorrect digits
    */
int ClientFeedback::get_correct(){
return cor; 
}

/* Function to set correct and incorrect digits within a response
    * @param guess - client's guess
    * @param lockcode - randomly generated secret code */
void ClientFeedback::set_values(LockBox &guess, LockBox &lockode){
cor = lockode.correctLocation(guess); 
inc = lockode.incorrectLocation(guess); 
}
/* A Global Overloaded operator << that prints a CLientFeedback response
    * @param ostream out method 
    * @param Client Feedback 
    * @return returns the cout and print the cfleedback response
    
    */
ostream& operator<<(ostream& out, const ClientFeedback &feedback)
{
    out << "The current guess has\ncorrect: " << feedback.cor << endl << "incorrect: " << feedback.inc;
    return out; 
} 

