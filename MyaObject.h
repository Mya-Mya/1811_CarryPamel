#pragma once
class MyaO
{
public:
	MyaO() {};
	virtual void init() =0;
	virtual void update() =0;
	virtual void draw() = 0;
};