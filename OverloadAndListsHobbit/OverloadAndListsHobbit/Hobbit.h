// Napon Krassner (Jett)
// CSC 2430, Homework 8
// 3/12/15
// Due: 3/17/15
// Name: Hobbit
// Description: This is the header file for Hobbit class.
//				It contains the Hobbit class with the member variables and function prototypes.

#ifndef _HOBBIT_
#define _HOBBIT_

#include <iostream>
#include <string>

using namespace std;

class Hobbit
{
	// FRIEND FUNCTIONS/OPERATORS

	// Parameters: ostream& for cout, Hobbit object to print
	// Returns: output stream (cout, and cout chain)
	// Description: Overloaded stream insertion operator as friend
	//				Output all Hobbit's info in form:
	//				Name (age), SiblingOne (age), SiblingTwo (age),...
	friend ostream& operator<<(ostream&, const Hobbit*);

public:

	//Parameterized constructor with defaults
	//Parameters: 
	//  The Hobbit's name (a string, default is empty string)
	//  The Hobbit's age (an unsigned short, default is 0, i.e., just born)
	//  The Hobbit's antecedent (a Hobbit*, default is NULL)
	//  The Hobbit's descendent (a Hobbit*, default is NULL)
	//Effects: sets all private member variables to parameters passed in, or
	//  defaults.  
	Hobbit(string = "", unsigned short = 0, Hobbit* = NULL, Hobbit* = NULL);

	//ACCESSORS

	//Accessor to return Hobbit's descendent
	//Parameters: None
	//Returns: a pointer to the Hobbit's descendent (Hobbit*)
	Hobbit *getDescendent() const;

	//Accessor to return Hobbit's antecedent
	//Parameters: None
	//Returns: a pointer to the Hobbit's antecedent (Hobbit*)
	Hobbit *getAntecedent() const;

	//Accessor to return Hobbit's name
	//Parameters: None
	//Returns: the Hobbit's name (a string)
	string getName() const;

	//Accessor to return Hobbit's age
	//Parameters: None
	//Returns: the Hobbit's age (an unsigned short)
	unsigned short getAge() const;

	//MUTATORS

	//Mutator set Hobbit's descendent
	//Parameters: a pointer to the Hobbit's descendent (Hobbit*)
	//Returns: none
	void setDescendent(Hobbit*);

	//Mutator set Hobbit's antecedent
	//Parameters: a pointer to the Hobbit's antecedent (Hobbit*)
	//Returns: none
	void setAntecedent(Hobbit*);

	//Mutator set Hobbit's name
	//Parameters: the Hobbit's name (a string)
	//Returns: none
	void setName(string);

	//Mutator set Hobbit's age
	//Parameters: the Hobbit's age (a unsigned short)
	//Returns: none
	void setAge(unsigned short);

	// Parameters: string for name, hobbit object to insert
	// Returns: true if name is in the list, false otherwise
	// Description: Insert sibling into the list directly after a given name in the parameter
	//				if name is "" insert to the end
	//				if name is given but not contained in the list, don't insert and return false
	//				if name is given and is in the list, insert and return true
	bool insert(string, Hobbit*);

	// Parameters: string for name
	// Returns: true if name is found, false otherwise
	// Description: Delete sibling from the list by name from param
	//				if sibling not found, don't delete and return false
	//				if found, delete sibling and return true
	bool deleteSib(string);


	//UTILITY FUNCTIONS

	//Utility function to determine if one Hobbit is parent of another
	//Parameters: the potential child (Hobbit*)  of this Hobbit
	//Returns: true if this is parent of parameter
	//  false if this is not parent of parameter
	bool isParentOf(Hobbit *);

	// Parameters: string name for key
	// Returns: true if name is found, false otherwise
	// Description: Search the siblings list for the string (key) in the parameter.
	bool search(string);

	// Parameters: Hobbit object
	// Returns: Hobbit object
	// Description: overloaded operator= for multiple assignment and selft-assignment.
	//				creates a deep copy of Hobbit object and assign it to another Hobbit object.
	const Hobbit* operator=(Hobbit*);

	// Parameters: Hobbit object
	// Returns: 
	// Description: Overloaded operator== checks and returns true if
	//				Hobbit's name, age, and all siblings names are identical in same order.
	//				False otherwise.
	bool operator==(Hobbit*);

private:

	//A pointer to *one* of the Hobbit's children (NULL if none)
	Hobbit *descendent;

	//A pointer to *one* of the Hobbit's parents (NULL if none)
	Hobbit *antecedent;

	//The Hobbit's full name (first last)
	//TODO: this member variable will be MyString
	string name;

	//The Hobbit's age (can't be negative!)
	unsigned short age;

	// A pointer to the next sibling in the list
	// Last sibling always point to NULL
	Hobbit *siblings;

	// Private functions
	// Parameters: Hobbit object
	// Returns: nothing
	// Descrtiption: Deep copy function to copy the Hobbit object and its member variables
	//					to a new Hobbit object.
	void deepCopy(Hobbit*);
};
#endif