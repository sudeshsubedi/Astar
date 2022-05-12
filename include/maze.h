#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include "node.h"
#include "constants.h"


class Maze
{
public:
    Maze(Node* start): start(start) {}
    void generate_maze(int);
    Node* get_neighbor(Node*);
    void display_maze();
private:
    Node *start, *current, *next;
    bool has_neighbor;
    int seed;
    std::vector<Node*> visited;
};