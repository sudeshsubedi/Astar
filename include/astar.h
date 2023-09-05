#pragma once

#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <vector>
#include "node.h"

class Astar
{
public:
    Astar() {}
    void find_path(Node*, Node*, bool);
    std::vector<Node*> get_path() { return path; }
    int print(Node*, std::string);
private:
    std::vector<Node*> open_list;
    std::vector<Node*> neighbors;
    std::vector<Node*> path;
    Node* start;
    Node* end;
    Node* current;
    void calculate_neighbors();
    int lowest_f();
    void display(Node*);
};