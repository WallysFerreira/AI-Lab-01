#ifndef _maze_hpp_
#define _maze_hpp_

#include "constants.hpp"
#include "mazepoint.hpp"

class Maze {
    public:
        MazePoint matrix[MAX_ROWS][MAX_COLS];

        Maze(int mat[MAX_ROWS][MAX_COLS]);

        void print();
        void walk(int x, int y);
        void setStart(int x, int y);
        void setEnd(int x, int y);

};

#endif