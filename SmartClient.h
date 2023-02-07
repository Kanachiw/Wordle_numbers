#ifndef SMART_CLIENT_CLASS
#define SMART_CLIENT_CLASS

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
#include "SmartClient.cpp"
#endif