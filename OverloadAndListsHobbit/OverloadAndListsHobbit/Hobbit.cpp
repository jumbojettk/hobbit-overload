// Napon Krassner (Jett)
// CSC 2430, Homework 8
// 3/12/15
// Due: 3/17/15
// Name: Hobbit
// Description: This is the implementation file for Hobbit class.
//				It contains the Hobbit class function definitions of the Hobbit object
//				to be implemented by the client.

#include "Hobbit.h"
#include <iostream>
#include <string>

using namespace std;

// Friend functions
ostream& operator<<(ostream& osObject, const Hobbit* hob)
{
	osObject << hob->name << " (" << hob->age << ")";  // first Hobbit
	while (hob->siblings != NULL)  // all the siblings
	{
		hob = hob->siblings;
		osObject << ", " << hob->name << " (" << hob->age << ")";
	}

	return (osObject);
}


// CONSTRUCTOR

Hobbit::Hobbit(string n, unsigned short a, Hobbit *an, Hobbit *d)
{
	antecedent = an;
	descendent = d;
	siblings = NULL;  // when create, automatically points to NULL, which makes the last sibling point to NULL
	name = n;

	//Note: will always be >= 0, since we are using
	// an unsigned short.  If you use a signed int for some
	// reason, need to make sure it is >=0!
	age = a;
}

// ACCESSORS

Hobbit* Hobbit::getDescendent() const
{
	return descendent;
}

string Hobbit::getName() const
{
	return name;
}

unsigned short Hobbit::getAge() const
{
	return age;
}

Hobbit* Hobbit::getAntecedent() const
{
	return antecedent;
}


// MUTATORS


void Hobbit::setAntecedent(Hobbit *a)
{
	antecedent = a;
}

void Hobbit::setDescendent(Hobbit *d)
{
	descendent = d;
}

void Hobbit::setName(string n)
{
	name = n;
}

void Hobbit::setAge(unsigned short a)
{
	//No need to check for age >=0
	// since working with unsigned short
	// BUT if you went "off script"
	// for the assignment and used an int, 
	// would need to check
	age = a;
}

bool Hobbit::insert(string positionName, Hobbit* hobSib)
{
	Hobbit *tmp = this;
	bool success = false;

	if (positionName == "")  // insert to end
	{
		while (tmp->siblings != NULL)
		{
			tmp = tmp->siblings;
		}
		tmp->siblings = hobSib;  // add to the siblings at the end
		success = true;
	}
	else if (this->search(positionName))  // if found in the list
	{
		while (tmp->name != positionName)  // move to the position of the name
		{
			tmp = tmp->siblings;
		}
		Hobbit *holdTmpSib = tmp->siblings;  // hold the next obj
		tmp->siblings = hobSib;  // add obj to next obj
		tmp = tmp->siblings;  // move to the added obj
		tmp->siblings = holdTmpSib;  // connect the rest of the list
		success = true;
	}
	else
	{
		success = false;
	}

	return success;
}

bool Hobbit::deleteSib(string hobSibName)
{
	Hobbit *tmp = this;  // temp
	bool found = false;
	if (this->search(hobSibName))
	{
		while (tmp->siblings->name != hobSibName)  // move to the sibling before the one to delete
		{
			tmp = tmp->siblings;
		}
		Hobbit *deleteTmp = tmp->siblings; // hold the sibling to delete
		tmp->siblings = deleteTmp->siblings;// point current sibling to the one after the delete one
		deleteTmp = NULL;  // point to NULL

		found = true;
	}
	else
		found = false;

	return found;
}

// UTILITIES

bool Hobbit::isParentOf(Hobbit *child)
{
	//Is this the parent of child?
	//Simply check child's antecedent,
	// (and doesn't hurt to check descendent of this too)
	if((child->getAntecedent() == this) && (this->getDescendent() == child))
		return true;
	return false;
}

bool Hobbit::search(string nm)
{
	Hobbit *tmp = this;
	bool found = false;
	while (tmp->name != nm && tmp->siblings != NULL)  // keep going till found or till end of list
	{
		tmp = tmp->siblings;  // keep going through the next siblings
	}
	if (tmp->name == nm)  // if found
	{
		found = true;
	}
	return found;
}

const Hobbit* Hobbit::operator=(Hobbit* rightHob)
{
	if (this == rightHob)  // if same
	{
		return this;
	}
	else  // if not same
	{
		// deep copy
		deepCopy(rightHob);
	}
}

bool Hobbit::operator==(Hobbit* rightHob)
{
	bool same = false;
	Hobbit *tmpLeft = this;
	Hobbit *tmpRight = rightHob;
	if (this->name == rightHob->name && this->age == rightHob->age)  // same name and age
	{
		while (tmpLeft->siblings == tmpRight->siblings && tmpLeft->siblings != NULL && tmpRight->siblings != NULL)  // same all siblings name and same order till end
		{
			tmpLeft = tmpLeft->siblings;
			tmpRight = tmpRight->siblings;
		}

		// check if reached end after the loop
		if (tmpLeft-siblings == NULL && tmpRight->siblings == NULL)
			same = true;
	}

	return same;
}

void Hobbit::deepCopy(Hobbit* originalHob)
{
	Hobbit *tmp = originalHob;  // temp
	Hobbit *thisTmp = this;

	// copy name
	thisTmp->name = tmp->name;

	// copy age
	thisTmp->age = tmp->age;

	// copy all siblings
	while (tmp->siblings != NULL)
	{
		thisTmp->siblings = tmp->siblings;
		tmp = tmp->siblings;
		thisTmp = thisTmp->siblings;
	}
	thisTmp->siblings = NULL;
}