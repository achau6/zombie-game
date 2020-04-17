#include "shotgun.h"
//#include "constant.h"

shotgun::shotgun()
{

}

void shotgun::add_ammo()
{

}

void shotgun::identify(int type)
{
	if(type == 3)
	{
		return;
	}
}

//shotgun does 4 dmg
int shotgun::damage(int& type)
{
	//type is the zombie while 5 equals the health
	//dont need this check but I want to know its
	//if its the right zombie
	if(type == 5)
	{
		type -= 5;
	}

	//return the health of the zombie
	return type;
}