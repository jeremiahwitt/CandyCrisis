#include "stdafx.h"
#include "Subject.h"
#include "Observer.h"

void Subject::attach(Observer *obs) {
	_observers->push_back(obs);
}

void Subject::detach(Observer * obs) {
	_observers->remove(obs);
}

void Subject::notify() {
	list<Observer*>::iterator i = _observers->begin();
	for (; i != _observers->end(); ++i) {
		(*i)->update();
	}
}

Subject::Subject() {
	_observers = new list<Observer*>;
}
