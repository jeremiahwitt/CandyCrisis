#pragma once
#ifndef OBSERVER_H
#define OBSERVER_H

/**
*@Class Observer
* An observer keeps track of an object's state. Whenever the state of the object is updated,
* the observer updates itself and carries out the necessary steps.
*/
class Observer {
public:
	Observer() {};
	virtual void update() = 0;
	virtual ~Observer() {};
};

#endif