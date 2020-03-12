/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** more is not enough-desu
*/

#include "../include/my.h"

sfVector2f fire_pos(sfVector2f pos, int where)
{
    pos.x = 1380;
    pos.y = 650;
    if (where == 1) {
        pos.x = 195;
        pos.y = 325;
    }
    if (where == 2) {
        pos.x = 550;
        pos.y = 320;
    }
    if (where == 3) {
        pos.x = 995;
        pos.y = 325;
    }
    if (where == 4) {
        pos.x = 1020;
        pos.y = 845;
    }
    return pos;
}

sfVector2f ice_pos(sfVector2f pos, int where)
{
    pos.x = 1370;
    pos.y = 650;
    if (where == 1) {
        pos.x = 185;
        pos.y = 325;
    }
    if (where == 2) {
        pos.x = 540;
        pos.y = 320;
    }
    if (where == 3) {
        pos.x = 985;
        pos.y = 325;
    }
    if (where == 4) {
        pos.x = 1010;
        pos.y = 845;
    }
    return pos;
}

tow *hit_box_maker(tow *towe, int *mem)
{
    towe[*mem].shape = sfCircleShape_create();
    sfCircleShape_setFillColor(towe[*mem].shape, sfTransparent);
    towe[*mem].hit_pos.x = (towe[*mem].pos.x - 175);
    towe[*mem].hit_pos.y = (towe[*mem].pos.y - 125);
    sfCircleShape_setPosition(towe[*mem].shape, towe[*mem].hit_pos);
    sfCircleShape_setRadius(towe[*mem].shape, 225);
    return towe;
}