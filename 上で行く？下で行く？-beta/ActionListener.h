#pragma once

class EventObj;

class ActionListener
{
public:
	virtual void actionPerformed(EventObj *e) =0;
};

