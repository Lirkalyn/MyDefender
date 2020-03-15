/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** too... much... TOWER-desu
*/

#include "../include/my.h"

sfSprite *bullet_maker(sfVector2f pos)
{
    sfTexture* bul = sfTexture_createFromFile("Picture/tower_b_5.png", NULL);
    sfSprite *rsl = sfSprite_create();

    sfSprite_setTexture(rsl, bul, sfTrue);
    sfSprite_setPosition(rsl, pos);
    return rsl;
}

sfSprite *bullet_moover(sfSprite *spr, sfVector2f pos)
{
    sfSprite_setPosition(spr, pos);
    return spr;
}