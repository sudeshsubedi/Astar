#include <iostream>
#include "constants.h"
#include "node.h"
#include "maze.h"
#include "astar.h"

void display(Node*);

int main() {
    Node grid[HEIGHT][WIDTH];
    for(int j=0; j<HEIGHT; j++) {
        for(int i=0; i<WIDTH; i++) {
            grid[j][i].set_position(j, i);
        }
    }

    Maze maze(grid[0]);
    maze.generate_maze(234, false);
    //maze.display_maze();
    Astar a;
    a.find_path(grid[0], &grid[HEIGHT-1][WIDTH-1], true);
    a.print(grid[0], "output.txt");
    //display(grid[0]);
    // for(auto& node: a.get_path()) {
    //     std::cout << "(" << node->get_row() << ", " << node->get_col() << ")\t";
    // }
    return 0;
}



// void display(Node* start) {
//     // system("clear");
//     // std::cout << CLEAR;
//     for(int k=0; k<=WIDTH; k++) std::cout << BG_RED << "__" << RESET;
//     std::cout << '\n';
//     for(int j=0; j<HEIGHT; j++) {
//         for(int i=0; i<WIDTH; i++) {
//             Status stat = (start + j*WIDTH + i)->get_status();
//             switch (stat)
//             {
//             case WALL:
//                 std::cout << BG_WHITE << "  " << RESET;
//                 break;
//             case DEFAULT:
//                 std::cout << BG_GREEN << "  " << RESET;
//                 break;
//             case START:
//                 std::cout << BG_YELLOW << "  " << RESET;
//                 break;
//             case END:
//                 std::cout << BG_MAGENTA << "  " << RESET;
//                 break;
//             case PATH:                                                                                                                                              
//                 std::cout << BG_PATH << "  " << RESET;
//                 break;
//             case CLOSED:
//                 std::cout << BG_CLOSED << "  " << RESET;
//                 break;
//             default:
//                 std::cout << BG_GREEN << "  " << RESET;
//                 break;
//             }
//         }
//         std::cout << BG_RED << "||" << RESET;
//         std::cout << '\n';
//     }
// }