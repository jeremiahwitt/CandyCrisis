#include "stdafx.h"
#include "Subject.h"
#include "Observer.h"


/**
 * Creates a new Subject with an empty list of Observers
 */
Subject::Subject() {
	_observers = new list<Observer*>;
}

/**
 * Attach an Observer to the list of Observers observing the Subject.
 */
void Subject::attach(Observer *obs) {
	_observers->push_back(obs);
}

/**
 * Remove the given Observer from the list of Observers observing the Subject.
 */
void Subject::detach(Observer * obs) {
	_observers->remove(obs);
}

/**
 * Notify all Observers that the state of the Subject has changed!
 */
void Subject::notify() {
	list<Observer*>::iterator observer = _observers->begin();
	for (; observer != _observers->end(); ++observer) {
		(*observer)->update();
	}
}
