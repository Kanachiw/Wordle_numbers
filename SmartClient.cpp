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
    */
    SmartClient::SmartClient() {
        LockBox obj(5, 10); 
       
        lbObj = obj; 
    }
    /*Create an object with integers n and m   
    * @post A new SmartClient object is created 
    * @param n the value of the length of the code
    * @param m the value for the range of digits in the code
    */
    SmartClient::SmartClient(int n, int m ) {
        LockBox obj(n, m); 
       
        lbObj = obj; 
    }

    /*Function to print out secret lock code in the lockbox
    * @post prints the values in the lockcode object
    */
    void SmartClient::printCode() {
        lbObj.printLockode(); 
    }

    /*Function to read a lockcode from the keyboard    
                and return a ClientFeedback object
    * @pre digits provided by client must be within the range of m-1.
                if they're not, throw range error
    * @return A ClientFeedback object which represents the client's guess
    */
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
    /*Function is passed a Lockbox guess code and returns a ClientFeedback object 
    * @param guess - client's guess which is a lockbox object
    * @return A ClientFeedback object representing correct and incorrect value of 
    *           the guess code to the correct value
    */
    ClientFeedback SmartClient::getFeedback(LockBox &guess) {
        ClientFeedback cf; 
        cf.set_values(guess, lbObj); 
        return cf; 

    }  
    /*Function is passed a ClientFeedback object and determines
                if the secret code has been guessed
    * @param cfb is a ClientFeedback object representing the response 
                to the client's guess
    * @return true if secret code has been correctly guessed
    */
    bool SmartClient::isOpened(const ClientFeedback &cfb) {
       return (getFeedback(lbObj) == cfb);  
       


    }
    /*Function to initialize a random lock code, print the secret 
            code to the screen, get a guess from the user, and print the 
            number of correct/incorrect digits until the client guesses 
            the right code
    * @post prints the lockcode/guesses and directs the client experience
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

