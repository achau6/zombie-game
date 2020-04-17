#ifndef SHOTGUN_H
#define SHOTGUN_H
#include "weapon.h"


class shotgun: public weapons
{
	shotgun();
	void add_ammo();
	void identify(int type);
	void damage();
};

#endif // SHOTGUN_H