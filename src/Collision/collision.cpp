#include "collision.h"
bool Collision::OutOfBounds(float positionx, float positiony){
	if (positionx < MAP_BORDER_X_LOW || positionx > MAP_BORDER_X_HIGH)
		return false;
	else if (positiony < MAP_BORDER_Y_LOW || positiony > MAP_BORDER_Y_HIGH)
		return false;
	return true;
}

// bool Collision::MapEntityCheck(float positionx, float positiony){

// }

bool Collision::legalMovement(float positionx, float positiony){
	if (!OutOfBounds(positionx, positiony))
		return false;
	return true;
}

