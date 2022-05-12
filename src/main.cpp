#include <iostream>
#include "constants.h"
#include "node.h"
#include "maze.h"

int main() {
    Node grid[HEIGHT][WIDTH];
    for(int j=0; j<HEIGHT; j++) {
        for(int i=0; i<WIDTH; i++) {
            grid[j][i].set_position(j, i);
        }
    }

    Maze maze(grid[0]);
    maze.generate_maze(time(NULL) % 1000);
    maze.display_maze();
    return 0;
}