/***********************************************************
* author           : Rajani Tabor and Kanachi Weli
* date             : February 8th, 2023
* file name        : SmartClient.cpp
* purpose          : Implementation of the SmartClient class
************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdlib> 
#include <vector>
#include <iomanip> 
#include <stdexcept>


    /*Create a new SmartClient object, which initializes values n and m at 5 and 10
            and initializes a Lockbox object 
    * @post A new SmartClient object is created
    * @param lbobj represents a Lockbox object
    */
    SmartClient::SmartClient() {
        LockBox obj(5, 10); 
       
        lbObj = obj; 
    }
    /*Create a new SmartClient object, which is passed values n and m 
            that can be read from the keyboard, and also initializes lockbox object
    * @post A new SmartClient object is created 
    * @param n represents the length of the code 
    * @param m represents the range of the digits from [0 - (d-1)]
    */
    SmartClient::SmartClient(int n, int m ) {
        LockBox obj(n, m); 
       
        lbObj = obj; 
    }

    /*Function calls lockcode function and lockbox object in order to print 
            randomly generated lock code
    * @param lbobj represents a lockbox object
    * @post prints secret lock code
    */
    void SmartClient::printCode() {
        lbObj.printLockode(); 
    }

    /*Function uses lockbox to get the length and digits of the guess,
            read a guess from the keyboard, and return number of correct digits in the 
            correct location and number of correct digits in the incorrect location
            using lockbox object
    * @param lbobj which represents a lockbox object
    * @return guessCode which represents the client's guess
    * */
    LockBox SmartClient::clientGuess() {
        LockBox guessCode(lbObj.getLength(), lbObj.getDigits());
        bool success = false; 
        while(!success)
        {
        try
        {
        guessCode.guess(); 
        cout<< "For your guess Lockbox "; 
        guessCode.printLockode(); 
        success = true; 
        }
        catch(const exception& e)
        {
        cerr << e.what() << '\n';
        cout<<"Please guess again"<<endl; 
        }
        }
        
        return guessCode; 

    } 
    /*Function is passed a Lockbox guess code and returns a 
            ClientFeedback object representing the guess in terms of 
            number of correct/incorrect digits
    * @param guess representing client's guess from Lockbox class
    * @return ClientFeedback object representing client's guess
    */
    ClientFeedback SmartClient::getFeedback(LockBox &guess) {
        ClientFeedback cf; 
        cf.set_values(guess, lbObj); 
        return cf; 

    }  
    /*Function uses ClientFeedback object to determine whether 
            the client has guessed the correct code or not
    * @param cfb is a ClientFeedback object 
    * @param lbobj is a Lockbox object
    * @return true if Lockbox object equals ClientFeedback object, 
            meaning the correct code has been guessed 
    */
    bool SmartClient::isOpened(const ClientFeedback &cfb) {
       return (getFeedback(lbObj) == cfb);  
       


    }
    /*Function to initialize a random lock code, print the secret 
            code to the screen, get a guess from the user, and print the 
            number of correct/incorrect digits until the client guesses 
            the right code
    * @post displays the secret code to the screen
    * @post displays to the screen whether or not the client has guessed the right code
    */
    void SmartClient::openLockBox(){
        /*Uses a lockbox object to randomize the secret code*/
       lbObj.LockCode();

       /*Calls the printCode function to print secret code to the screen*/
       printCode(); 

       /*Gets the client's guess at the code*/
       ClientFeedback ans;
       do{

       /*Iteratively inputs the guess via the ClientGuess() function 
            and outputs the response via the getFeedback() function*/
       cout << endl << "Please guess the code below" << endl; 
       LockBox a = clientGuess();
      
       ans = getFeedback(a); 
       /* Uses the isOpened() function to determine whether the box has been
            opened and thus the while loop should end*/
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

