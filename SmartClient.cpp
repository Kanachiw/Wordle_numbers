#include <iostream>
#include <algorithm>
#include <cstdlib> 
#include <vector>
#include <iomanip> 
#include <stdexcept>


/*SmartClient constructor 1, which is passed no parameters and 
initializes values n and m at 5 and 10 respectively.
Constructor also initializes lockbox object*/
    SmartClient::SmartClient() {
        LockBox obj(5, 10); 
       
        lbObj = obj; 
    }
/*SmartClient constructor 2, which is passed values n and m 
that can be read from the keyboard. also initializes lockbox object*/
    SmartClient::SmartClient(int n, int m ) {
        LockBox obj(n, m); 
       
        lbObj = obj; 
    }
/*calls lockcode function and lockbox object in order to print 
randomly generated lock code*/
    void SmartClient::printCode() {
        lbObj.printLockode(); 
    }
/*uses lockbox to get the length and the digits of the guess,
then reads the guess from the keyboard and returns how many 
digits are correct and how many digits are correct but in the 
wrong location, using lockbox object*/
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
    /*function is passed a Lockbox guess code and returns a 
    ClientFeedback object representing the guess in terms of 
    number of correct/incorrect digits*/
    ClientFeedback SmartClient::getFeedback(LockBox &guess) {
        ClientFeedback cf; 
        cf.set_values(guess, lbObj); 
        return cf; 

    }  
    /*function uses ClientFeedback object to determine whether 
    the client has guessed the correct code or not*/
    bool SmartClient::isOpened(const ClientFeedback &cfb) {
       return (getFeedback(lbObj) == cfb);  
       


    }
    /*function to initialize a random lock code, print the secret 
    code to the screen, gets a guess from the user, and prints the 
    number of correct/incorrect digits until the client guesses 
    the right code*/
    void SmartClient::openLockBox(){
    /*uses a lockbox object to randomize the secret code*/
       lbObj.LockCode();
       /*calls the printCode function to print secret code to the screen*/
       printCode(); 
       /*gets the client's guess at the code*/
       ClientFeedback ans;
       do{
        /*iteratively inputs the guess via the ClientGuess() function 
        and outputs the response via the getFeedback() function*/
       cout << endl << "Please guess the code below" << endl; 
       LockBox a = clientGuess();
      
       ans = getFeedback(a); 
       /* uses the isOpened() function to determine whether the box has been
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

