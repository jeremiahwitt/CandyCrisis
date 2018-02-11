// TODO clean this up!
#include "stdafx.h"
#include "Subject.h"
#include "Observer.h"

/**
* Attaches a new Observer to the Subject.
*@param Observer pointer, pointing to the Observer to be attached
*/
void Subject::attach(Observer *obs) {
	_observers->push_back(obs);
}

/**
* Detaches the desired Observer from the subject.
*@param Observer pointer, pointing to the desired Observer
*/
void Subject::detach(Observer * obs) {
	_observers->remove(obs);
}

/**
* Will notify all attached Observers that its state has changed.
*/
void Subject::notify() {
	list<Observer*>::iterator i = _observers->begin();
	for (; i != _observers->end(); ++i) {
		(*i)->update();
	}
}

/**
* Default Subject constructor. Initializes _observers as a new list.
*/
Subject::Subject() {
	_observers = new list<Observer*>;
}
