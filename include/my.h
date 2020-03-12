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

typedef struct Tower {
    int which;
    sfSprite* spr;
    sfIntRect rect_spr;
    sfVector2f pos;
    int damage;
    sfCircleShape *shape;
    sfVector2f hit_pos;
    sfTexture* tex_f;
    sfTexture* tex_i;
    sfTexture* tex_o;
} tow;

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
tow *fill_tower(tow *towe);
sfVector2f set_pos(sfVector2f i, int opt);
tow *place_tower(tow *towe, int tow, int *towe_nb, sfRenderWindow* window);
int touch_menu(sfRenderWindow* window, sfTexture* menu, sfSprite* me);

#endif
