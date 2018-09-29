#pragma once
#include"ActionListener.h"
#include<list>
using namespace std;
class EventObj
{
protected:
	EventObj() {};
	list<ActionListener*> Listeners;
	void eventFire() {
		for (auto i : Listeners)i->actionPerformed(this);
	};
public:
	void addActionListener(ActionListener* listener) {
		Listeners.push_back(listener);
	};
};

