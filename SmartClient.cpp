#include <iostream>
#include <algorithm>
#include <cstdlib> 
#include <vector>
#include <iomanip> 
#include <stdexcept>



    SmartClient::SmartClient() {
        LockBox obj(5, 10); 
       
        lbObj = obj; 
    }

    SmartClient::SmartClient(int n, int m ) {
        LockBox obj(n, m); 
       
        lbObj = obj; 
    }
    void SmartClient::printCode() {
        lbObj.printLockode(); 
    }

    LockBox SmartClient::clientGuess() {
        LockBox guessCode(lbObj.getLength(), lbObj.getDigits());
        
        guessCode.guess(); 
        return guessCode; 

    } 
    ClientFeedback SmartClient::getFeedback(LockBox &guess) {
        ClientFeedback cf; 
        cf.set_values(guess, lbObj); 
        return cf; 

    }  
    bool SmartClient::isOpened(const ClientFeedback &cfb) {
       return (getFeedback(lbObj) == cfb);  
       


    }
    void SmartClient::openLockBox(){
       lbObj.LockCode();
       printCode(); 
       ClientFeedback ans;
       do{
       cout << endl << "Please guess the code below" << endl; 
       LockBox a = clientGuess();
      
       ans = getFeedback(a); 
       
       if (isOpened(ans)){
        cout << "Congrats you opened the box" << endl; 
       }
       else{
        cout << "Wrong, try again! " << endl; 
       }
       cout << ans << endl;

       }
       while(!isOpened(ans)); 

    

    }

