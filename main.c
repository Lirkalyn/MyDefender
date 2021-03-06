/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** main of my_runner
*/

#include "include/my.h"

//#include <stdio.h>

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

en *set_Clock_pos(en *enem, int opt)
{
    sfClock *clock;
    sfTime time;
    float seconds;
    static int cpt = 0;

    cpt = (opt != 0 && cpt == 1) ? 0 : cpt;
    clock = (opt == 0) ? sfClock_create() : NULL;
    while (opt == 0) {
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

int game(sfRenderWindow* window, sfSprite* bg, en *enem, tow *towe)
{
    sfVector2u w_size;
    int mous = 0;
    int *nb = fill_nb();

    while (sfRenderWindow_isOpen(window)) {
        w_size = sfRenderWindow_getSize(window);
        mous = mouse(window, w_size);
        enem = fill_en(enem, NULL, 1);
        if (mous >= 22)
            return mous;
        else if (mous >= 6 && mous <= 8)
            towe = place_tower(towe, mous, &nb[0], window);
        sfRenderWindow_drawSprite(window, bg, NULL);
        draw(window, nb[0], enem, towe);
        enem = set_Clock_pos(enem, 0);
        get_hit(towe, enem, nb, window);
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
    }
}

int start_game(sfRenderWindow* window, sfSprite *bg, int rep)
{
    sfTexture* enemy = sfTexture_createFromFile("Picture/R_W_Enemy.png", NULL);
    en *enem;
    tow *towe;
    int over;

    if (rep == 1) {
    sfRenderWindow_setFramerateLimit(window, 30);
    enem = fill_en(enem, enemy, 0);
    towe = fill_tower(towe);
    over = game(window, bg, enem, towe);
    if (over == 22)
        return start_game(window, bg, rep);
    sfRenderWindow_destroy(window);
    if (over == 23 || over == 24)
        return over;
    }
    else if (rep == 2)
        ;
    else
        sfRenderWindow_close(window);
}

int main(int argc, char *argv[], char *envp[])
{
    if (envp[0] == NULL)
        return 84;
    else
        return main_2(argc, argv, envp);
}