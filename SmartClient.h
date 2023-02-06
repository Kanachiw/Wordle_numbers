#ifndef SMART_CLIENT_CLASS
#define SMART_CLIENT_CLASS
#include "Lockbox.h"
#include "ClientFeedback.h"


class SmartClient{
private: 
    LockBox lbObj;
public: 
    SmartClient(); 
    SmartClient(int n, int m ); 
    void printCode();
    LockBox clientGuess(); 
    ClientFeedback getFeedback(LockBox &guess);  
    bool isOpened(const ClientFeedback &cfb);
    void openLockBox(); 



};

     SmartClient :: SmartClient (){
        LockBox obj(5, 10); 
       
        lbObj =obj; 
    }

    SmartClient :: SmartClient (int n, int m ){
        LockBox obj(n,m); 
       
        lbObj= obj; 
    }
    void SmartClient :: printCode(){
        for (int i = 0; i < lbObj.getLength(); i++){ // create a loop to create a vector size of n 
            cout<<lbObj.getCode()[i]<<endl;
        }
    }

    LockBox SmartClient :: clientGuess(){
        LockBox Guess; 
        Guess.guess(); 
        return Guess; 

    } 
    ClientFeedback SmartClient :: getFeedback( LockBox &guess){
        ClientFeedback cf; 
        cf.set_correct(lbObj, guess); 
        cf.set_incorrect(lbObj, guess); 

    }  
    bool SmartClient:: isOpened(const ClientFeedback &cfb){


    }
    void SmartClient :: openLockBox(){
       lbObj.LockCode();
       printCode(); 
       do {
       clientGuess();
       cout<< ClientFeedback()<<endl; }

       while (!isOpened(ClientFeedback())); 

    }


#endif