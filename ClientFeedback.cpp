#include <iostream>
#include <algorithm>
#include <cstdlib> 
#include <vector>
#include <iomanip> 
#include <stdexcept>

bool operator==(const ClientFeedback &cf1 , const ClientFeedback &cf2 ){ //first returns the lockbox aand the second returning guess 
    if (cf1.cor == cf2.cor && cf1.inc == cf2.inc) 
    {
        return true;
    }
    return false; 
}

ClientFeedback::ClientFeedback(int c, int i): cor(c), inc(i)
{
  cor=c; 
  inc=i; 
}


int ClientFeedback::get_incorrect(){

return inc; 
}
int ClientFeedback::get_correct(){
return cor; 
}
void ClientFeedback::set_values(LockBox &guess, LockBox &lockode){
cor = lockode.correctLocation(guess); 
inc = lockode.incorrectLocation(guess); 
}

ostream& operator<<(ostream& out, const ClientFeedback &feedback)
{
    out << "The current guess has\ncorrect: " << feedback.cor << endl << "incorrect: " << feedback.inc;
    return out; 
} 

