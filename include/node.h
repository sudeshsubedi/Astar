#pragma once

class Node
{
public:
    Node(int row, int col): row(row), col(col) { visited = false; }
    Node(): row(0), col(0) { visited = false; }
    void set_position(int, int);
    void set_visited(bool);
    int get_row() { return row; }
    int get_col() { return col; }
    bool get_visited() { return visited; }
private:
    int row, col;
    bool visited;
};