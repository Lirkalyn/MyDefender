int interaction(int *x_y, struct Pos *p)
{
    int rsl = 0;

//    if ((x_y[0] >= 168 && x_y[0] <= 295) && (x_y[1] >= 394 && x_y[1] <= 470))
//        rsl = 1;
    if ((x_y[0] >= p[1].a && x_y[0] <= p[1].b) && (x_y[1] >= p[1].c && x_y[1] <= p[1].d))
        rsl = 1;
    if ((x_y[0] >= 520 && x_y[0] <= 659) && (x_y[1] >= 391 && x_y[1] <= 467))
        rsl = 2;
    if ((x_y[0] >= 965 && x_y[0] <= 1093) && (x_y[1] >= 395 && x_y[1] <= 472))
        rsl = 3;
    if ((x_y[0] >= 991 && x_y[0] <= 1120) && (x_y[1] >= 912 && x_y[1] <= 988))
        rsl = 4;
    if ((x_y[0] >= 1354 && x_y[0] <= 1483) && (x_y[1] >= 718 && x_y[1] <= 796))
        rsl = 5;
    if ((x_y[0] >= 1404 && x_y[0] <= 1516) && (x_y[1] >= 43 && x_y[1] <= 190))
        rsl = 6;
    if ((x_y[0] >= 1537 && x_y[0] <= 1647) && (x_y[1] >= 44 && x_y[1] <= 190))
        rsl = 7;
    if ((x_y[0] >= 1673 && x_y[0] <= 1784) && (x_y[1] >= 44 && x_y[1] <= 191))
        rsl = 8;
    return rsl;
}



int set_Clock_ani(sfIntRect rect)
{
    sfClock *clock;
    sfTime time;
    float seconds;

    clock = sfClock_create();
    while (1) {
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.0;
        if (seconds > 0.085) {
            rect.left = move_rect(rect);
            sfClock_restart(clock);
            return (rect.left);
        }
    }
}


int pause_menu(sfRenderWindow* window)
{
    sfEvent event;
    int x_y[3] = {[0 ... 2] = 0};

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace) {
            make_pause_menu(window, x_y);
        }
    }
}