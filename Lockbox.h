#ifndef LOCKBOX_CLASS
#define LOCKBOX_CLASS

#include <iostream>
#include <vector>
using namespace std;
/*class LockBox that stores a secret lock code as a vector
and contains different functions that analyze guesses at that lock code
	*/
class LockBox {

  private:
    //private data members

    vector<int> lockcode;
  
    int length, digits; 

  public:
    /*
    create an new LockBox object and sets the inital price to zero 
	  or a client supplied value
    @post A new LockBox object is created
	  @param n is the length of the code 
  	@param d is the range of each digit [0 - (d-1)]*/
    LockBox(int n = 0, int m = 0);


    /*
    returns the correct Length of the lockcode 
    @return int length >= 0  */
    int getLength() const;

    /*
    returns the correct range of digits of the lockcode 
    @return int digits >= 0 */
    int getDigits() const; 
    
    /*
    returns the lockcode(vector of int) member with the private class 
    @return vector<int> lockcode. where the lockode.size()>= 0 */
    vector<int> getCode ()const;
    
    /*create an operation to set the vector code 
    using a random generator 
    @post Creates a lockode that assigns a 
    value to the vector (lockcode)*/
    void LockCode(); 
  
     /*create an operation to print the lockcode
     member of the class. This iterates through a 
     vector printing out each position 
     @post prints a vector (lockcode)*/
    void printLockode(); 
    
     /*create an operation to set the vector code 
    using a  user keyboard 
    @post Creates a lockode that assigns a 
    value to the vector (lockcode)*/
    void guess();

    /*create an operation find the amount of 
    guesses in the right location 
    @param takes in a Lockbox object code
    (can be a guess or another lockcode )
    @return the amount in the correct location */
    int  correctLocation(const LockBox &code);
     /*create an operation find the amount of 
    correct  guesses in the  wrong location 
    @param takes in a Lockbox object code
    (can be a guess or another lockcode )
    @return the amount in the incorrect location  */
    int incorrectLocation( const LockBox &code);

   
};
 #include "Lockbox.cpp"
#endif