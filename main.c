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

void start_game(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow* window = sfRenderWindow_create(mode, "my_defender", sfResize | sfClose, NULL);
    sfEvent event;
    sfTexture* map = sfTexture_createFromFile("Picture/map.jpg", NULL);
    sfSprite* background = sfSprite_create();

    sfRenderWindow_setFramerateLimit(window, 60);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        sfSprite_setTexture(background, map, sfTrue);
        sfRenderWindow_drawSprite(window, background, NULL);
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
    }
}

int main(int argc, char *argv[])
{
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h' && argv[1][2] == '\0') {
            myputstr("...", 0);
            myputstr("ok", 0);
            myputstr("...", 0);
    }
    else
        start_game();
}