#include "maze.hpp"
#include "node.cpp"

class Tree {
    public:
        Node startNode;

        Tree(MazePoint maze[MAX_ROWS][MAX_COLS]) {
            vector<Coordinates> emptyVector;

            for (int i = 0; i < MAX_ROWS; i++) {
                for (int j = 0; j < MAX_COLS; j++) {
                    if (maze[i][j].isStart) {
                        startNode = Node(j, i, maze, emptyVector);
                        return;
                    }
                }
            }
        }
};