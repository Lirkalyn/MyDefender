/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** pause menu
*/

#include "../include/my.h"

struct Pos *fill_pause(sfVector2u w_size)
{
    struct Pos *p = malloc(8 * sizeof(struct Pos));

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
    return p;
}

int menu_pause(int *x_y, sfRenderWindow* window)
{
    sfVector2u w_size;
    struct Pos *p;

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
    return 0;
}

void check_pause(int x_y, sfRenderWindow* window)
{
    sfTexture* map = sfTexture_createFromFile("Picture/map (copie).jpg", NULL);
    sfTexture* menu = sfTexture_createFromFile("Picture/Menu.png", NULL);
    sfSprite* me = sfSprite_create();
    int rep = 1;

    if (x_y == 1) {
        sfSprite_destroy(me);
        sfTexture_destroy(menu);
        sfTexture_destroy(map);
    }
    if (x_y == 2) {
        sfSprite_destroy(me);
        sfTexture_destroy(menu);
        start_game(window, map, rep);
    }
    if (x_y == 3) {
        rep = touch_menu(window, menu, me);
        start_game(window, map, rep);
    }
}

void make_pause_menu(sfRenderWindow* window, int *x_y)
{
    sfTexture* pause = sfTexture_createFromFile("Picture/pause.jpg", NULL);
    sfSprite* pa = sfSprite_create();
    sfEvent event;

    while (x_y[2] == 0 && sfRenderWindow_isOpen(window)) {
        sfSprite_setTexture(pa, pause, sfTrue);
        sfRenderWindow_drawSprite(window, pa, NULL);
        sfRenderWindow_display(window);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtMouseButtonPressed 
                && event.type != sfEvtClosed) {
                x_y[0] = sfMouse_getPositionRenderWindow(window).x;
                x_y[1] = sfMouse_getPositionRenderWindow(window).y;
                x_y[2] = menu_pause(x_y, window);
                check_pause(x_y[2], window);
            }
            else if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
    }
}

int pause_menu(sfRenderWindow* window)
{
    sfEvent event;
    int x_y[3] = {[0 ... 2] = 0};

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace) {
            make_pause_menu(window, x_y);
        }
    }
}