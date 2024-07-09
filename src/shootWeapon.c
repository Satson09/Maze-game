#include "maze.h"

/**
 * shootWeapon - handles the shooting logic
 * Return: void
 */
void shootWeapon(void)
{
    if (weapon.ammo > 0 && (time - weapon.lastFired) / 1000.0 >= weapon.cooldown)
    {
        weapon.ammo--;
        weapon.lastFired = time;
        printf("Weapon fired! Ammo left: %d\n", weapon.ammo);
        // Add more weapon firing logic here, such as checking for hits
    }
}

