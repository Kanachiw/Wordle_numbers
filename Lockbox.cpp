
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <cstdlib> 
#include <vector>
#include <iomanip> 


/*
    create an new LockBox object and sets the inital price to zero 
	  or a client supplied value
    @post A new LockBox object is created
	  @param n is the length of the code 
  	@param d is the range of each digit [0 - (d-1)]*/
LockBox::LockBox(int n, int m): length(n), digits(m) // allow the 
{
  length = n;
  digits = m;
}


/*
returns the correct Length of the lockcode 
@return int length >= 0  */
int LockBox ::  getLength() const
{
  return length;

}
/*
returns the correct range of digits of the lockcode 
@return int digits >= 0 */
int LockBox :: getDigits() const 
{
 return digits; 
}

/*create an operation to set the vector code 
using a random generator 
@post Creates a lockode that assigns a 
value to the vector (lockcode)*/
void LockBox :: LockCode() {
  
    //initializes a vector of integer 

    srand( time(0) ); //ensured a random number is generated each time 

    for (int i = 0; i < length; i++){ // create a loop to create a vector size of n 
      int item = rand() % digits; //generates a # from 0-(digits -1)
      lockcode.push_back(item); // generate each individal digit from the range of [0,m-1]
    }
}

/*create an operation to set the vector code 
    using a  user keyboard 
    @post Creates a lockode that assigns a 
    value to the vector (lockcode)*/
void LockBox :: guess() { 
//input guess and store as vector
  
  int num; 
    // creates a vector of user keyboard entered values 

     for (int i = 0; i < length; i++){ // create a loop to create a vector size of n 
      cout << "enter digit " << i << " from 0 : " << digits-1 << endl;;
      cin >> num; // takes in each position in thse vector 
      if (num > (digits - 1)){
       throw out_of_range("ERROR: Not within range! (you entered a value greater or Equal to " + to_string(digits) +")\n"); //ensure that digits are not greater than the range 
      }
      lockcode.push_back(num); // generate each individal digit from the range of [0,m-1]
  
    }

    
}



int LockBox::correctLocation(const LockBox &code) {

  int c1 = 0;/* creats a counter variable thats increments 
  based on the value in the correct location*/

  for (int i = 0; i < length; i++) {

    if (lockcode[i] == code.lockcode[i]){ /*compares the vector values at each position 
    if it's true it increments counter by 1 */
      c1++; 
    }
    
  }
  //returns the counter 
  return c1; 
}

 /*create an operation find the amount of 
  correct  guesses in the  wrong location 
  @param takes in a Lockbox object code(can be a guess or another lockcode )
  @return the amount in the incorrect location*/
int LockBox::incorrectLocation( const LockBox &code){
  // creats a counter variable thats increments  based on the number of correct digits in incorrect location
  int c2=0;

  /*create a vecotor of unique guesses*/
  vector <int> unique; 
  
    /*creates a for loop that loops through
    the length of thr lockode in the object lockbox*/ 
   for (int i = 0; i < length; i++) {
  
    /*checks to see if the guess is not in the unique vector, and in the lockode 
    However it's not in the same position as the lockode*/
    if ((count (unique.begin(), unique.end(), code.lockcode[i]))==0 
    && (count (lockcode.begin(), lockcode.end(), code.lockcode[i]))>0 
    &&lockcode[i]!= code.lockcode[i])
    {  
      /*if all the conditions are true therefore the guess gets added to the 
      unique vector */
       unique.push_back(code.lockcode[i]); 

       // counter function gets incremented by 1 
        c2++;     
    }   
   }
  return c2; 
}
/*
returns the lockcode(vector of int) member with the private class 
@return vector<int> lockcode. where the lockode.size()>= 0 */
vector<int> LockBox::getCode () const{
  return lockcode;
}

/*create an operation to print the lockcode
member of the class. This iterates through a 
vector printing out each position 
@post prints a vector (lockcode)*/
void LockBox::printLockode(){
    cout << "The Lockode is :";

    // iterates thrroght the vector code and prints each vector position 
for (int i = 0; i < length; i++){ // create a loop to create a vector size of n 
            cout <<lockcode[i];
        }
    cout << endl; 
}

