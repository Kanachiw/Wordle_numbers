
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <cstdlib> 
#include <vector>
#include <iomanip> 

LockBox::LockBox(int n, int m): length(n), digits(m) // allow the 
{
  length= n;
  digits = m;
}

int LockBox ::  getLength() const
{
  return length;

}

int LockBox :: getDigits() const 
{
 return digits; 
}

//create a lockode 
void LockBox :: LockCode() {
  
     //initializes a vector of integer 
    srand(time(0));
    for (int i = 0; i < length; i++){ // create a loop to create a vector size of n 
      int item = rand() % digits;
      lockcode.push_back(item); // generate each individal digit from the range of [0,m-1]
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

    if (lockcode[i] == guess.lockcode[i]){
      c1++; 
    }
    
  }
  return c1; 
}

int LockBox:: incorrectLocation( const LockBox &guess){
int c2=0;//number of correct digits in wrong location

 //create a vecotor of unique guesses 
  vector <int> unique; 
  

   for (int i = 0; i < length; i++) {
   
    if ((count (unique.begin(), unique.end(), guess.lockcode[i]))==0 
    && (count (lockcode.begin(), lockcode.end(), guess.lockcode[i]))>0 
    &&lockcode[i]!= guess.lockcode[i] )
    { 
       unique.push_back(guess.lockcode[i]); 
        c2++; 
        
    }
    
   }

  return c2; 
}
vector<int> LockBox:: getCode () const{
  return lockcode;
}

void LockBox:: printLockode(){
    cout<< "The Lockode is :";
for (int i = 0; i < length; i++){ // create a loop to create a vector size of n 
            cout<<lockcode[i];
        }
    cout<<endl; 
}
