/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** mor tower-desu
*/

#include "../include/my.h"

sfVector2f set_pos(sfVector2f i, int opt)
{
    if (opt == 0) {
        i.x = 1425;
        i.y = 57;
    }
    return (i);
}