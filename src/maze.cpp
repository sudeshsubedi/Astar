#include "maze.h"

void Maze::generate_maze(int sd, bool display_process) {
    seed = sd;
    visited.push_back(start);
    while(visited.size() > 0) {
        current = visited.at(visited.size() - 1);
        current->set_visited(true);
        current->set_status(DEFAULT);
        // std::cout << "test: (" << current->get_row() << ", " << current->get_col() << ")\n";
        next = get_neighbor(current);

        if(!has_neighbor) {
            visited.pop_back();
            continue;
        } else {
            visited.push_back(next);
        }
        if(display_process) {
            display_maze();
            std::this_thread::sleep_for(std::chrono::milliseconds(5));
        }
    }
}

Node* Maze::get_neighbor(Node* curr_node) {
    has_neighbor = false;
    std::vector<Node*> neighbors;
    if( curr_node->get_row() > 0 && !( (curr_node - WIDTH * 2)->get_visited() ) ) {
        neighbors.push_back(curr_node - WIDTH * 2);
        has_neighbor = true;
    }

    if( curr_node->get_col() > 0 && !( (curr_node - 2)->get_visited() ) ) {
        neighbors.push_back(curr_node - 2);
        has_neighbor = true;
    }

    if( curr_node->get_row() < HEIGHT - 1 && !( (curr_node + WIDTH * 2)->get_visited() ) ) {
        neighbors.push_back(curr_node + WIDTH * 2);
        has_neighbor = true;
    }

    if( curr_node->get_col() < WIDTH -1  && !( (curr_node + 2)->get_visited() ) ) {
        neighbors.push_back(curr_node + 2);
        has_neighbor = true;
    }

    if(has_neighbor) {
        std::srand( time(NULL) % seed );
        std::srand(rand());
        seed += 7;
        //seed = rand() % 10;
        //std::random_shuffle(neighbors.begin(), neighbors.end());
        //std::srand(seed);
        next = neighbors.at(rand() % neighbors.size());
        //next = neighbors.at(0);
        if(curr_node->get_row() == next->get_row()) {
            (curr_node - (curr_node->get_col() / 2 - next->get_col() / 2) )->set_visited(true);
            (curr_node - (curr_node->get_col() / 2 - next->get_col() / 2) )->set_status(DEFAULT);
        } else {
            (curr_node - (curr_node->get_row() / 2 - next->get_row() / 2) * WIDTH )->set_visited(true);
            (curr_node - (curr_node->get_row() / 2 - next->get_row() / 2) * WIDTH )->set_status(DEFAULT);
        }
        return next;
    }

    return curr_node;
}

void Maze::display_maze() {
    system("clear");
    std::cout << CLEAR;
    for(int k=0; k<=WIDTH; k++) std::cout << BG_RED << "__" << RESET;
    std::cout << '\n';
    for(int j=0; j<HEIGHT; j++) {
        for(int i=0; i<WIDTH; i++) {
            if( (start + j*WIDTH + i)->get_visited() ) std::cout << BG_GREEN << "  " << RESET;
            else std::cout << BG_WHITE << "  " << RESET;
        }
        std::cout << BG_RED << "||" << RESET;
        std::cout << '\n';
    }
}