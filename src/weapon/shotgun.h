#ifndef SHOTGUN_H
#define SHOTGUN_H
#include "weapon.h"


class shotgun: public weapons
{
	shotgun();
	void add_ammo();
	void identify(int type);
	int damage(int& type);
};

#endif // SHOTGUN_H