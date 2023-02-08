/************************************************************************
* author           : Rajani Tabor and Kanachi Weli
* date             : February 8th, 2023
* file name        : SmartClient.h - SmartClient header file
* purpose          : Class that handles the playing of the lock code game
************************************************************************/

#ifndef SMART_CLIENT_CLASS
#define SMART_CLIENT_CLASS

#include "ClientFeedback.h"

/*Smartclient class that handles the game play*/
class SmartClient{
private: 
    /*lockbox object is a data member of this class*/
    LockBox lbObj;
public: 

    SmartClient(); 

    /* Create an object with integers n and m
    * @post a new SmartClient object is created
    * @param n the value of the length of the code
    * @param m the value for the range of digits in the code 
    */
    SmartClient(int n, int m ); 

    /* Function to print out secret lock code*/
    void printCode();

    /* Function to read a guess from the keyboard
            and return a ClientFeedback object 
    * @pre digits provided by client must be within range of m-1.
            if they're not, throw range error
    * @return A ClientFeedback object representing the guess
    */
    LockBox clientGuess(); 

    /* Function that is passed a guess code and returns a ClientFeedback object
    * @param guess - client's guess at secret code
    * @return A ClientFeedback object representing the guess
    */
    ClientFeedback getFeedback(LockBox &guess);  

    /* Function that is passed a ClientFeedback object and determines if the 
             secret code has been guessed
    * @param cfb - ClientFeedback object representing the response to a 
             client's guess               
    * @return true if secret code has been correctly guessed       
    */
    bool isOpened(const ClientFeedback &cfb);

    /* Function to initialize a random secret code, print code to the screen
            iteratively get a guess from user, and print a ClientFeedback 
            object representing the guess until the code has been guessed 
            correctly
    * @post prints the secret code to the screen
    * @return A ClientFeedback object representing the guess        
    */
    void openLockBox(); 



};
#include "SmartClient.cpp"
#endif