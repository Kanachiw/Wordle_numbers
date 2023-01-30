#include <iostream>
#include <vector>
#include <iomanip> 
#include <stdexcept>
#include <iostream>
#include <algorithm>
//#ifndef LOCKBOX_CLASS
//#define LOCKBOX_CLASS

using namespace std;

class LockBox {

  private:

    vector<int> lockcode;
  
    int length, digits; 

  public:

    LockBox(int n=0, int m=0);

    int getLength();

    int getDigits(); 

    void LockCode(); 

    void guess();

    int  correctLocation(const LockBox &guess);

    int incorrectLocation( const LockBox &guess);

    int getCode () const;
};

LockBox :: LockBox(int n, int m) : length(n), digits(m) // allow the 
{
  length= n;
  digits = m;
}

int LockBox ::  getLength()
{
  return length;

}

int LockBox :: getDigits()
{
 return digits; 
}

//create a lockode 
void LockBox :: LockCode() {
  
     //initializes a vector of integer 
  
    for (int i = 0; i < length; i++){ // create a loop to create a vector size of n 
      int item = rand() % (digits-1);
      lockcode.push_back(item); // generate each individal digit from the range of [0,m-1]
      cout<<item<<endl;
    }
}


void LockBox :: guess() { 
//input guess and store as vector
  
  int num; 
  
     for (int i = 0; i < length; i++){ // create a loop to create a vector size of n 
      cout<<"enter digit "<<i<<" from 0: [" <<length<<"-1]"<<endl;;
      cin >> num; 
      if (num > (digits-1)){
        throw "range error"; 
      }
      lockcode.push_back(num); // generate each individal digit from the range of [0,m-1]
      
    }

    
}



int LockBox :: correctLocation(const LockBox &guess) {

  int c1= 0;// couts the  number of correct digits 

  for (int i = 0; i < length; i++) {

    if (lockcode[i] ==guess.lockcode[i]){
      c1++; 
    }
    
  }
  return c1; 
}
int LockBox:: incorrectLocation( const LockBox &guess){
int c2=0;//number of correct digits in wrong location

 //create a vecotor of unique guesses 
  vector<int> temp =guess.lockcode;
  vector <int> uniqueGuess; 

  for (int i = 0; i < length; i++) {

    if (find(uniqueGuess.begin(),uniqueGuess.end(), temp[i])!= uniqueGuess.end()) {
      uniqueGuess.push_back(temp[i]); 
    }
  
  }

  for(int i=0; i<uniqueGuess.size(); i++){

    if (find(lockcode.begin(),lockcode.end(), uniqueGuess[i])!= lockcode.end()) {
      c2++; 
    }
  }
  
  return c2; 

}


int main () {
LockBox obj(3,7);
int length = obj.getLength();
int digits = obj.getDigits();
obj.LockCode();
LockBox obj2(length, digits); 
obj2.guess();
cout << obj.correctLocation(obj2);
cout<< obj.incorrectLocation(obj2);
  
}