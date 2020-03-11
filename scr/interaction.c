/*
** EPITECH PROJECT, 2020
** my_defander
** File description:
** act-desu
*/

#include "../include/my.h"

int interaction_2(int *x_y, struct Pos *p)
{
    if ((x_y[0] >= p[6].a && x_y[0] <= p[6].b)
            && (x_y[1] >= p[6].c && x_y[1] <= p[6].d))
        return 7;
    if ((x_y[0] >= p[7].a && x_y[0] <= p[7].b)
            && (x_y[1] >= p[7].c && x_y[1] <= p[7].d))
        return 8;
    return 0;
}

int interaction(int *x_y, struct Pos *p)
{
    if ((x_y[0] >= p[0].a && x_y[0] <= p[0].b)
            && (x_y[1] >= p[0].c && x_y[1] <= p[0].d))
        return 1;
    if ((x_y[0] >= p[1].a && x_y[0] <= p[1].b)
            && (x_y[1] >= p[1].c && x_y[1] <= p[1].d))
        return 2;
    if ((x_y[0] >= p[2].a && x_y[0] <= p[2].b)
            && (x_y[1] >= p[2].c && x_y[1] <= p[2].d))
        return 3;
    if ((x_y[0] >= p[3].a && x_y[0] <= p[3].b)
            && (x_y[1] >= p[3].c && x_y[1] <= p[3].d))
        return 4;
    if ((x_y[0] >= p[4].a && x_y[0] <= p[4].b)
            && (x_y[1] >= p[4].c && x_y[1] <= p[4].d))
        return 5;
    if ((x_y[0] >= p[5].a && x_y[0] <= p[5].b)
            && (x_y[1] >= p[5].c && x_y[1] <= p[5].d))
        return 6;
    return interaction_2(x_y, p);
}

int mouse(sfRenderWindow* window, sfVector2u w_size)
{
    struct Pos *p = fill(w_size);
    int x_y[3] = {[0 ... 2] = 0};
    sfEvent event;

    if (p == NULL) {
        sfRenderWindow_close(window);
        return 0;
    }
//    printf("a = %d et b = %d\n", p[1].a, p[1].b);
//    printf("c = %d et d = %d\n", p[1].c, p[1].d);
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtMouseButtonPressed
            && event.type != sfEvtClosed) {
            x_y[0] = sfMouse_getPositionRenderWindow(window).x;
            x_y[1] = sfMouse_getPositionRenderWindow(window).y;
            x_y[2] = interaction(x_y, p);
        }
        else if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
    return x_y[2];
}