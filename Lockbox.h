#ifndef LOCKBOX_CLASS
#define LOCKBOX_CLASS

#include <iostream>
#include <vector>
using namespace std;

class LockBox {

  private:

    vector<int> lockcode;
  
    int length, digits; 

  public:

    LockBox(int n = 0, int m = 0);

    int getLength() const;

    int getDigits() const; 

    void LockCode(); 

    void printLockode(); 
    
    void guess();

    int  correctLocation(const LockBox &guess);

    int incorrectLocation( const LockBox &guess);

    vector<int> getCode ()const;
};
 #include "Lockbox.cpp"
#endif