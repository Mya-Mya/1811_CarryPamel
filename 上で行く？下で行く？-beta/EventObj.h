#pragma once
#include"ActionListener.h"
#include<list>
using namespace std;
class EventObj
{
protected:
	EventObj() {};
	list<ActionListener*> Listeners;
	void eventFire();
public:
	void addActionListener(ActionListener* listener);
};

