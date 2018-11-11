#include "MapData.h"
#include"Point.h"
#include"Branch.h"
#include"DxLib.h"
#include"Frame.h"
#include<random>
#pragma warning(disable:4244)
using namespace std;

DrivePlan* MapData::getDrivePlan()
{
	random_device rd;
	mt19937 mt(rd());
	int i = mt() % driveplans.size();
	return driveplans[mt() % driveplans.size()];
}

#define NUM_BRANCHES 72

void MapData::init()
{
	Branch *b[NUM_BRANCHES];
	/*Ž}‚ðì‚é*/
{
		b[0] = new Branch(300, 400);b[0]-> makePoint(1)->makePoint(2)->makePoint(3);
		b[1] = new Branch(500, 100); b[1]->makePoint(1)->makePoint(2)->makePoint(3);
		b[2] = new Branch(900, 100); b[2]->makePoint(1)->makePoint(2)->makePoint(3);
		b[3] = new Branch(1600, 100); b[3]->makePoint(1)->makePoint(2)->makePoint(3);
		b[4] = new Branch(1900, 50); b[4]->makePoint(2);
		b[5] = new Branch(1900, 100); b[5]->makePoint(0)->makePoint(1)->makePoint(3);
		b[6] = new Branch(2200, 100); b[6]->makePoint(1)->makePoint(2)->makePoint(3);
		b[7] = new Branch(2500, 100); b[7]->makePoint(2)->makePoint(3);
		b[8] = new Branch(400, 400); b[8]->makePoint(0);
		b[9] = new Branch(800, 300); b[9]->makePoint(1);
		b[10] = new Branch(900, 300); b[10]->makePoint(0)->makePoint(2)->makePoint(3);
		b[11] = new Branch(2500, 300); b[11]->makePoint(0)->makePoint(1)->makePoint(2);
		b[12] = new Branch(200, 500); b[12]->makePoint(0)->makePoint(2);
		b[13] = new Branch(500, 600); b[13]->makePoint(0)->makePoint(1)->makePoint(2);
		b[14] = new Branch(1000, 600); b[14]->makePoint(0)->makePoint(1)->makePoint(2)->makePoint(3);
		b[15] = new Branch(1300, 600); b[15]->makePoint(0)->makePoint(1)->makePoint(3);
		b[16] = new Branch(1500, 600); b[16]->makePoint(1)->makePoint(2)->makePoint(3);
		b[17] = new Branch(2000, 600); b[17]->makePoint(0)->makePoint(1)->makePoint(3);
		b[18] = new Branch(2300, 600); b[18]->makePoint(1)->makePoint(2)->makePoint(3);
		b[19] = new Branch(2700, 600); b[19]->makePoint(0)->makePoint(3);
		b[20] = new Branch(2800, 200); b[20]->makePoint(3);
		b[21] = new Branch(200, 800); b[21]->makePoint(0)->makePoint(1)->makePoint(2);
		b[22] = new Branch(500, 800); b[22]->makePoint(0)->makePoint(2)->makePoint(3);
		b[23] = new Branch(2300, 800); b[23]->makePoint(1)->makePoint(2)->makePoint(3);
		b[24] = new Branch(500, 900); b[24]->makePoint(0)->makePoint(1)->makePoint(2);
		b[25] = new Branch(900, 900); b[25]->makePoint(0)->makePoint(1)->makePoint(3);
		b[26] = new Branch(1300, 900); b[26]->makePoint(1)->makePoint(2)->makePoint(3);
		b[27] = new Branch(1500, 900); b[27]->makePoint(0)->makePoint(1)->makePoint(3);
		b[28] = new Branch(1800, 900); b[28]->makePoint(1)->makePoint(2)->makePoint(3);
		b[29] = new Branch(2700, 900); b[29]->makePoint(0);
		b[30] = new Branch(100, 1200); b[30]->makePoint(1);
		b[31] = new Branch(200, 1200); b[31]->makePoint(0)->makePoint(1)->makePoint(2)->makePoint(3);
		b[32] = new Branch(500, 1200); b[32]->makePoint(0)->makePoint(2)->makePoint(3);
		b[33] = new Branch(500, 1400); b[33]->makePoint(0)->makePoint(1)->makePoint(2);
		b[34] = new Branch(700, 1400); b[34]->makePoint(0)->makePoint(1)->makePoint(3);
		b[35] = new Branch(800, 1300); b[35]->makePoint(0)->makePoint(2);
		b[36] = new Branch(1000, 1200); b[36]->makePoint(1)->makePoint(3);
		b[37] = new Branch(1200, 1000); b[37]->makePoint(0)->makePoint(2);
		b[38] = new Branch(900, 1400); b[38]->makePoint(1)->makePoint(2)->makePoint(3);
		b[39] = new Branch(1500, 1400); b[39]->makePoint(0)->makePoint(1)->makePoint(2)->makePoint(3);
		b[40] = new Branch(1500, 1320); b[40]->makePoint(2);
		b[41] = new Branch(1800, 1400); b[41]->makePoint(0)->makePoint(1)->makePoint(3);
		b[42] = new Branch(1800, 1300); b[42]->makePoint(2);
		b[43] = new Branch(2000, 1400); b[43]->makePoint(0)->makePoint(1)->makePoint(2)->makePoint(3);
		b[44] = new Branch(2500, 1400); b[44]->makePoint(3)->makePoint(2);
		b[45] = new Branch(200, 1700); b[45]->makePoint(0)->makePoint(1)->makePoint(2);
		b[46] = new Branch(400, 1700); b[46]->makePoint(3)->makePoint(1);
		b[47] = new Branch(500, 1800); b[47]->makePoint(0)->makePoint(1)->makePoint(2)->makePoint(3);
		b[48] = new Branch(500, 1900); b[48]->makePoint(0);
		b[49] = new Branch(800, 1800); b[49]->makePoint(3)->makePoint(1);
		b[50] = new Branch(900, 1800); b[50]->makePoint(0)->makePoint(1)->makePoint(3);
		b[51] = new Branch(1000, 1800); b[51]->makePoint(1)->makePoint(2)->makePoint(3);
		b[52] = new Branch(1300, 1800); b[52]->makePoint(3)->makePoint(1);
		b[53] = new Branch(1400, 1900); b[53]->makePoint(0)->makePoint(1)->makePoint(2)->makePoint(3);
		b[54] = new Branch(1500, 2000); b[54]->makePoint(1)->makePoint(3);
		b[55] = new Branch(2000, 2000); b[55]->makePoint(0)->makePoint(1)->makePoint(3);
		b[56] = new Branch(2000, 1600); b[56]->makePoint(0)->makePoint(1)->makePoint(2);
		b[57] = new Branch(2200, 1600); b[57]->makePoint(1)->makePoint(2)->makePoint(3);
		b[58] = new Branch(2500, 1600); b[58]->makePoint(0)->makePoint(1)->makePoint(2)->makePoint(3);
		b[59] = new Branch(2800, 1600); b[59]->makePoint(3);
		b[60] = new Branch(2200, 1900); b[60]->makePoint(0)->makePoint(1);
		b[61] = new Branch(2500, 1900); b[61]->makePoint(0)->makePoint(2)->makePoint(3);
		b[62] = new Branch(2500, 2000); b[62]->makePoint(0)->makePoint(2)->makePoint(3);
		b[63] = new Branch(200, 2300); b[63]->makePoint(0)->makePoint(1)->makePoint(2);
		b[64] = new Branch(1000, 2000); b[64]->makePoint(0)->makePoint(1)->makePoint(2);
		b[65] = new Branch(1300, 2100); b[65]->makePoint(0)->makePoint(2)->makePoint(3);
		b[66] = new Branch(1000, 2300); b[66]->makePoint(0)->makePoint(1)->makePoint(3);
		b[67] = new Branch(1300, 2300); b[67]->makePoint(0)->makePoint(1)->makePoint(3);
		b[68] = new Branch(2500, 2100); b[68]->makePoint(0)->makePoint(2)->makePoint(3);
		b[69] = new Branch(2200, 2100); b[69]->makePoint(1);
		b[70] = new Branch(2500, 2300); b[70]->makePoint(0)->makePoint(3);
		b[71] = new Branch(300, 2400); b[71]->makePoint(0);
}
	/*“_“¯Žm‚ð‚­‚Á‚Â‚¯‚é*/
{
	linkEachPoint(b[0]->getPoint(1), b[1]->getPoint(3), randomTS());
	linkEachPoint(b[0]->getPoint(2), b[8]->getPoint(0), randomTS());
	linkEachPoint(b[0]->getPoint(3), b[12]->getPoint(0), randomTS());
	linkEachPoint(b[1]->getPoint(1), b[2]->getPoint(3), randomTS());
	linkEachPoint(b[1]->getPoint(2), b[13]->getPoint(0), randomTS());
	linkEachPoint(b[2]->getPoint(2), b[10]->getPoint(0), randomTS());
	linkEachPoint(b[10]->getPoint(3), b[9]->getPoint(1), randomTS());
	linkEachPoint(b[10]->getPoint(2), b[14]->getPoint(0), randomTS());
	linkEachPoint(b[2]->getPoint(1), b[3]->getPoint(3), randomTS());
	linkEachPoint(b[3]->getPoint(2), b[15]->getPoint(0), randomTS());
	linkEachPoint(b[3]->getPoint(1), b[5]->getPoint(3), randomTS());
	linkEachPoint(b[4]->getPoint(2), b[5]->getPoint(0), randomTS());
	linkEachPoint(b[5]->getPoint(1), b[6]->getPoint(3), randomTS());
	linkEachPoint(b[6]->getPoint(1), b[7]->getPoint(3), randomTS());
	linkEachPoint(b[7]->getPoint(2), b[11]->getPoint(0), randomTS());
	linkEachPoint(b[11]->getPoint(1), b[20]->getPoint(3), randomTS());
	linkEachPoint(b[11]->getPoint(2), b[19]->getPoint(0), randomTS());
	linkEachPoint(b[13]->getPoint(1), b[14]->getPoint(3), randomTS());
	linkEachPoint(b[14]->getPoint(1), b[15]->getPoint(3), randomTS());
	linkEachPoint(b[15]->getPoint(1), b[16]->getPoint(3), randomTS());
	linkEachPoint(b[16]->getPoint(1), b[17]->getPoint(3), randomTS());
	linkEachPoint(b[6]->getPoint(2), b[17]->getPoint(0), randomTS());
	linkEachPoint(b[17]->getPoint(1), b[18]->getPoint(3), randomTS());
	linkEachPoint(b[18]->getPoint(1), b[19]->getPoint(3), randomTS());
	linkEachPoint(b[12]->getPoint(2), b[21]->getPoint(0), randomTS());
	linkEachPoint(b[21]->getPoint(1), b[22]->getPoint(3), randomTS());
	linkEachPoint(b[13]->getPoint(2), b[22]->getPoint(0), randomTS());
	linkEachPoint(b[22]->getPoint(2), b[24]->getPoint(0), randomTS());
	linkEachPoint(b[24]->getPoint(1), b[25]->getPoint(3), randomTS());
	linkEachPoint(b[14]->getPoint(2), b[25]->getPoint(0), randomTS());
	linkEachPoint(b[25]->getPoint(1), b[26]->getPoint(3), randomTS());
	linkEachPoint(b[26]->getPoint(1), b[27]->getPoint(3), randomTS());
	linkEachPoint(b[16]->getPoint(2), b[27]->getPoint(0), randomTS());
	linkEachPoint(b[27]->getPoint(1), b[28]->getPoint(3), randomTS());
	linkEachPoint(b[28]->getPoint(1), b[23]->getPoint(3), randomTS());
	linkEachPoint(b[23]->getPoint(1), b[18]->getPoint(2), randomTS());
	linkEachPoint(b[23]->getPoint(2), b[29]->getPoint(0), randomTS());
	linkEachPoint(b[21]->getPoint(2), b[31]->getPoint(0), randomTS());
	linkEachPoint(b[30]->getPoint(1), b[31]->getPoint(3), randomTS());
	linkEachPoint(b[31]->getPoint(1), b[32]->getPoint(3), randomTS());
	linkEachPoint(b[24]->getPoint(2), b[32]->getPoint(0), randomTS());
	linkEachPoint(b[31]->getPoint(2), b[45]->getPoint(0), randomTS());
	linkEachPoint(b[32]->getPoint(2), b[33]->getPoint(0), randomTS());
	linkEachPoint(b[33]->getPoint(2), b[47]->getPoint(0), randomTS());
	linkEachPoint(b[33]->getPoint(1), b[34]->getPoint(3), randomTS());
	linkEachPoint(b[34]->getPoint(0), b[35]->getPoint(2), randomTS());
	linkEachPoint(b[35]->getPoint(0), b[36]->getPoint(3), randomTS());
	linkEachPoint(b[36]->getPoint(1), b[37]->getPoint(2), randomTS());
	linkEachPoint(b[37]->getPoint(0), b[26]->getPoint(2), randomTS());
	linkEachPoint(b[34]->getPoint(1), b[38]->getPoint(3), randomTS());
	linkEachPoint(b[38]->getPoint(1), b[39]->getPoint(3), randomTS());
	linkEachPoint(b[39]->getPoint(0), b[40]->getPoint(2), randomTS());
	linkEachPoint(b[39]->getPoint(1), b[41]->getPoint(3), randomTS());
	linkEachPoint(b[41]->getPoint(0), b[42]->getPoint(2), randomTS());
	linkEachPoint(b[41]->getPoint(1), b[43]->getPoint(3), randomTS());
	linkEachPoint(b[43]->getPoint(0), b[28]->getPoint(2), randomTS());
	linkEachPoint(b[43]->getPoint(1), b[44]->getPoint(3), randomTS());
	linkEachPoint(b[45]->getPoint(1), b[46]->getPoint(3), randomTS());
	linkEachPoint(b[46]->getPoint(1), b[47]->getPoint(3), randomTS());
	linkEachPoint(b[47]->getPoint(2), b[48]->getPoint(0), randomTS());
	linkEachPoint(b[47]->getPoint(1), b[49]->getPoint(3), randomTS());
	linkEachPoint(b[49]->getPoint(1), b[50]->getPoint(3), randomTS());
	linkEachPoint(b[50]->getPoint(0), b[38]->getPoint(2), randomTS());
	linkEachPoint(b[50]->getPoint(1), b[51]->getPoint(3), randomTS());
	linkEachPoint(b[51]->getPoint(1), b[52]->getPoint(3), randomTS());
	linkEachPoint(b[52]->getPoint(1), b[53]->getPoint(3), randomTS());
	linkEachPoint(b[53]->getPoint(0), b[39]->getPoint(2), randomTS());
	linkEachPoint(b[53]->getPoint(1), b[54]->getPoint(3), randomTS());
	linkEachPoint(b[53]->getPoint(2), b[65]->getPoint(0), randomTS());
	linkEachPoint(b[53]->getPoint(3), b[52]->getPoint(1), randomTS());
	linkEachPoint(b[54]->getPoint(1), b[55]->getPoint(3), randomTS());
	linkEachPoint(b[43]->getPoint(2), b[56]->getPoint(0), randomTS());
	linkEachPoint(b[56]->getPoint(1), b[57]->getPoint(3), randomTS());
	linkEachPoint(b[57]->getPoint(1), b[58]->getPoint(3), randomTS());
	linkEachPoint(b[44]->getPoint(2), b[58]->getPoint(0), randomTS());
	linkEachPoint(b[58]->getPoint(1), b[59]->getPoint(3), randomTS());
	linkEachPoint(b[58]->getPoint(2), b[61]->getPoint(0), randomTS());
	linkEachPoint(b[57]->getPoint(2), b[60]->getPoint(0), randomTS());
	linkEachPoint(b[60]->getPoint(1), b[61]->getPoint(3), randomTS());
	linkEachPoint(b[61]->getPoint(2), b[62]->getPoint(0), randomTS());
	linkEachPoint(b[56]->getPoint(2), b[55]->getPoint(0), randomTS());
	linkEachPoint(b[55]->getPoint(1), b[62]->getPoint(3), randomTS());
	linkEachPoint(b[62]->getPoint(2), b[68]->getPoint(0), randomTS());
	linkEachPoint(b[68]->getPoint(3), b[69]->getPoint(1), randomTS());
	linkEachPoint(b[68]->getPoint(2), b[70]->getPoint(0), randomTS());
	linkEachPoint(b[67]->getPoint(1), b[70]->getPoint(3), randomTS());
	linkEachPoint(b[51]->getPoint(2), b[64]->getPoint(0), randomTS());
	linkEachPoint(b[64]->getPoint(1), b[65]->getPoint(3), randomTS());
	linkEachPoint(b[64]->getPoint(2), b[66]->getPoint(0), randomTS());
	linkEachPoint(b[45]->getPoint(2), b[63]->getPoint(0), randomTS());
	linkEachPoint(b[63]->getPoint(1), b[66]->getPoint(3), randomTS());
	linkEachPoint(b[66]->getPoint(1), b[67]->getPoint(3), randomTS());
	linkEachPoint(b[65]->getPoint(2), b[67]->getPoint(0), randomTS());
	linkEachPoint(b[63]->getPoint(2), b[71]->getPoint(0), randomTS());
}
	/*’n–¼“o˜^*/
{
	b[8]->rgstName("‰ž‘V", "‚¨‚¤‚º‚ñ");
	b[9]->rgstName("pé", "‚¶‚ñ‚¶‚å‚¤");
	b[4]-> rgstName( "Š|‹ã’J",  "‚©‚¯‚­‚¾‚É");
	b[20]-> rgstName( "Œu˜a",  "‚Ù‚½‚é‚í");
	b[29]-> rgstName( "—€Ñô•~",  "‚æ‚­‚¹‚«‚¹‚ñ‚¶‚«");
	b[40]-> rgstName( "‰S•û",  "‚¤‚½‚©‚½");
	b[42]-> rgstName( "“•ò",  "‚Æ‚¤‚Ù‚¤");
	b[30]-> rgstName( "—§•ô",  "‚½‚¿‚Ý‚Ë");
	b[48]-> rgstName( "ÔŒ©Ø",  "‚ ‚©‚Ý‚È");
	b[71]-> rgstName("—³“n",  "‚è‚ã‚¤‚Æ");
	b[69]-> rgstName( "ŽÚh",  "‚µ‚á‚­‚¶‚ã‚­");
	b[59]->rgstName("ÃŽü", "‚¹‚¢‚µ‚ã‚¤");
}
	/*‰^“]Œv‰æ‘ì¬*/
	driveplans.push_back(new DrivePlan( b[4]->getPoint(2),b[69] ));
	driveplans.push_back(new DrivePlan( b[69]->getPoint(1),b[4]));
	driveplans.push_back(new DrivePlan( b[29]->getPoint(0),b[48] ));
	driveplans.push_back(new DrivePlan( b[48]->getPoint(0),b[29] ));
	driveplans.push_back(new DrivePlan (b[20]->getPoint(3),b[71]) );
	driveplans.push_back(new DrivePlan( b[71]->getPoint(0),b[20]) );


	for(int i=0;i<NUM_BRANCHES;i++) mapdata.push_back(b[i]);

}


void MapData::linkEachPoint(Point *one, Point *another, TrafficState ts)
{
	if (one == nullptr || another == nullptr) return;
	one->rgstLink(another, ts);
	another->rgstLink(one, ts);
}

TrafficState MapData::randomTS()
{
	return TrafficState(rand()%4);
}

void MapData::setWhatToDraw(MapWhatToDraw WhatToDraw)
{
	this->WhatToDraw = WhatToDraw;
	for (auto i : mapdata)i->setWhatToDraw(WhatToDraw);
}


void MapData::drawOnMap()
{
	for (auto i : mapdata)i->drawOnMap();
}


void MapData::setScreenTS(bool IfScreenTS)
{
	for (auto i : mapdata)i->setScreenTS(IfScreenTS);
}