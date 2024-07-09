#ifndef STRUCTS_H
#define STRUCTS_H

#include <SDL.h>

/**
 * struct point_s - data structure for XY point coordinates of type double
 * @x: X coordinate
 * @y: Y coordinate
 * Description: struct point
 */
typedef struct point_s
{
        double x;
        double y;
} point_t;

/**
 * struct weapon_s - data structure for weapon
 * @ammo: number of ammo
 * @cooldown: cooldown time between shots
 * @lastFired: last time the weapon was fired
 * @texture: SDL texture for the weapon
 * @position: SDL rect for weapon position
 */
typedef struct weapon_s
{
    int ammo;
    double cooldown;
    double lastFired;
    SDL_Texture *texture;
    SDL_Rect position;
} weapon_t;

#endif /* STRUCTS_H */

