#include "weapon.h"
#include <iostream>
#include <assert.h>
weapons::weapons()
{


    smgs = nullptr;
    shotguns = nullptr;
    pistols = nullptr;
    rifles = nullptr;
    currentIndex = 0;
    shotgunsHead = nullptr;
    shotgunsTail = nullptr;


}

// void weapons::push(int identifier, sf::CircleShape bullet,
//                     sf::Vector2f velocity)
// {
//     node<sf::CircleShape>* temp = new node<sf::CircleShape>;
//     //pistol
//     if(identifier == 1 || head == pistols){
//         temp->key = 1;
//     } else if(temp->key == 2 || head == smgs){
//         temp->key = 2;
//     } else if(temp->key == 4 || head == shotguns){
//         temp->key = 4;
//     } else if(temp->key == 3 || head == rifles){
//         temp->key = 3;
//     }
//     temp->shape = bullet;
//     temp->prev = nullptr;
//     temp->next = nullptr;
//     temp->currentVelocity = velocity;
//     if (head == nullptr){
//         head = temp;
//     } else {
//         temp->next = head;
//         head->prev = temp;
//         head = temp;
//     }
// }


void weapons::printCheck(node<sf::CircleShape>* &head)
{
    node<sf::CircleShape>* temp = head;
    while(temp != nullptr){
        std::cout<<temp->key<<", ";
        temp = temp->next;
    }
    std::cout<<std::endl;
}
void weapons::remove(node<sf::CircleShape>* &head)
{
    node<sf::CircleShape>* temp = head;
    if(temp == nullptr){

    } else{
        temp = temp->next;
        temp = nullptr;
        head = temp;
    }
}

bool weapons::is_item(node<sf::CircleShape>* &head){
    int count = 0;
    node<sf::CircleShape>* temp = head;
    while(temp != nullptr){
        if(count == currentIndex){
            if(temp == nullptr) {
                return false;
            } else {
                return true;
            }
        }
        count ++;
        temp = temp->next;
    }
    return false;
}
void weapons::start() {
    currentIndex = 0;
}

void weapons::advance(){
    currentIndex ++;
}
void weapons::current(node<sf::CircleShape>* &head)
{
    int count = 0;
    node<sf::CircleShape>* temp = head;
    while(temp != nullptr){
        if(count == currentIndex){
            temp->shape.move(temp->currentVelocity);
            break;
        }
        count += 1;
        temp = temp->next;
    }

}

void weapons::currentDraw(sf::RenderWindow& window,
                         node<sf::CircleShape>* &head)
{
    node<sf::CircleShape>* temp = head;
    int count = 0;
    while(temp != nullptr){
        if(count == currentIndex){
            window.draw(temp->shape);
            break;
        }
        count += 1;
        temp = temp->next;
    }
}
// void weapons::pick_Up_Gun(node<sf::CircleShape>* &head)
// {
//    if(head->key == 1){
//         std::cout<<"pistol"<<std::endl;

//     } else if(head->key == 2){
//         std::cout<<"smg"<<std::endl;

//     }else if(head->key == 3){
//         std::cout<<"rifle"<<std::endl;

//     }else if(head->key == 4){
//         for(int i = 0; i < SHOTGUN_MAG; i ++){
//             //push();
//         }
//     }
// }

// //adding ammo to the gun
// //although there is nothing of value to transfer
// //which I can just delete the array and then remake it
// //but maybe there will be important values inside the array
// void weapons::reload(node<sf::CircleShape>* &head, sf::CircleShape bullet, sf::Vector2f velocity)
// {
//     if(head == pistols){
//         std::cout<<"pistol"<<std::endl;

//     } else if(head == pistols){
//         std::cout<<"smg"<<std::endl;

//     }else if(head == pistols){
//         std::cout<<"rifle"<<std::endl;

//     }else if(head == pistols){
//         std::cout<<"shotgun"<<std::endl;
//         for(int i = 0; i < SHOTGUN_MAG; i ++)
//         {
//             //push(head, bullet, velocity);
//         }
//     }
// }



// //returns the amount of clips player has
// int weapons::size(sf::CircleShape array[])
// {
//     if(array == smgAmmo){
//         return currentSMGBullets;

//     } else if(array == shotgunAmmo){
//         return usedShotgun;

//     }else if(array == rifleAmmo){
//         return currentRifleBullets;

//     }else if(array == pistolAmmo){
//         return currentPistolBullets;
//     }

//     return 0;
// }

// //returns constant how how much bullets in a MAG
// int weapons::mag_Size(sf::CircleShape array[])
// {
//     if(array == smgAmmo){
//         return SMG_MAG;

//     } else if(array == shotgunAmmo){
//         return SHOTGUN_MAG;

//     }else if(array == rifleAmmo){
//         return RIFLE_MAG;

//     }else if(array == pistolAmmo){
//         return PISTOL_MAG;
//     }

//     return 0;
// }

// //int weapons::check_Mag(int array[])
// //{
// //    if(array == smgAmmo){
// //        for (int i = 0; i < ; i ++) {
// //            smgAmmo[i] = 1;
// //        }
// //    } else if(array == shotgunAmmo){
// //        for (int i = 0; i < 30; i ++) {
// //            shotgunAmmo[i] = 1;
// //        }

// //    }else if(array == rifleAmmo){
// //        for (int i = 0; i < 30; i ++) {
// //            rifleAmmo[i] = 1;
// //        }

// //    }else if(array == pistolAmmo){
// //        for (int i = 0; i < 30; i ++) {
// //            pistolAmmo[i] = 1;
// //        }

// //    }
// //    return 0;
// //}

// //decreae bullets in the mag
// void weapons::decrease_Bullets(sf::CircleShape array[])
// {
//     if(array == smgAmmo){
//         usedSMG --;

//     } else if(array == shotgunAmmo){
//         usedShotgun --;

//     }else if(array == rifleAmmo){
//         usedRifle --;

//     }else if(array == pistolAmmo){
//         usedPistol --;;
//     }
// }
// //just return the amount of total bullets
// int weapons::bullet_Count(sf::CircleShape array[])
// {
//     if(array == smgAmmo){
//         return usedSMG;

//     } else if(array == shotgunAmmo){
//         return usedShotgun;

//     }else if(array == rifleAmmo){
//         return usedRifle;

//     }else if(array == pistolAmmo){
//         return usedPistol;
//     }
//     return 0;
// }



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

