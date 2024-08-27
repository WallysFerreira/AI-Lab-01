#include "maze.hpp"
#include "mazepoint.cpp"
#include <math.h>
#include <iostream>

using namespace std;

Maze::Maze(int mat[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0 ; j < MAX_COLS; j++) {
            bool isWall = mat[i][j] == 1;
            Coordinates coords = Coordinates(j, i);
            MazePoint newMazePoint = MazePoint(coords, isWall, false, false);

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

int Maze::getManhattanDistance(Coordinates from, Coordinates to) {
    return abs(to.x - from.x) + abs(to.y - from.y);
}

int Maze::getDistance(Coordinates from, Coordinates to) {
    int b = pow((to.x - from.x), 2);
    int c = pow((to.y - from.y), 2);

    return sqrt(b + c);
}