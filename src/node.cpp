#include "../include/node.h"

void Node::set_position(int y, int x) {
    row = y;
    col = x;
}

void Node::set_visited(bool is_visited) {
    visited = is_visited;
}

void Node::calculate_cost(Node* parent, Node* end) {
    if(status == START) g = 0;
    else g = parent->get_g() + 1;
    int hy = (end->get_row() - row);
    int hx = (end->get_col() - col);
    h = hy*hy + hx*hx;
    f = g+f;
}


bool operator<(const Node& n1, const Node& n2) {
    return n2.get_f() < n1.get_f();
}