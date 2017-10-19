// Napon Krassner (Jett)
// CSC 2430, Homework 8
// 3/12/15
// Due: 3/17/15
// Name: Hobbit
// Description: This is the client file for testing Hobbit overloading and lists.

#include "Hobbit.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void printFamilyStick(Hobbit*);
void printRelation(Hobbit *a, Hobbit *b);

int main()
{
	cout << "**** Welcome to Hobbit Overload and Lists! By Napon Krassner (Jett) ****" << endl << endl;
	//Create Sam and Gaffer, link them
	Hobbit *sam = new Hobbit("Samwise Gamgee", 41, NULL, NULL);
	Hobbit *gaffer = new Hobbit("Gaffer Gamgee", 95, NULL, sam);
	sam->setAntecedent(gaffer);

	//Create Elanor, link to Sam and vice versa
	Hobbit *elanor = new Hobbit("Elanor Gamgee", 0, sam, NULL);
	sam->setDescendent(elanor);
	elanor->setAntecedent(sam);

	// TEST INSERT SIBLINGS

	// Insert at end of list
	cout << "==== Testing insert siblings ====" << endl << endl;
	Hobbit *andy = new Hobbit("Andy Roper", 98, NULL, NULL);
	bool successAndy = gaffer->insert("", andy);
	cout << "Andy inserted to end of Gaffer's siblings list: " << successAndy << endl;

	Hobbit *hamson = new Hobbit("Hamson", 56, NULL, NULL);
	bool successHamson = sam->insert("", hamson);
	cout << "Hamson inserted to end of Samwise's siblings list: " << successHamson << endl;

	Hobbit *halfred = new Hobbit("Halfred", 52, NULL, NULL);
	bool successHalfred = sam->insert("", halfred);
	cout << "Halfred inserted to end of Samwise's siblings list: " << successHalfred << endl;

	Hobbit *may = new Hobbit("May", 45, NULL, NULL);
	bool successMay = sam->insert("", may);
	cout << "May inserted to end of Samwise's siblings list: " << successMay << endl;

	Hobbit *marigold = new Hobbit("Marigold", 38, NULL, NULL);
	bool successMarigold = sam->insert("", marigold);
	cout << "Marigold inserted to end of Samwise's siblings list: " << successMarigold << endl;

	// Insert at given position name
	Hobbit *daisy = new Hobbit("Daisy", 49, NULL, NULL);
	bool successDaisy = sam->insert("May", daisy);
	cout << "Daisy inserted to Samwise's siblings list between May and Marigold: " << successDaisy << endl << endl << endl;

	// TEST SEARCH
	cout << "==== Testing search siblings ====" << endl << endl;
	cout << "Search for May in Samwise's siblings list: " << sam->search("May") << endl;  // true
	cout << "Search for Andy in Samwise's siblings list: " << sam->search("Andy") << endl << endl << endl;  // false


	// TEST COPY
	cout << "==== Testing copy Hobbit with siblings ====" << endl << endl;
	Hobbit *samCopy, *samCopy2;
	samCopy = samCopy2 = sam;
	bool successCopySam = (samCopy == sam);
	bool successCopySam2 = (samCopy2 == sam);
	cout << "sam object has been copied to samCopy object: " << successCopySam << endl;
	cout << "sam object has also been copied to samCopy2 object via multiple assignment: " << successCopySam2 << endl << endl << endl;

	//Test printRelation for all 3 cases
	cout << "==== Testing printRelation ====" << endl;
	cout << endl << "===== Relationship between Samwise and Gaffer: =====" << endl;
	printRelation(sam, gaffer);
	cout << endl << "===== Relationship between Samwise and Elanor: =====" << endl;
	printRelation(sam, elanor);
	cout << endl << "===== Relationship between Gaffer and Elanor: =====" << endl;
	printRelation(gaffer, elanor);

	//Test printFamilyStick on the Gaffer with new ostream overloaded
	cout << endl << endl << endl << "===== Testing printFamilyStick on Gaffer: =====" << endl << endl;
	printFamilyStick(gaffer);

	// TEST DELETE
	cout << endl << endl << endl << "==== Testing delete siblings ====" << endl << endl;
	sam->deleteSib("Halfred");
	cout << "Sam's siblings after Halfred deleted: " << endl << endl;
	cout << sam << endl;

	return 0;
}

//A funciton to print a family "stick"
// Description: Simply traverses hob's descendents, printing their names, use overloaded operator<< to output each line in the family stick
// Parameters: the Hobbit whose family stick we should print (Hobbit *)
// Returns: nothing
void printFamilyStick(Hobbit *hob)
{
	Hobbit *child = hob->getDescendent();
	cout << "The family stick of " << hob->getName() << ": " << endl;

	// cout << setw(35) << hob->getName() << " (" << hob->getAge() <<")" << endl;
	cout << setw(35) << hob << endl;
	while (child != NULL)
	{
		//Using setw for simple formatting
		cout << setw(28) << "|" << endl;
		// cout << setw(35) << child->getName() << " (" << child->getAge() <<")" << endl;
		cout << setw(35) << child << endl;
		child = child->getDescendent();
	}
}

//A funciton to print the relation status between two Hobbits
//Parameters: the Hobbits we will determine relationship on (Hobbit*)
//Returns: nothing
void printRelation(Hobbit *a, Hobbit *b)
{
	//If first Hobbit is parent of the second
	if(a->isParentOf(b))
		cout << a->getName() << " is a parent of " << b->getName() << endl;

	//If second Hobbit is parent of the first
	else if(b->isParentOf(a))
		cout << b->getName() << " is a parent of " << a->getName() << endl;

	//Otherwise, no relation!
	else
		cout << b->getName() << " is not the parent of " << a->getName() << " and vice versa" << endl;
}