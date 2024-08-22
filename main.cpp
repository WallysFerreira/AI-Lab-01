#include <iostream>
#include "maze.cpp"

using namespace std;

int main(void) {
    int input[MAX_ROWS][MAX_COLS] = {
        {1, 1, 0, 1, 1},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 0, 1},
        {0, 0, 0, 0, 1}
    };

    Maze maze = Maze(input);
    maze.print();
}

