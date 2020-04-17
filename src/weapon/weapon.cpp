#include "weapon.h"
#include "constant.h"
#include <iostream>
weapons::weapons()
{
    //how much ammo a clip can hold
    smgAmmo = new int[SMG_MAG]; //20
    shotgunAmmo = new int[SHOTGUN_MAG]; //5
    rifleAmmo = new int[RIFLE_MAG]; //15
    pistolAmmo = new int[PISTOL_MAG]; //10

    //initializing the amount of clips person has
    // currentSMGclip = 0;
    // currentRifleClip = 0;
    // currentShotgunClip = 0;
    // currentPistolClip = 0;
    // currentMineClip = 0;

    //amount of bullets in mag
    usedSMG = 0;
    usedRifle = 0;
    usedPistol = 0;
    usedShotgun = 0;
    usedMine = 0;

}

void weapons::pick_Up_Gun(int array[])
{
    int usedTemp = 0;
    if(array == smgAmmo){
        std::cout<<"testing"<<std::endl;
        usedTemp = usedSMG;
        for (int i = 0; i < usedTemp + SMG_MAG; i ++) {
            array[i] = 1;
        }
    } else if(array == shotgunAmmo){
        //usedTemp is for calculatin TOTAL amount of bullets
        usedTemp = usedShotgun;
        //reset the bullet count
        usedShotgun = 0;
        //increase the amount of bullets starting from 0
        //to how much he picks up
        for (int i = 0; i < usedTemp + SHOTGUN_MAG; i ++) {
            array[i] = 1;
            usedShotgun ++;

        }

    }else if(array == rifleAmmo){
        for (int i = 0; i < 30; i ++) {
            rifleAmmo[i] = 1;
        }

    }else if(array == pistolAmmo){
        for (int i = 0; i < 30; i ++) {
            pistolAmmo[i] = 1;
        }

    }
}

//adding ammo to the gun
//although there is nothing of value to transfer
//which I can just delete the array and then remake it
//but maybe there will be important values inside the array
void weapons::push(int array[])
{
    if(array == smgAmmo){
        usedSMG += SMG_MAG;

    } else if(array == shotgunAmmo){
        //add the bullets to the reserve
        usedShotgun += SHOTGUN_MAG;
        //make sure reserve ammo doesnt exceed capacities
        while(usedShotgun > TOTAL_SHOTGUN)
        {
            usedShotgun --;
            std::cout<<"Reducing Ammo"<<std::endl;
        }
        //create temp copy of array
        int *temp = new int[usedShotgun];
        //intialize the values
        for(int i = 0; i < usedShotgun; i ++){
            temp[i] = 1;
        }
        //delete that array
        delete[] array;

        //create a new copy of that array
        array = new int[usedShotgun];
        //transfer the values
        for(int i = 0; i < usedShotgun; i ++){
            array[i] = temp[i];
        }

    }else if(array == rifleAmmo){
        usedRifle += RIFLE_MAG;

    }else if(array == pistolAmmo){
        usedPistol += PISTOL_MAG;
    }
}

//call pop to remove 1 bullet from the top of the stack
void weapons::fire(int array[])
{
	//bool holder;
    if(array == smgAmmo){
        pop(array);
		std::cout<<"Fire SMG"<<std::endl;
		// if(pop(array)==false)
		// {
		// 	reload(array);
		// }


    } else if(array == shotgunAmmo){
        //first check if I have ammo
		// if(pop(array)==false)
		// {
        //     //if no ammo, then exit the function
		// 	std::cout<<"Start Reload"<<std::endl;
		// 	reload(array);
		// 	std::cout<<"Reload Shotgun"<<std::endl;
		// 	return;
		// } else
        //{
            //if there is bullets, then fire and pop a bullet
            pop(array);
        //}
		std::cout<<"Fire SHotgun"<<std::endl;


    }else if(array == rifleAmmo){
        pop(array);
		std::cout<<"Fire RIFLE"<<std::endl;

    }else if(array == pistolAmmo){
        pop(array);
		std::cout<<"Fire Pistol"<<std::endl;

    }
}

void weapons::reload(int array[])
{
	if(array == smgAmmo){
		//mag is temp, later have to kept track if there is shots leftover

        usedSMG -= SMG_MAG;

    } else if(array == shotgunAmmo){
		if(usedShotgun != 0)
		{
        	usedShotgun -= SHOTGUN_MAG;

		}

    }else if(array == rifleAmmo){
        usedRifle -= RIFLE_MAG;

    }else if(array == pistolAmmo){
        usedPistol -= PISTOL_MAG;
    }

}
//returns the amount of clips player has
int weapons::size(int array[])
{
    if(array == smgAmmo){
        return currentSMGBullets;

    } else if(array == shotgunAmmo){
        return usedShotgun;

    }else if(array == rifleAmmo){
        return currentRifleBullets;

    }else if(array == pistolAmmo){
        return currentPistolBullets;
    }

    return 0;
}

//returns constant how how much bullets in a MAG
int weapons::mag_Size(int array[])
{
    if(array == smgAmmo){
        return SMG_MAG;

    } else if(array == shotgunAmmo){
        return SHOTGUN_MAG;

    }else if(array == rifleAmmo){
        return RIFLE_MAG;

    }else if(array == pistolAmmo){
        return PISTOL_MAG;
    }

    return 0;
}

//int weapons::check_Mag(int array[])
//{
//    if(array == smgAmmo){
//        for (int i = 0; i < ; i ++) {
//            smgAmmo[i] = 1;
//        }
//    } else if(array == shotgunAmmo){
//        for (int i = 0; i < 30; i ++) {
//            shotgunAmmo[i] = 1;
//        }

//    }else if(array == rifleAmmo){
//        for (int i = 0; i < 30; i ++) {
//            rifleAmmo[i] = 1;
//        }

//    }else if(array == pistolAmmo){
//        for (int i = 0; i < 30; i ++) {
//            pistolAmmo[i] = 1;
//        }

//    }
//    return 0;
//}

//decreae bullets in the mag
void weapons::decrease_Bullets(int array[])
{
    if(array == smgAmmo){
        usedSMG --;

    } else if(array == shotgunAmmo){
        usedShotgun --;

    }else if(array == rifleAmmo){
        usedRifle --;

    }else if(array == pistolAmmo){
        usedPistol --;;
    }
}
//just return the amount of total bullets
int weapons::bullet_Count(int array[])
{
    if(array == smgAmmo){
        return usedSMG;

    } else if(array == shotgunAmmo){
        return usedShotgun;

    }else if(array == rifleAmmo){
        return usedRifle;

    }else if(array == pistolAmmo){
        return usedPistol;
    }
    return 0;
}

//pops a bullet of the stack and return true/false if
//a bullet exist
void weapons::pop(int array[])
{
    int usedMag = mag_Size(array);

    //if there is ABSOLUTELY no ammo
    if(size(array)<= 0)
	{
		std::cout<<"No Bullets"<<std::endl;
		return;
	}

    //decrease the bullet of respected gun
    decrease_Bullets(array);
    //get the bullets left on the gun
    int used = bullet_Count(array);
    //use it to create a temp array
    int *temp = new int[used];


	std::cout<<"ShotGun : "<<size(shotgunAmmo)<<std::endl;

    for(int i = 0; i < used; i ++){
        temp[i] = array[i];
    }
    delete[] array;
    array = new int[usedMag];
    for(int i = 0; i < used; i ++){
        array[i] = temp[i];
        //cout<<"data: "<<data[i]<<endl;
    }
    delete [] temp;
}

// void weapons::reSize(int array[], int ammo)
// {
// 	int *temp = new int[ammo];
// 	if(array == smgAmmo){
//         for(int i = 0; i < ammo; i ++){
//         	temp[i] = 1;
// 		}

//     } else if(array == shotgunAmmo){
//         return usedShotgun;

//     }else if(array == rifleAmmo){
//         return usedRifle;

//     }else if(array == pistolAmmo){
//         return usedPistol;
//     }
// }

