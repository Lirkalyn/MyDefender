/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** main of my_runner
*/

#include "include/my.h"

int main_2(int argc, char *argv[], char *envp[])
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow* window;
    sfTexture* map = sfTexture_createFromFile("Picture/map.jpg", NULL);
    sfTexture* menu = sfTexture_createFromFile("Picture/Menu.png", NULL);
    sfSprite* me = sfSprite_create();
    sfSprite* bg = sfSprite_create();
    int rep;

    window = sfRenderWindow_create(mode, "defender", sfResize | sfClose, NULL);
    rep = touch_menu(window, menu, me);
    sfSprite_setTexture(bg, map, sfTrue);
    if (start_game(window, bg, rep) == 23)
        return main_2(argc, argv, envp);
    else
        return 0;
}