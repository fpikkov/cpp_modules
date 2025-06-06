# CPP MODULES

## OVERVIEW

This repository includes the various C++ modules from 42 curriculum. Each module introduces us to new concepts and ways of working with C++.
Up until this point all our projects have been written in C with multiple constraints whereas we have a lot more freedom in approaching the challenges of these C++ projects.

## GOALS
### CPP00
0. Capitalize the input received as arguments.
1. Create a phonebook which stores up to 8 contacts. Entering more contacts will overwrite the indices starting from the beginning.
2. Create a file (Account.cpp) which will replicate the output as shown in the log file.

### CPP01
0. Implement a class which will announce itself when instantiated.
1. Following the previous exercise, create a funtion which will allocate N amount of classes.
2. Introduction to references and comparing their use to variables and pointers.
3. Create three classes, HumanA will take in the Weapon class in it's constructor whereas HumanB may be instantiated without said class. Changing the Weapon class should reflect the same changes in the Human classes.
4. Create a program which will take an infile, string to replace and the replaced string. Introduction to file streams.
5. Practice the use of pointers to member functions and avoid using if/else if/else statements.
6. Practice fall-through cases in switch statements.

### CPP02
0. Start implementing classes in the Orthodox Canonical Form. Simple setup for a class which will handle fixed point numbers.
1. Implement more member functions and add an overload of the insertion operator.
2. Implement comparison, arithmetic and increment/decrement operator overloads. Add member functions which will return the minimum or maximum fixed point number between two parameters.
3. Using the fixed point number class, implement a class for storing x and y coordinates. Then use said class in a function to check whether a point is inside of a triangle constructed from vertices A, B and C.

### CPP03
0. Begin this module by implementing a base class which will later be used to create derived classes.
1. Create a derived class which will inherit the members of the base class. The derived class will override the ClapTrap::attack method and use different values to initialize member variables of the base class. One new method is included in the derived class.
2. Similarly to the previous exercise, create a derived class from the base class and initialize values unique to the new derived class. An additional method is included.
3. Diamond inheritance problem: create a class which inherits from both the previous derived classes. Variables are initialized based on a combination of the derived classes initial values. Example of variable shadowing.

### CPP04
0. Introduction to polymorphic classes. Demonstration of member function overloads.
1. Use heap allocated memory to store variables within classes. Make sure to create deep copies of the allocated variables instead of shallow copies.
2. Introduction to the concept of abstract classes which cannot be instantiated on their own.
3. Implement multiple pure abstract classes (commonly called interfaces), an abstract class and concrete classes. Multiple classes will include pointers to heap allocated objects which will require proper cleanup using the delete keyword.

### CPP05
0. Create a class which throws a custom exception based on wrong parameters.
1. Implement a second class with it's own exceptions which get thrown when
the class is initialized with invalid parameters.
2. Make the class from the previous exercise abstract and implement three concrete classes based off of it. The concrete classes will have some unique functionality.
3. Create a class which will construct one of the three previously created ones based on input parameters. The Intern class will attempt to match up the Form class type in a loop, return a valid enum which is then used in a switch case to allocate and return a pointer to the class which was asked for.

### CPP06
0. Create a class which can not be instantiated. Member function accepts a string which then gets converted into char, int, float and double. Introduction to static_cast.
1. Create a class which can not be instantiated. Member function will either serialize a struct into uintptr_t or deserialize it. Introduction to reinterpret_cast.
2. Create a base class and three derived classes along with member function in the base class whih lets you identify the actual type of the class given as either pointer to base class or reference. Introduction to dynamic_cast.

### CPP07
0. Create templates for swapping two values and finding min/max between two values. The two arguments should be of the same type and support all of the comparison operators.
1. Create a functiion template iter which takes in three paramateres (address of an array, length of the array, function pointer which gets called on each element of the array) and provide enough code to demonstrate the functionality of such a function template.
2. Make a class template named Array which will construct an array based on the type used to instantiate the class. When instantiated with no constructor parameters the array will be empty. When using the overloaded constructor then a size of the array can be specified. The Array class should be accessible with the [] operator by being both readable and modifyiable. If an out of range index is accessed, the class should throw an exceptiion.

## LICENSE

This repository is licensed under GNU GPL v3.0.
This means you may use this repository for any purpose (personal, educational, commercial), modify the code and distribute copies of the code.
However you MAY NOT distribute without the source code, use the code in proprietary software or apply a more restrictive license to the code.
