/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** main of my_runner
*/

#include "include/my.h"

#include <stdio.h>

en follow_path(en enem, int i)
{
    static int step = 0;

    if (enem.i.x <= (350 + (i * 10)))
        enem.i.x += 7;
    if (enem.i.x > (350 + (i * 10)) && enem.i.y > (340 - (i * 10))
            && step == 0)
        enem.i.y -= 7;
    if (enem.i.y <= (340 - (i * 10)) && enem.i.x <= (1160 + (i * 10)))
        enem.i.x += 7;
    if (enem.i.x > (1160 + (i * 10)) && enem.i.y < (850 + (i * 10))) {
        step += 1;
        enem.i.y += 7;
    }
    if (enem.i.x > (1160 + (i * 10)) && enem.i.y >= (850 + (i * 10)))
        enem.i.x += 7;
    return enem;
}

en *set_Clock_pos(en *enem)
{
    sfClock *clock;
    sfTime time;
    float seconds;
    static int cpt = 0;

    clock = sfClock_create();
    while (1) {
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.0;
        if (seconds > 0.085) {
            for (int i = 0; i < 10; i++) {
                enem[i] = follow_path(enem[i], i);
                enem[i].rect_en.left += (cpt == 1) ? (-40) : 40;
            }
            cpt += (cpt == 1) ? (-1) : 1;
            sfClock_restart(clock);
            return (enem);
        }
    }
}

void game(sfRenderWindow* window, sfSprite* bg, en *enem)
{
    sfVector2u w_size;
    int mous = 0;

    while (sfRenderWindow_isOpen(window)) {
        w_size = sfRenderWindow_getSize(window);
        mous = mouse(window, w_size);
        enem = fill_en(enem, NULL, 1);
//        printf("ok = %d\n", ok);
//        printf("hei = %d et wid = %d\n", w_size.x, w_size.y);
        sfRenderWindow_drawSprite(window, bg, NULL);
        for (int i = 0; i < 10; i++)
            sfRenderWindow_drawSprite(window, enem[i].en, NULL);
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
        enem = set_Clock_pos(enem);
    }
}

void start_game(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow* window;
//    sfTexture* map = sfTexture_createFromFile("Picture/map (copie).jpg", NULL);
    sfTexture* map = sfTexture_createFromFile("Picture/map.jpg", NULL);
    sfTexture* enemy = sfTexture_createFromFile("Picture/R_W_Enemy.png", NULL);
    sfSprite* bg = sfSprite_create();
    en *enem;

    window = sfRenderWindow_create(mode, "defender", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 30);
    sfSprite_setTexture(bg, map, sfTrue);
    enem = fill_en(enem, enemy, 0);
    game(window, bg, enem);
    sfRenderWindow_destroy(window);
}

int main(int argc, char *argv[])
{
    if (argc == 2 && str_cmp(argv[1], "-h") == 0) {
            myputstr("...", 0);
            myputstr("ok", 0);
            myputstr("...", 0);
    }
    else
        start_game();
}