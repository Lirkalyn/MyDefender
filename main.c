/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** main of my_runner
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "include/my.h"

#include <stdio.h>

int interaction(int *x_y)
{
    int rsl = 0;

    if ((x_y[0] >= 168 && x_y[0] <= 295) && (x_y[1] >= 394 && x_y[1] <= 470))
        rsl = 1;
    if ((x_y[0] >= 520 && x_y[0] <= 659) && (x_y[1] >= 391 && x_y[1] <= 467))
        rsl = 2;
    if ((x_y[0] >= 965 && x_y[0] <= 1093) && (x_y[1] >= 395 && x_y[1] <= 472))
        rsl = 3;
    if ((x_y[0] >= 991 && x_y[0] <= 1120) && (x_y[1] >= 912 && x_y[1] <= 988))
        rsl = 4;
    if ((x_y[0] >= 1354 && x_y[0] <= 1483) && (x_y[1] >= 718 && x_y[1] <= 796))
        rsl = 5;
    if ((x_y[0] >= 1404 && x_y[0] <= 1516) && (x_y[1] >= 43 && x_y[1] <= 190))
        rsl = 6;
    if ((x_y[0] >= 1537 && x_y[0] <= 1647) && (x_y[1] >= 44 && x_y[1] <= 190))
        rsl = 7;
    if ((x_y[0] >= 1673 && x_y[0] <= 1784) && (x_y[1] >= 44 && x_y[1] <= 191))
        rsl = 8;
    return rsl;
}

void game(sfRenderWindow* window, sfSprite* bg)
{
    int x_y[3] = {[0 ... 2] = 0};
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtMouseButtonPressed
            && event.type != sfEvtClosed) {
            x_y[0] = sfMouse_getPositionRenderWindow(window).x;
            x_y[1] = sfMouse_getPositionRenderWindow(window).y;
            x_y[2] = interaction(x_y);
            printf("c'est %d\n", x_y[2]);
/*            else {
                myputstr("c'est pas 1\n", 0);
                printf("x = %d et y = %d\n", x_y[0], x_y[1]);
            }*/
        }
        else if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
    sfRenderWindow_drawSprite(window, bg, NULL);
    sfRenderWindow_display(window);
    sfRenderWindow_clear(window, sfBlack);
}

void start_game(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow* window;
//    sfTexture* map = sfTexture_createFromFile("Picture/map (copie).jpg", NULL);
    sfTexture* map = sfTexture_createFromFile("Picture/map.jpg", NULL);
    sfSprite* bg = sfSprite_create();

    window = sfRenderWindow_create(mode, "defender", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 30);
    sfSprite_setTexture(bg, map, sfTrue);
    while (sfRenderWindow_isOpen(window))
        game(window, bg);
    sfRenderWindow_destroy(window);
}

int main(int argc, char *argv[])
{
    if (argc == 2 && str_cmp(argv[1], "-h") == 0) {
            myputstr("...", 0);
            myputstr("ok", 0);
            myputstr("...", 0);
    }
    else
        start_game();
}