/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** menu
*/

#include "../include/my.h"

pos *fill_menu(sfVector2u w_size)
{
    pos *p = malloc(8 * sizeof(pos));

    if (p == NULL)
        return NULL;
    p[0].a = (795 * w_size.x)/1971;
    p[0].b = (1177 * w_size.x)/1971;
    p[0].c = (148 * w_size.y)/1008;
    p[0].d = (258 * w_size.y)/1008;
    p[1].a = (832 * w_size.x)/1971;
    p[1].b = (1152 * w_size.x)/1971;
    p[1].c = (356 * w_size.y)/1008;
    p[1].d = (463 * w_size.y)/1008;
    p[2].a = (849 * w_size.x)/1971;
    p[2].b = (1158 * w_size.x)/1971;
    p[2].c = (567 * w_size.y)/1008;
    p[2].d = (676 * w_size.y)/1008;
    return p;
}

int menu_int(int *x_y, sfRenderWindow* window)
{
    sfVector2u w_size;
    pos *p;

    w_size = sfRenderWindow_getSize(window);
    p = fill_menu(w_size);
    if ((x_y[0] >= p[0].a && x_y[0] <= p[0].b)
            && (x_y[1] >= p[0].c && x_y[1] <= p[0].d))
        return 1;
    if ((x_y[0] >= p[1].a && x_y[0] <= p[1].b)
            && (x_y[1] >= p[1].c && x_y[1] <= p[1].d))
        return 2;
    if ((x_y[0] >= p[2].a && x_y[0] <= p[2].b)
            && (x_y[1] >= p[2].c && x_y[1] <= p[2].d))
        return 3;
    return 0;
}

int touch_menu(sfRenderWindow* window, sfTexture* menu, sfSprite* me)
{
    sfEvent event;
    int x_y[3] = {[0 ... 2] = 0};

    while (x_y[2] == 0 && sfRenderWindow_isOpen(window)) {
        sfSprite_setTexture(me, menu, sfTrue);
        sfRenderWindow_drawSprite(window, me, NULL);
        sfRenderWindow_display(window);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtMouseButtonPressed
                && event.type != sfEvtClosed) {
                x_y[0] = sfMouse_getPositionRenderWindow(window).x;
                x_y[1] = sfMouse_getPositionRenderWindow(window).y;
                x_y[2] = menu_int(x_y, window);
            }
            else if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
    }
    return x_y[2];
}