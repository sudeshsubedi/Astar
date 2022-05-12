#include "node.h"

void Node::set_position(int y, int x) {
    row = y;
    col = x;
}

void Node::set_visited(bool is_visited) {
    visited = is_visited;
}