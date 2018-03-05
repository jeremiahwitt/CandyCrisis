#pragma once
#ifndef OBSERVER_H
#define OBSERVER_H

/**
*@Class Observer
* An observer keeps track of its subject's state. Whenever the state of the subject 
* gets updated the observer will perform some sort of action.
*/
class Observer {
public:
	Observer() {};
	virtual void update() = 0;
	virtual ~Observer() {};
};

#endif