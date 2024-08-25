#include <iostream>
#include "maze.cpp"
#include "node.cpp"

using namespace std;

Node* getFirstNode(Maze maze) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            if (maze.matrix[i][j].isStart) {
                maze.matrix[i][j].hasBeenAddedToTree = true;
                return new Node(maze.matrix[i][j], maze);
            }
        }
    }

    return NULL;
}

void breadthFirstSearch(Node *startNode, Maze *maze) {
    startNode->info.hasBeenWalked = true;
    maze->matrix[startNode->info.coords.y][startNode->info.coords.x].hasBeenWalked = true;

    if (startNode->info.isEnd) {
        return;
    }
}

int main(void) {
    int input[MAX_ROWS][MAX_COLS] = {
        {1, 1, 0, 1, 1},
        {0, 0, 0, 1, 1},
        {0, 1, 0, 0, 0},
        {1, 1, 1, 0, 1},
        {0, 0, 0, 0, 1}
    };

    Maze maze = Maze(input);
    maze.print();
    Node startNode;

    int x, y;

    cout << "input x and y coodinates of start point" << endl;
    cin >> x >> y;
    maze.setStart(x, y);

    cout << "input x and y coodinates of end point" << endl;
    cin >> x >> y;
    maze.setEnd(x, y);

    startNode = *getFirstNode(maze);

    //cout << breadthFirstSearch(&startNode, &maze) << endl;
    breadthFirstSearch(&startNode, &maze);
    maze.print();
}
