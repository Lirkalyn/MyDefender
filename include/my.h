/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** h-desu
*/

#ifndef _MY_H_
#define _MY_H_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

struct Pos {
    int a;
    int b;
    int c;
    int d;
};

typedef struct En {
    sfSprite* en;
    sfIntRect rect_en;
    sfVector2f i;
    int lp;
} en;

void my_putchar(char c);
int myputstr(char *str, int opt);
int my_puterror(char *str, int opt);
int my_put_nbr(int nb);
int str_cmp(char const *s1, char const *s2);
sfIntRect set_rect_en(sfIntRect rect_en);
sfVector2f set_i(sfVector2f i, int j);
en *set_Clock_ani(en *enem);
int mouse(sfRenderWindow* window, sfVector2u w_size);
struct Pos *fill(sfVector2u w_size);
en *fill_en(en *enem, sfTexture* enemy, int opt);
en *set_Clock_pos(en *enem);

#endif
