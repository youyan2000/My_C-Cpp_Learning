#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <ncurses.h>

#define ROWS 20
#define COLS 10
#define TETROMINOES 7

int shapes[TETROMINOES][4][4] = {
    {{0,1,0,0},{0,1,0,0},{0,1,0,0},{0,1,0,0}},
    {{0,1,1,0},{0,1,1,0},{0,0,0,0},{0,0,0,0}},
    {{0,1,0,0},{1,1,1,0},{0,0,0,0},{0,0,0,0}},
    {{0,1,1,0},{1,1,0,0},{0,0,0,0},{0,0,0,0}},
    {{1,1,0,0},{0,1,1,0},{0,0,0,0},{0,0,0,0}},
    {{1,0,0,0},{1,1,1,0},{0,0,0,0},{0,0,0,0}},
    {{0,0,1,0},{1,1,1,0},{0,0,0,0},{0,0,0,0}}
};

int map[ROWS][COLS] = {0};
int curX, curY, curType;
int score = 0;

int check(int x, int y, int type) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (shapes[type][i][j]) {
                int nx = x + j;
                int ny = y + i;
                if (nx < 0 || nx >= COLS || ny >= ROWS) return 0;
                if (ny >= 0 && map[ny][nx]) return 0;
            }
        }
    }
    return 1;
}

void fixBlock() {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (shapes[curType][i][j])
                map[curY + i][curX + j] = 1;
}

void clearLines() {
    int lines = 0;
    for (int i = ROWS - 1; i >= 0; i--) {
        int full = 1;
        for (int j = 0; j < COLS; j++)
            if (!map[i][j]) { full = 0; break; }
        if (full) {
            lines++;
            for (int k = i; k > 0; k--)
                for (int j = 0; j < COLS; j++)
                    map[k][j] = map[k-1][j];
            for (int j = 0; j < COLS; j++) map[0][j] = 0;
            i++;
        }
    }
    if (lines == 1) score += 100;
    else if (lines == 2) score += 300;
    else if (lines == 3) score += 500;
    else if (lines >= 4) score += 1000;
}

void newBlock() {
    curType = rand() % TETROMINOES;
    curX = COLS / 2 - 2;
    curY = 0;
    if (!check(curX, curY, curType)) {
        clear();
        mvprintw(ROWS/2, COLS-5, "GAME OVER");
        mvprintw(ROWS/2+1, COLS-6, "Score: %d", score);
        refresh();
        napms(2000);
        endwin();
        exit(0);
    }
}

void draw() {
    clear();
    for (int i = 0; i <= ROWS; i++) {
        for (int j = 0; j <= COLS; j++) {
            if (i == 0 || j == 0 || j == COLS)
                mvprintw(i, j*2, "[]");
            else {
                int filled = map[i-1][j-1];
                for (int di = 0; di <4; di++)
                    for (int dj =0; dj <4; dj++)
                        if (curY+di == i-1 && curX+dj == j-1 && shapes[curType][di][dj])
                            filled = 1;
                if (filled) mvprintw(i, j*2, "[]");
                else mvprintw(i, j*2, "  ");
            }
        }
    }
    mvprintw(2, COLS*2 + 4, "Score: %d", score);
    mvprintw(4, COLS*2 +4, "UP: Rotate");
    mvprintw(5, COLS*2 +4, "LEFT/RIGHT: Move");
    mvprintw(6, COLS*2 +4, "DOWN: Speed");
    mvprintw(8, COLS*2 +4, "Q: Quit");
    refresh();
}

void rotate() {
    int tmp[4][4];
    for (int i=0; i<4; i++) for (int j=0; j<4; j++) tmp[i][j] = shapes[curType][i][j];
    int rot[4][4];
    for (int i=0; i<4; i++) for (int j=0; j<4; j++) rot[i][j] = tmp[3-j][i];
    for (int i=0; i<4; i++) for (int j=0; j<4; j++) shapes[curType][i][j] = rot[i][j];
    if (!check(curX, curY, curType))
        for (int i=0; i<4; i++) for (int j=0; j<4; j++) shapes[curType][i][j] = tmp[i][j];
}

void down() {
    if (check(curX, curY+1, curType)) curY++;
    else { fixBlock(); clearLines(); newBlock(); }
}

void moveBlock(int dx) {
    if (check(curX+dx, curY, curType)) curX += dx;
}

int main() {
    initscr();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    curs_set(0);
    srand(time(NULL));
    newBlock();

    while (1) {
        draw();
        int c = getch();
        switch (c) {
            case KEY_UP: rotate(); break;
            case KEY_LEFT: moveBlock(-1); break;
            case KEY_RIGHT: moveBlock(1); break;
            case KEY_DOWN: down(); break;
            case 'q': endwin(); exit(0);
        }
        down();
        napms(500);
    }
    endwin();
    return 0;
}



