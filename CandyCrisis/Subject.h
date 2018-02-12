#pragma once
#ifndef SUBJECT_H
#define SUBJECT_H
#include <list>
#include "Observer.h"
using namespace std;

/**
*@class Subject
* A Subject will notify its observers that a change has been made, so that the Observers can update themselves
* accordingly
*/

class Subject {
public:
	virtual void attach(Observer* obs);
	virtual void detach(Observer* obs);
	virtual void notify();

	Subject();
private:
	list<Observer*> *_observers;

};
#endif