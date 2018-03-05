#pragma once
#ifndef SUBJECT_H
#define SUBJECT_H
#include <list>
#include "Observer.h"
using namespace std;

/**
*@class Subject
* A Subject will notify the Observers that are observing it when its state
* has changed
*/

class Subject {
public:
	Subject();
	virtual void attach(Observer* obs);
	virtual void detach(Observer* obs);
	virtual void notify();
private:
	list<Observer*> *_observers;
};
#endif