#include <iostream>
#include <ncurses.h>

int main() {
    initscr();
    if (has_colors() == false) {
        endwin();
        std::cout << "Terminal sem suporte de cor." << std::endl;
        exit(1);
    }

    printw("Controles: WASD"
           "\nQ p/ sair"
           "\nCores: "
           "\n1 - Azul"
           "\n2 - Preto"
           "\n3 - Branco"
           "\n4 - Verde\n:");

    int x = 10;
    int y = 10;

    refresh();

    int ch = 0;

    start_color();
    init_pair(1, COLOR_BLUE, COLOR_BLUE);
    init_pair(2, COLOR_BLACK, COLOR_BLACK);
    init_pair(3, COLOR_WHITE, COLOR_WHITE);
    init_pair(4, COLOR_GREEN, COLOR_GREEN);

    while (ch != 'q') {
        ch = getch();
        int sy, sx;
        getmaxyx(stdscr, sy, sx);

        move(y, x);
        delch();

        switch(std::tolower(ch)) {
            case 'w':
                y--;
            break;

            case 'a':
                x--;
            break;

            case 's':
                y++;
            break;

            case 'd':
                x++;
            break;
        }

        switch(ch) {
            case '1':
                for (int i=1; i <= 4; i++) {
                    if (i != 1) {
                        attroff(COLOR_PAIR(i));
                    }
                }
                attron(COLOR_PAIR(1));
            break;

            case '2':
                for (int i=1; i <= 4; i++) {
                    if (i != 2) {
                        attroff(COLOR_PAIR(i));
                    }
                }
                attron(COLOR_PAIR(2));
            break;

            case '3':
                for (int i=1; i <= 4; i++) {
                    if (i != 3) {
                        attroff(COLOR_PAIR(i));
                    }
                }
                attron(COLOR_PAIR(3));
            break;

            case '4':
                for (int i=1; i <= 4; i++) {
                    if (i != 4) {
                        attroff(COLOR_PAIR(i));
                    }
                }
                attron(COLOR_PAIR(4));
            break;
        }

        y = std::max(1, std::min(sy - 1, y));
        x = std::max(0, std::min(sx - 1, x));

        move(y, x);
        addch('|');
        refresh();
    }
    endwin();
    return 0;
}
