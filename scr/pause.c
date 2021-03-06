/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** pause menu
*/

#include "../include/my.h"

pos *fill_pause_2(sfVector2u w_size, pos *p)
{
    p[3].a = (804 * w_size.x)/1920;
    p[3].b = (1199 * w_size.x)/1920;
    p[3].c = (800 * w_size.y)/1008;
    p[3].d = (920 * w_size.y)/1008;
    return p;
}

pos *fill_pause(sfVector2u w_size)
{
    pos *p = malloc(4 * sizeof(pos));

    if (p == NULL)
        return NULL;
    p[0].a = (804 * w_size.x)/1920;
    p[0].b = (1099 * w_size.x)/1920;
    p[0].c = (298 * w_size.y)/1008;
    p[0].d = (450 * w_size.y)/1008;
    p[1].a = (804 * w_size.x)/1920;
    p[1].b = (1199 * w_size.x)/1920;
    p[1].c = (474 * w_size.y)/1008;
    p[1].d = (608 * w_size.y)/1008;
    p[2].a = (804 * w_size.x)/1920;
    p[2].b = (1199 * w_size.x)/1920;
    p[2].c = (633 * w_size.y)/1008;
    p[2].d = (781 * w_size.y)/1008;
    p = fill_pause_2(w_size, p);
    return p;
}

int menu_pause(int *x_y, sfRenderWindow* window)
{
    sfVector2u w_size;
    pos *p;

    w_size = sfRenderWindow_getSize(window);
    p = fill_pause(w_size);
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
    return 0;
}

sfSprite *pa_maker(void)
{
    sfTexture* pause = sfTexture_createFromFile("Picture/pause_3.png", NULL);
    sfSprite* pa = sfSprite_create();

    sfSprite_setTexture(pa, pause, sfTrue);
    return pa;
}

int make_pause_menu(sfRenderWindow* window, int *x_y)
{
    sfSprite* pa = pa_maker();
    sfEvent event;

    while (x_y[2] == 0 && sfRenderWindow_isOpen(window)) {
        sfRenderWindow_drawSprite(window, pa, NULL);
        sfRenderWindow_display(window);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtMouseButtonPressed
                && event.type != sfEvtClosed) {
                x_y[0] = sfMouse_getPositionRenderWindow(window).x;
                x_y[1] = sfMouse_getPositionRenderWindow(window).y;
                x_y[2] = menu_pause(x_y, window);
                if (x_y[2] == 2 || x_y[2] == 3)
                    set_Clock_pos(NULL, 1);
                return (x_y[2] + 20);
            }
            else if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
    }
}