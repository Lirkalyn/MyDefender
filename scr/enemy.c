/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** bad-desu
*/

#include "../include/my.h"

en *fill_en(en *enem, sfTexture* enemy, int opt)
{
    if (opt == 0) {
        enem = malloc(10 * sizeof(en));
        for (int j = 0; j < 10; j++) {
            enem[j].en = sfSprite_create();
            sfSprite_setTexture(enem[j].en, enemy, sfTrue);
            enem[j].rect_en = set_rect_en(enem[j].rect_en);
            enem[j].i = set_i(enem[j].i, j);
            enem[j].lp = 20;
        }
    }
    if (opt == 1)
        for (int j = 0; j < 10; j++) {
        sfSprite_setTextureRect(enem[j].en, enem[j].rect_en);
        sfSprite_setPosition(enem[j].en, enem[j].i);
    }
    return enem;
}