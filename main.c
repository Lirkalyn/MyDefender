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

void game(sfRenderWindow* window, sfSprite* bg)
{
    int x_y[2] = {[0 ... 1] = 0};
    sfEvent event;
//    sfTexture* map = sfTexture_createFromFile("Picture/map (copie).jpg", NULL);
//    sfTexture* map = sfTexture_createFromFile("Picture/map.jpg", NULL);
//    sfSprite* background = sfSprite_create();

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtMouseButtonPressed
            && event.type != sfEvtClosed) {
            x_y[0] = sfMouse_getPositionRenderWindow(window).x;
            x_y[1] = sfMouse_getPositionRenderWindow(window).y;
//            x_y[0] = sfMouse_getPosition(window).x;
//            x_y[1] = sfMouse_getPosition(window).y;
            if ((x_y[0] >= 168 && x_y[0] <= 295) && (x_y[1] >= 394 && x_y[1] <= 470))
                myputstr("c'est 1\n", 0);
            else {
                myputstr("c'est pas 1\n", 0);
                printf("x = %d et y = %d\n", x_y[0], x_y[1]);
            }
        }
        else if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
//    sfSprite_setTexture(background, map, sfTrue);
    sfRenderWindow_drawSprite(window, bg, NULL);
    sfRenderWindow_display(window);
    sfRenderWindow_clear(window, sfBlack);
}

void start_game(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow* window;
    sfTexture* map = sfTexture_createFromFile("Picture/map (copie).jpg", NULL);
//    sfTexture* map = sfTexture_createFromFile("Picture/map.jpg", NULL);
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