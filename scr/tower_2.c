/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** mor tower-desu
*/

#include "../include/my.h"

sfVector2f set_pos(sfVector2f i, int opt)
{
    if (opt == 0) {
        i.x = 1425;
        i.y = 57;
    }
    else if (opt == 1) {
        i.x = 1542;
        i.y = 50;
    }
    else {
        i.x = 1680;
        i.y = 50;
    }
    return (i);
}

tow *place_tower_filler(tow *towe, int tow, int where, int *mem)
{
    towe[*mem].damage = towe[(tow - 6)].damage;
    towe[*mem].spr = towe[(tow - 6)].spr;
    towe[*mem].rect_spr = towe[(tow - 6)].rect_spr;
    towe[*mem].shape = towe[(tow - 6)].shape;
    towe[*mem].pos.x = 0;
    towe[*mem].pos.y = 0;
    sfSprite_setTextureRect(towe[*mem].spr, towe[*mem].rect_spr);
    sfSprite_setPosition(towe[*mem].spr, towe[*mem].pos);
    *mem += 1;
    return towe;
}

tow *over(tow *towe, sfClock *clock)
{
    sfClock_restart(clock);
    return towe;
}

tow *place_tower(tow *towe, int tow, int *towe_nb, sfRenderWindow* window)
{
    sfClock *clock;
    sfTime time;
    float seconds;
    int mous = 0;
    sfVector2u w_size;

    clock = sfClock_create();
    while (1) {
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.0;
        w_size = sfRenderWindow_getSize(window);
        mous = mouse(window, w_size);
        if (mous != 0) {
            towe = place_tower_filler(towe, tow, mous, towe_nb);
            return over(towe, clock);
        }
        else if (seconds > 1.0)
            return over(towe, clock);
    }
}