#include <iostream>
#include <vector>
#include <iomanip> 
#include <stdexcept>
//#ifndef LOCKBOX_CLASS
//#define LOCKBOX_CLASS

using namespace std;

class LockBox {

  private:

    vector<int> code;
    int length, digits; 

  public:

    LockBox(int n, int m);

    void LockCode(int n, int m); 

    void guess();

    LockBox correctLocation(const LockBox &guess);

    int incorrectLocation(const LockBox &guess);

    int getCode () const;
};

LockBox :: LockBox(int n, int m) : length(n), digits(m) // allow the 
{

  LockCode(n, m);
  
}

void LockBox :: LockCode(int n, int m) {
  
    vector<int> code; //initializes a vector of integer 
  
    for (int i = 0; i < n; i++){ // create a loop to create a vector size of n 
  
      code.push_back(rand() % m-1); // generate each individal digit from the range of [0,m-1]
      
    }
}


void LockBox :: guess() {
//input guess and store as vector
  vector<int> guess; 
  int num; 
  
     for (int i = 0; i < length; i++){ // create a loop to create a vector size of n 
      cin>> num; 
      if (num > (digits-1)){
        throw"range error"; 
      }
      guess.push_back(num); // generate each individal digit from the range of [0,m-1]
      
    }
}


LockBox::LockBox correctLocation(const LockBox &guess) {

  count1 = // number of correct digits 

  for (int i = 0; i < n; i++) {
    if (guess != code) {
      
    }
    return count1;
  }
}

LockBox::LockBox incorrectLocation(const LockBox &guess) {

  count2 = //number of correct digits in wrong location

  for (int i = 0, i < n; i++) {
    if (guess != code) {
      
    }
    return count2; 
  } 
}


int main () {


  
}