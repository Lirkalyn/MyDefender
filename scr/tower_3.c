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
    sfCircleShape_setOutlineThickness(towe[*mem].shape, 1);
    sfCircleShape_setOutlineColor(towe[*mem].shape, sfBlue);
    return towe;
}

void get_hit(tow *towe, en *enem, int nb_tower, int nb_enemy)
{
    float radius;
    double rsl = 0.0;
    sfVector2f enem_x_y;
    int enem_x = 0;
    int enem_y = 0;
    int towe_x = 0;
    int towe_y = 0;

    for (int i = 3; i < nb_tower; i++) {
        radius = sfCircleShape_getRadius(towe[i].shape);
        if (towe[i].which == 1) {
        towe_x = (towe[i].pos.x + 35);
        towe_y = (towe[i].pos.y + 105);
        }
        else if (towe[i].which == 2) {
        towe_x = (towe[i].pos.x + 45);
        towe_y = (towe[i].pos.y + 105);
        }
        for (int j = 0; j < nb_enemy; j++) {
            enem_x_y = sfSprite_getPosition(enem[j].en);
            enem_x = enem_x_y.x;
            enem_y = enem_x_y.y;
            //rsl = sqrt(pow((towe_x - enem_x), 2) + pow((towe_y - enem_y), 2));
            rsl = sqrt(pow((enem_x - towe_x), 2) + pow((enem_y - towe_y), 2));
//            printf("i = %d et j = %d : e_x = %d et e_y = %d : t_x = %d et t_y = %d : et rad = %f et %f\n", i , j, enem_x, enem_y, towe_x, towe_y, radius, rsl);
        }
//        printf("%d\n", towe[i].which);
//        printf("\n");
    }
}