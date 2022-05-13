#pragma once

#include "constants.h"

class Node
{
public:
    Node(int row, int col): row(row), col(col), g(10000), h(10000), f(20000), status(WALL) { visited = false; is_closed = false; is_wall = true; }
    Node(): row(0), col(0),  g(10000), h(10000), f(20000), status(WALL) { visited = false; is_closed = false; is_wall = true; }
    void set_position(int, int);
    void set_visited(bool);
    void set_status(Status stat) { status = stat; }
    void set_parent(Node* node) { parent = node; }
    void set_wall(bool wall) { is_wall = wall; }
    int get_row() { return row; }
    int get_col() { return col; }
    int get_f() const { return f; }
    int get_g() { return g; }
    int get_h() { return h; }
    bool get_wall() { return is_wall; }
    Node* get_parent() { return parent; }
    Status get_status() { return status; }
    bool is_close() { return is_closed; }
    bool get_visited() { return visited; }
    void calculate_cost(Node*, Node*);
private:
    int row, col, f, g, h;
    bool visited, is_closed, is_wall;
    Node* parent;
    Status status;
};

bool operator>(const Node&, const Node&);