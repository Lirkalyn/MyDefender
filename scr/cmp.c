/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** more-desu
*/

#include "../include/my.h"

int str_cmp(char const *s1, char const *s2)
{
    int i;

    for (i = 0; s1[i] != '\0'; i++)
        if (s1[i] != s2[i])
            return (1);
    return (0);
}

sfIntRect set_rect_en(sfIntRect rect_en)
{
    rect_en.top = 38;
    rect_en.left = 80;
    rect_en.width = 40;
    rect_en.height = 20;
    return (rect_en);
}

sfVector2f set_i(sfVector2f i, int j)
{
    i.x = 0;
    i.y = (525 + (j * 10));
    return (i);
}