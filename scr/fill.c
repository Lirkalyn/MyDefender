/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** fill-desu
*/

#include "../include/my.h"

struct Pos *fill_3(sfVector2u w_size, struct Pos *p)
{
    p[7].a = (1673 * w_size.x)/1920;
    p[7].b = (1784 * w_size.x)/1920;
    p[7].c = (44 * w_size.y)/1008;
    p[7].d = (191 * w_size.y)/1008;
    return p;
}

struct Pos *fill_2(sfVector2u w_size, struct Pos *p)
{
    p[3].a = (991 * w_size.x)/1920;
    p[3].b = (1120 * w_size.x)/1920;
    p[3].c = (912 * w_size.y)/1008;
    p[3].d = (988 * w_size.y)/1008;
    p[4].a = (1354 * w_size.x)/1920;
    p[4].b = (1483 * w_size.x)/1920;
    p[4].c = (718 * w_size.y)/1008;
    p[4].d = (796 * w_size.y)/1008;
    p[5].a = (1404 * w_size.x)/1920;
    p[5].b = (1516 * w_size.x)/1920;
    p[5].c = (43 * w_size.y)/1008;
    p[5].d = (190 * w_size.y)/1008;
    p[6].a = (1537 * w_size.x)/1920;
    p[6].b = (1647 * w_size.x)/1920;
    p[6].c = (44 * w_size.y)/1008;
    p[6].d = (190 * w_size.y)/1008;
    p = fill_3(w_size, p);
    return p;
}

struct Pos *fill(sfVector2u w_size)
{
    struct Pos *p = malloc(8 * sizeof(struct Pos));

    if (p == NULL)
        return NULL;
    p[0].a = (164 * w_size.x)/1920;
    p[0].b = (297 * w_size.x)/1920;
    p[0].c = (391 * w_size.y)/1008;
    p[0].d = (472 * w_size.y)/1008;
    p[1].a = (520 * w_size.x)/1920;
    p[1].b = (659 * w_size.x)/1920;
    p[1].c = (391 * w_size.y)/1008;
    p[1].d = (467 * w_size.y)/1008;
    p[2].a = (965 * w_size.x)/1920;
    p[2].b = (1093 * w_size.x)/1920;
    p[2].c = (395 * w_size.y)/1008;
    p[2].d = (472 * w_size.y)/1008;
    p = fill_2(w_size, p);
    return p;
}