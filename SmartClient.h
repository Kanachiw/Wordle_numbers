#ifndef SMART_CLIENT_CLASS
#define SMART_CLIENT_CLASS

#include "ClientFeedback.h"

/*Smartclient class that handles the game play*/
class SmartClient{
private: 
    /*lockbox object is a data member of this class*/
    LockBox lbObj;
public: 
/*SmartClient functions necessary for gameplay*/
    SmartClient(); 
    SmartClient(int n, int m ); 
    void printCode();
    LockBox clientGuess(); 
    ClientFeedback getFeedback(LockBox &guess);  
    bool isOpened(const ClientFeedback &cfb);
    void openLockBox(); 



};
#include "SmartClient.cpp"
#endif