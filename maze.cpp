#include "maze.hpp"
#include "mazepoint.cpp"
#include <iostream>

using namespace std;

Maze::Maze(int mat[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0 ; j < MAX_COLS; j++) {
            bool isWall = mat[i][j] == 1;
            MazePoint newMazePoint = MazePoint(isWall, false, false);

            matrix[i][j] = newMazePoint;
        }
    }
}

void Maze::print() {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            cout << matrix[i][j].toString();
        }

        cout << endl;
    }
}

void Maze::walk(int x, int y) {
    this->matrix[y][x].hasBeenWalked = true;
    print();
    cout << endl;
}

void Maze::setStart(int x, int y) {
    this->matrix[y][x].isStart = true;
    print();
    cout << endl;
}

void Maze::setEnd(int x, int y) {
    this->matrix[y][x].isEnd = true;
    print();
    cout << endl;
}