/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** tow-desu
*/

#include "../include/my.h"

sfIntRect set_rect_spr(sfIntRect rect_spr, int opt)
{
    if (opt == 0) {
        rect_spr.top = 4;
        rect_spr.left = 5;
    }
    else if (opt == 1) {
        rect_spr.top = 39;
        rect_spr.left = 18;
    }
    else {
        rect_spr.top = 39;
        rect_spr.left = 18;
    }
    rect_spr.width = 100;
    rect_spr.height = 150;
    return (rect_spr);
}

tow *fill_first(tow *towe, sfTexture* tex_f)
{
    towe[0].which = 1;
    towe[0].spr = sfSprite_create();
    sfSprite_setTexture(towe[0].spr, tex_f, sfTrue);
    towe[0].rect_spr = set_rect_spr(towe[0].rect_spr, 0);
    towe[0].pos = set_pos(towe[0].pos, 0);
    sfSprite_setTextureRect(towe[0].spr, towe[0].rect_spr);
    sfSprite_setPosition(towe[0].spr, towe[0].pos);
    towe[0].damage = 5;
    towe[0].shape = sfCircleShape_create();
    sfCircleShape_setFillColor(towe[0].shape, sfTransparent);
    towe[0].hit_pos.x = 0;
    towe[0].hit_pos.y = 0;
    sfCircleShape_setPosition(towe[0].shape, towe[0].hit_pos);
    sfCircleShape_setRadius(towe[0].shape, 50);
    return towe;
}

tow *fill_second(tow *towe, sfTexture* tex_i)
{
    towe[1].which = 2;
    towe[1].spr = sfSprite_create();
    sfSprite_setTexture(towe[1].spr, tex_i, sfTrue);
    towe[1].rect_spr = set_rect_spr(towe[1].rect_spr, 1);
    towe[1].pos = set_pos(towe[1].pos, 1);
    sfSprite_setTextureRect(towe[1].spr, towe[1].rect_spr);
    sfSprite_setPosition(towe[1].spr, towe[1].pos);
    towe[1].damage = 5;
    towe[1].shape = sfCircleShape_create();
    sfCircleShape_setFillColor(towe[1].shape, sfTransparent);
    towe[1].hit_pos.x = 0;
    towe[1].hit_pos.y = 0;
    sfCircleShape_setPosition(towe[1].shape, towe[1].hit_pos);
    sfCircleShape_setRadius(towe[1].shape, 50);
    return towe;
}

tow *fill_last(tow *towe, sfTexture* tex_o)
{
    towe[2].which = 3;
    towe[2].spr = sfSprite_create();
    sfSprite_setTexture(towe[2].spr, tex_o, sfTrue);
    towe[2].rect_spr = set_rect_spr(towe[2].rect_spr, 2);
    towe[2].pos = set_pos(towe[2].pos, 2);
    sfSprite_setTextureRect(towe[2].spr, towe[2].rect_spr);
    sfSprite_setPosition(towe[2].spr, towe[2].pos);
    towe[2].damage = 5;
    towe[2].shape = sfCircleShape_create();
    sfCircleShape_setFillColor(towe[2].shape, sfTransparent);
    towe[2].hit_pos.x = 0;
    towe[2].hit_pos.y = 0;
    sfCircleShape_setPosition(towe[2].shape, towe[2].hit_pos);
    sfCircleShape_setRadius(towe[2].shape, 50);
    return towe;
}

tow *fill_tower(tow *towe)
{
    sfTexture* tex_f = sfTexture_createFromFile("Picture/f_t_2.png", NULL);
    sfTexture* tex_i = sfTexture_createFromFile("Picture/i_t.png", NULL);
    sfTexture* tex_o = sfTexture_createFromFile("Picture/i_t.png", NULL);

    towe = malloc(11 * sizeof(en));
    towe[10].tex_f = tex_f;
    towe[10].tex_i = tex_i;
    towe[10].tex_o = tex_o;
    towe = fill_first(towe, tex_f);
    towe = fill_second(towe, tex_i);
    towe = fill_last(towe, tex_o);
    return towe;
}