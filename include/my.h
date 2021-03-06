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
#include <math.h>

typedef struct Pos {
    int a;
    int b;
    int c;
    int d;
} pos;

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
    sfTexture* tex;
} tow;

void my_putchar(char c);
int myputstr(char *str, int opt);
int my_puterror(char *str, int opt);
int my_put_nbr(int nb);
int str_cmp(char const *s1, char const *s2);
sfIntRect set_rect_en(sfIntRect rect_en);
sfVector2f set_i(sfVector2f i, int j);
int mouse(sfRenderWindow* window, sfVector2u w_size);
pos *fill(sfVector2u w_size);
en *fill_en(en *enem, sfTexture* enemy, int opt);
en *set_Clock_pos(en *enem, int opt);
tow *fill_tower(tow *towe);
sfVector2f set_pos(sfVector2f i, int opt);
tow *place_tower(tow *towe, int tow, int *towe_nb, sfRenderWindow* window);
int touch_menu(sfRenderWindow* window, sfTexture* menu, sfSprite* me);
sfVector2f fire_pos(sfVector2f pos, int where);
sfVector2f ice_pos(sfVector2f pos, int where);
tow *hit_box_maker(tow *towe, int *mem);
void draw(sfRenderWindow* window, int towe_nb, en *enem, tow *towe);
int pause_menu(sfRenderWindow* window);
int make_pause_menu(sfRenderWindow* window, int *x_y);
void get_hit(tow *towe, en *enem, int *nb, sfRenderWindow* window);
int *fill_nb(void);
sfSprite *bullet_maker(sfVector2f pos);
sfSprite *bullet_moover(sfSprite *spr, sfVector2f pos);
int main_2(int argc, char *argv[], char *envp[]);
int start_game(sfRenderWindow* window, sfSprite *bg, int rep);

#endif
