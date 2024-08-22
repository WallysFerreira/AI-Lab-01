#include "mazepoint.cpp"
#include <iostream>

#define MAX_ROWS 5
#define MAX_COLS 5

using namespace std;

class Maze {

    public:
        MazePoint matrix[MAX_ROWS][MAX_COLS];

        Maze(int mat[MAX_ROWS][MAX_COLS]) {
            for (int i = 0; i < MAX_ROWS; i++) {
                for (int j = 0 ; j < MAX_COLS; j++) {
                    bool isWall = mat[i][j] == 1;
                    MazePoint newMazePoint = MazePoint(isWall, false, false);

                    matrix[i][j] = newMazePoint;
                }
            }
        }

        void print() {
            for (int i = 0; i < MAX_ROWS; i++) {
                for (int j = 0; j < MAX_COLS; j++) {
                    cout << matrix[i][j].toString();
                }

                cout << endl;
            }
        }
};