/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** to draw everything-desu
*/

#include "../include/my.h"

void draw(sfRenderWindow* window, int towe_nb, en *enem, tow *towe)
{
    for (int i = 0; i < towe_nb; i++)
        sfRenderWindow_drawCircleShape(window, towe[i].shape, NULL);
    for (int i = 0; i < 10; i++)
        sfRenderWindow_drawSprite(window, enem[i].en, NULL);
    for (int i = 0; i < towe_nb; i++)
        sfRenderWindow_drawSprite(window, towe[i].spr, NULL);
}