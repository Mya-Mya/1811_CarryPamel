#pragma once
#include"Point.h"
#include"PlaneVector.h"
#include"ActionListener.h"
#include"Toggle.h"
#include"MyaObject.h"
#include"MapDrawable.h"

class Car:public ActionListener, MapDrawable
	,MyaO
{
private:
	Point * BeforePosition=nullptr,* NowPosition=nullptr;

	double CarMovingL = 0,CarVelocity = 0;
	Mya::PlaneVector *CarHeadding=nullptr;
	int CarImage;
	bool running=false;
	
	const int ToggleLeft = 0, ToggleStraight = 1, ToggleRight = 2;
	Toggle *Toggles[3];

	TrafficState MyTS=TrafficState_None;
	void setCarHeadding(Point*before, Point*after);
	void setCarVelocity(TrafficState ts);
	void turn(TurnDirection td);
	TurnDirection availableOnlyOneFork(Point*point);

public:
	
	void init();
	void draw();
	void update();

	int getX();
	int getY();

	void setPosition(Point*position);
	void setDriveable(bool driveable) ;
	double getCurrentVelocity() ;
	Point* getCurrentPosition() ;//ëñçsíÜÇÕnullptr
	iBranch* getCurrentBranch(); //ëñçsíÜÇÕnullptr
	bool canOnlyBack() ;
	bool isRunning();

	// implements from AcLis
	void actionPerformed(EventObj *e);

	/*from MapDrawable*/
	void drawOnMap()override;
};

