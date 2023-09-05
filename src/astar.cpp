#include "astar.h"

void Astar::find_path(Node* s, Node* e, bool show_process) {
    start = s;
    end = e;
    end->set_status(END);
    start->set_status(START);
    open_list.push_back(start);
    start->calculate_cost(start, end);
    while(open_list.size() > 0) {
        if(show_process) {
            display(start);
        }
        current = open_list[lowest_f()];
        open_list.erase(open_list.begin() + lowest_f());
        if(current->get_status() != START && current->get_status() != END) {
            current->set_status(CLOSED);
        }
        if(current == end) {
            Node* temp = current->get_parent();
            while(temp != start) {
                path.push_back(temp);
                temp->set_status(PATH);
                if(show_process) {
                    display(start);
                }
                if(temp == start) break;
                temp = temp->get_parent();
            }
            break;
        }
        calculate_neighbors();
        for(int i=0; i<neighbors.size(); i++) {
            if(neighbors.at(i)->get_status() == CLOSED) continue;
            if(neighbors[i]->get_status() == WALL) continue;
            bool is_in_open = false;
            for(auto& elem: open_list) {
                if(elem->get_col() == neighbors[i]->get_col() && elem->get_row() == neighbors[i]->get_row()) {
                    is_in_open = true;
                    break;
                }
            }
            if(is_in_open) {
                int prev_cost = neighbors[i]->get_f();
                neighbors[i]->calculate_cost(current, end);
                if(prev_cost > neighbors[i]->get_f()) {
                    neighbors[i]->set_parent(current);
                } else {
                    neighbors[i]->calculate_cost(neighbors[i]->get_parent(), end);
                }
            } else {
                neighbors[i]->calculate_cost(current, end);
                neighbors[i]->set_parent(current);
                open_list.push_back(neighbors[i]);
                if(neighbors[i]->get_status() != START && neighbors[i]->get_status() != END) {
                    neighbors[i]->set_status(OPEN);
                }
            }
        }
    }
}

void Astar::calculate_neighbors() {
    neighbors.clear();
    if(current->get_row() > 0) {
        Node* up = start + current->get_col() + (current->get_row() - 1) * WIDTH;
        neighbors.push_back(up);
    }

    if(current->get_col() > 0) {
        Node* left = start + current->get_row() * WIDTH + current->get_col() - 1;
        neighbors.push_back(left);
    }

    if(current->get_col() < WIDTH - 1) {
        Node* right = start + current->get_row() * WIDTH + current->get_col() + 1;
        neighbors.push_back(right);
    }

    if(current->get_row() < HEIGHT - 1) {
        Node* down = start + current->get_col() + (current->get_row() + 1) * WIDTH;
        neighbors.push_back(down);
    }
}

int Astar::lowest_f() {
    int lowest = 0;
    int lowest_f = 100000;
    if(open_list.size() > 1) {
        for(int i=1; i<open_list.size(); ++i) {
            if(open_list[i]->get_f() < lowest_f) {
                lowest = i;
                lowest_f = open_list[i]->get_f();
            }
        }
    }
    return lowest;
}

void Astar::display(Node* start) {
    system("clear");
    std::cout << CLEAR;
    for(int k=0; k<=WIDTH; k++) std::cout << BG_RED << "__" << RESET;
    std::cout << '\n';
    for(int j=0; j<HEIGHT; j++) {
        for(int i=0; i<WIDTH; i++) {
            Status stat = (start + j*WIDTH + i)->get_status();
            switch (stat)
            {
            case WALL:
                std::cout << BG_BLACK << "  " << RESET;
                break;
            case DEFAULT:
                std::cout << BG_GREEN << "  " << RESET;
                break;
            case START:
                std::cout << BG_YELLOW << "  " << RESET;
                break;
            case END:
                std::cout << BG_MAGENTA << "  " << RESET;
                break;
            case PATH:                                                                                                                                              
                std::cout << BG_PATH << "  " << RESET;
                break;
            case CLOSED:
                std::cout << BG_CLOSED << "  " << RESET;
                break;
            default:
                std::cout << BG_GREEN << "  " << RESET;
                break;
            }
        }
        std::cout << BG_RED << "||" << RESET;
        std::cout << '\n';
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(5));
}

int Astar::print(Node* start, std::string filename) {
    std::ofstream outf(filename);
    if (!outf.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return 1;
    }
    outf << CLEAR;
    for(int k=0; k<=WIDTH; k++) outf << BG_RED << "__" << RESET;
    outf << '\n';
    for(int j=0; j<HEIGHT; j++) {
        for(int i=0; i<WIDTH; i++) {
            Status stat = (start + j*WIDTH + i)->get_status();
            switch (stat)
            {
            case WALL:
                outf << BG_BLACK << "  " << RESET;
                break;
            case DEFAULT:
                outf << BG_GREEN << "  " << RESET;
                break;
            case START:
                outf << BG_YELLOW << "  " << RESET;
                break;
            case END:
                outf << BG_MAGENTA << "  " << RESET;
                break;
            case PATH:                                                                                                                                              
                outf << BG_PATH << "  " << RESET;
                break;
            case CLOSED:
                outf << BG_CLOSED << "  " << RESET;
                break;
            default:
                outf << BG_GREEN << "  " << RESET;
                break;
            }
        }
        outf << BG_RED << "||" << RESET;
        outf << '\n';
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(5));
}