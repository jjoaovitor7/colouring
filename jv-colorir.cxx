#include <ncurses.h>
#include <sys/param.h>

int main()
{
    initscr();

    printw("Controles: WASD"
           "\nQ p/ sair"
           "\nCores: "
           "\n1 - amarelo"
           "\n2 - verde"
           "\n3 - branco"
           "\n4 - azul"
           "\n5 - preto"
           "\n6 - vermelho\n");

    int x = 10;
    int y = 10;

    refresh();

    int ch = 0;

    while (ch != 'q')
    {
        ch = getch();

        int sy, sx;
        getmaxyx(stdscr, sy, sx);

        move(y, x);

        delch();

        if (ch == 'w')
        {
            y--;
        }

        if (ch == 'a')
        {
            x--;
        }

        if (ch == 's')
        {
            y++;
        }

        if (ch == 'd')
        {
            x++;
        }

        start_color();

        init_pair(1, COLOR_YELLOW, COLOR_YELLOW);
        init_pair(2, COLOR_GREEN, COLOR_GREEN);
        init_pair(3, COLOR_WHITE, COLOR_WHITE);
        init_pair(4, COLOR_BLUE, COLOR_BLUE);
        init_pair(5, COLOR_BLACK, COLOR_BLACK);
        init_pair(6, COLOR_RED, COLOR_RED);

        if (ch == '1')
        {
            attroff(COLOR_PAIR(2));
            attroff(COLOR_PAIR(3));
            attroff(COLOR_PAIR(4));
            attroff(COLOR_PAIR(5));
            attroff(COLOR_PAIR(6));
            attron(COLOR_PAIR(1));
        }

        if (ch == '2')
        {
            attroff(COLOR_PAIR(1));
            attroff(COLOR_PAIR(3));
            attroff(COLOR_PAIR(4));
            attroff(COLOR_PAIR(5));
            attroff(COLOR_PAIR(6));
            attron(COLOR_PAIR(2));
        }

        if (ch == '3')
        {
            attroff(COLOR_PAIR(1));
            attroff(COLOR_PAIR(2));
            attroff(COLOR_PAIR(4));
            attroff(COLOR_PAIR(5));
            attroff(COLOR_PAIR(6));
            attron(COLOR_PAIR(3));
        }

        if (ch == '4')
        {
            attroff(COLOR_PAIR(1));
            attroff(COLOR_PAIR(2));
            attroff(COLOR_PAIR(3));
            attroff(COLOR_PAIR(5));
            attroff(COLOR_PAIR(6));
            attron(COLOR_PAIR(4));
        }

        if (ch == '5')
        {
            attroff(COLOR_PAIR(1));
            attroff(COLOR_PAIR(2));
            attroff(COLOR_PAIR(3));
            attroff(COLOR_PAIR(4));
            attroff(COLOR_PAIR(6));
            attron(COLOR_PAIR(5));
        }

        if (ch == '6')
        {
            attroff(COLOR_PAIR(1));
            attroff(COLOR_PAIR(2));
            attroff(COLOR_PAIR(3));
            attroff(COLOR_PAIR(4));
            attroff(COLOR_PAIR(5));
            attron(COLOR_PAIR(6));
        }

        y = MAX(1, MIN(sy - 1, y));
        x = MAX(0, MIN(sx - 1, x));

        move(y, x);

        addch('|');

        refresh();
    }

    endwin();

    return 0;
}