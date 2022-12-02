#ifndef _CONST_H_
#define _CONST_H_

class Constants
{
public:
static const int FIELDX = 4800;
static const int FIELDY=3300;
static const int GOALX=4800;
static const int GOALY=3300;
static const int GOALUPY=2050;
static const int GOALDOWNY=1250;
static const int GOALWIDTH=400;
static const int ROBOSIZE = 120;

static const int OFFSET=150;
static const int KICKDISTANCE=250;
static const int KICKAREA=350;

static const int BALL=0;
static const int GOALKEEPER=1;
static const int DEFENCERIGHT=2;
static const int DEFENCELEFT=3;
static const int ATTACKEL=4;
static const int ATTACKER=5;

static const int NORMALIZEX=0;
static const int NORMALIZEY=0;

//KalmanFilter references
static const float T;
// static const float PS;
// static const float PV;
// static const float Q;
// static const float R;
};

#endif