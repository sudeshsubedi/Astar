#pragma once

#define HEIGHT 35 // 35 // in the form of 2 * n - 1
#define WIDTH 71 // 71 // in the form of 2 * n - 1


#define RESET "\033[0m"
#define BG_BLACK "\033[40m"
#define BG_RED "\033[41m"
#define BG_GREEN "\033[42m"
#define BG_YELLOW "\033[43m"
#define BG_BLUE "\033[44m"
#define BG_MAGENTA "\033[45m"
#define BG_CYAN "\033[46m"
#define BG_PATH "\033[48;5;20m"
#define BG_CLOSED "\033[48;5;26m"
#define BG_WHITE "\033[47m"
#define CLEAR "\033[H\033[J"

enum Status {
    DEFAULT, START, END, PATH, CLOSED, WALL, OPEN
};