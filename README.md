                                                              Project Lock Box
In this project, you will write a complete program that allows the client to open a lock box used for storage of precious belongings. The Lock Box System has the following features:

The client is prompted to enter two integers: the combination lock code length n, and the range of digits m.
The lock box system generates a random set of numbers and sets them as the initial lock code: a random sequence of n digits, each of which is in the range [0, m-1].
When the client wants to open the box, they are prompted to enter a guess, an n-digit sequence.
The lock box system responds by printing two values that indicate how close the guess is to the lock code. The first response value is the number of digits that are the right digit in the right location. The second response value is the number of digits that are the right digit in the wrong location.
For example, if the lock code is 1,2,3,4,5 and the guess is 5,0,3,2,6, the response would be 1,2 because one digit (3) is the right digit in the right location, and two digits (2 and 5) are the right digits in the wrong locations.

Note that no digit in the lock code or guess is counted more than once. If the lock code is 1,2,3,4,5 and the guess is 2,1,2,2,2, the response is 0,2. If the lock code is 3,2,3,3,3 and the guess is 1,3,3,4,5, the response is 1,1.

The client is prompted to continue entering guesses. The client successfully opens the box if the correct lock code is entered in ten or fewer guesses, and otherwise the lock box system disables the input locking the box permanently.
Your programs should be modular and should make full use of object-oriented programming techniques. Each class should clearly separate its interface from its implementation. Use member functions to implement all commonly used operations. Every function should be documented to describe its function, assumptions and limitations. Each function should validate its inputs and print error messages if the inputs are not correct.

 

Project Lock Box Part a
In the first part of the project,

Implement the class LockBox which stores the lock code as a vector and contains
the LockBox class declaration,
a constructor that is passed values n and m and initialize the LockBox object,
a function that generates the lock code randomly,
a function correctLocation(…) which is passed a guess as a parameter, i.e. another LockBox object, and which returns the number of correct digits in the correct location.
a function incorrectLocation(…) which is passed a guess as a parameter (i.e. another LockBox object and returns the number of correct digits in the incorrect location. No digit in the guess or the code should be counted more than once.
Implement a function main() which creates a LockBox object, generates a lock code, and prints out the result of calling correctLocation(…) and incorrectLocation(…) for three sample guess codes ((5,0,3,2,6), (2,1,2,2,2), (1,3,3,4,5)). Please print the secret lock code as well.
 

Project Lock Box Part b
In the second part of the project, complete the program that allows a user (client) to outsmart the Lock Bos System.

Implement the class ClientFeedback which stores the response to a guess (number correct and number incorrect), and which includes:
a constructor,
functions to set and get the individual stored values within a response,
an overloaded operator == that compares responses and returns true if they are equal (global),
an overloaded operator << that prints a response (global).
Implement the class SmartClient which handles the playing of the game, and which includes:
a LockBox object as a data member,
two constructors to initialize the game: one constructor is passed values of n and m that were read from the keyboard, and the other constructor is passed no parameters and uses default values for n = 5 and m = 10,
a function that prints the secret lock code,
a function clientGuess() that reads a guess from the keyboard and returns a LockBox object that represents the guess,
a function getFeedback() that is passed one lock code (a guess code), and returns a ClientFeedback object,
a function isOpened() that is passed a ClientFeedback object and returns true if the ClientFeedback indicates that the lock box has been opened (correct lock code has been entered/guessed).
a function openLockBox() that initializes a random lock code, prints it to the screen, and then iteratively gets a guess from the user and prints the response (using ClientFeedback’s overloaded operator <<) until either the lock box disables or the client opens the box.
Implement a function main() which initializes a SmartClient object and then calls openLockBox(). The version of the code you submit should print the secret lock code to the screen to help us test your code.
