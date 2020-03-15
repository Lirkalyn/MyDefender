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

int shoot(int *xy, tow towe, en enem, sfRenderWindow* window)
{
    sfClock *clock;
    sfTime time;
    float seconds;
    sfSprite *bullet = bullet_maker(enem.i);

    clock = sfClock_create();
    while (1) {
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.0;
        if (seconds > 0.001) {
            if (enem.lp > 0)
                sfRenderWindow_drawSprite(window, bullet, NULL);
            sfClock_restart(clock);
                return ((towe.damage) * -1);
        }
    }
}

void get_hit(tow *towe, en *enem, int *nb, sfRenderWindow* window)
{
    double rsl = 0.0;
    int ene[2] = {[0 ... 1] = 0};
    int tow[2] = {[0 ... 1] = 0};
    int xy[2] = {[0 ... 1] = 0};

    for (int i = 3; i < nb[0]; i++) {
        tow[0] = (towe[i].which == 1) ? (towe[i].pos.x + 35) : tow[0];
        tow[1] = (towe[i].which == 1) ? (towe[i].pos.y + 105) : tow[1];
        tow[0] = (towe[i].which == 2) ? (towe[i].pos.x + 45) : tow[0];
        tow[1] = (towe[i].which == 2) ? (towe[i].pos.y + 105) : tow[1];
        for (int j = 0; j < nb[1]; j++) {
            ene[0] = sfSprite_getPosition(enem[j].en).x;
            ene[1] = sfSprite_getPosition(enem[j].en).y;
            rsl = sqrt(pow((ene[0] - tow[0]), 2) + pow((ene[1] - tow[1]), 2));
            xy[0] = (ene[0] - tow[0]);
            xy[1] = (ene[1] - tow[1]);
            if (rsl <= sfCircleShape_getRadius(towe[i].shape))
                enem[j].lp += shoot(xy, towe[i], enem[j], window);
        }
    }
}