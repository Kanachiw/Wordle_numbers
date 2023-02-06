#include "ClientFeedback.h"


bool operator == (const ClientFeedback &cf1 , const ClientFeedback &cf2 ){
    if (cf1.cor == cf2.cor && cf1.inc == cf2.inc) 
    {
        return true;
    }
    return false; 
}

int ClientFeedback::get_incorrect(){

return inc; 
}
int ClientFeedback::get_correct(){
return cor; 
}
void ClientFeedback:: set_correct(LockBox &guess, LockBox &lockode  ){
inc = lockode.correctLocation(guess); 

}
void ClientFeedback:: set_incorrect(LockBox &guess, LockBox &lockode ){
inc = lockode.incorrectLocation(guess); 
}

ostream& operator<< (ostream& out, const ClientFeedback& feedback)
{
    // Since operator<< is a friend of the Point class, we can access Point's members directly.
    out << "The current guess has \n correct: " << feedback.cor << endl <<"incorrect: " << feedback.inc;
    return out; 
} 

