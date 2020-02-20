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

void game(sfRenderWindow* window)
{
    int x = 0;
    int y = 0;
    sfEvent event;
    sfTexture* map = sfTexture_createFromFile("Picture/map (copie).jpg", NULL);
//    sfTexture* map = sfTexture_createFromFile("Picture/map.jpg", NULL); map (copie).jpg
    sfSprite* background = sfSprite_create();

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtMouseButtonPressed
            && event.type != sfEvtClosed) {
            x = sfMouse_getPositionRenderWindow(window).x;
            y = sfMouse_getPositionRenderWindow(window).y;
//            printf("x = %d et y = %d\n", x, y);
        }
        else if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
    sfSprite_setTexture(background, map, sfTrue);
    sfRenderWindow_drawSprite(window, background, NULL);
    sfRenderWindow_display(window);
    sfRenderWindow_clear(window, sfBlack);
}

void start_game(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow* window;

    window = sfRenderWindow_create(mode, "defender", sfResize | sfClose, NULL);
//    sfRenderWindow_setFramerateLimit(window, 60);
//    while (sfRenderWindow_isOpen(window))
//        game(window);
//    sfRenderWindow_destroy(window);
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