#ifndef WEAPON_H
#define WEAPON_H


class weapons
{
public:
    //constructor
    weapons();
	//accessors
    void shotgun();
    void rifle();
    void pistol();
    void mine();
    void smg();
    void melee();

	//mutators
    //-------------Main Functions----
    void decrease_Bullets(int array[]);
    void fire(int array[]);
    void reload(int array[]);
    void push(int array[]);
    //--------------------------


    void pick_Up_Gun(int array[]);
    void pop(int array[]);
    void top();
    int size(int array[]);
    int mag_Size(int array[]);
    int check_Mag(int array[]);
    int bullet_Count(int array[]);
	void reSize(int array[], int ammo);

    //array
//protected:
    int *smgAmmo;
    int *shotgunAmmo;
    int *rifleAmmo;
    int *pistolAmmo;
    int *mineAmmo;

private:
	//how much shots he has left
    int currentSMGBullets;
    int currentRifleBullets;
    int currentShotgunBullets = 5;
    int currentPistolBullets;
    int currentMineBullets;

	//how much reserve ammo he has
    int usedSMG;
    int usedRifle;
    int usedPistol;
    int usedShotgun;
    int usedMine;


};

#endif // WEAPON_H