#include "EventObj.h"



void EventObj::addActionListener(ActionListener * listener)
{
	Listeners.push_back(listener);
}

void EventObj::eventFire()
{
	for (auto i : Listeners)i->actionPerformed(this);
}
