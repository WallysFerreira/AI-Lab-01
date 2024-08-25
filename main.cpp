#include <iostream>
#include "maze.cpp"
#include "node.cpp"

using namespace std;

Node* getFirstNode(Maze maze) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            if (maze.matrix[i][j].isStart) {
                return new Node(maze.matrix[i][j]);
            }
        }
    }

    return NULL;
}

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
    Node startNode;

    int x, y;

    cout << "input x and y coodinates of start point" << endl;
    cin >> x >> y;
    maze.setStart(x, y);

    cout << "input x and y coodinates of end point" << endl;
    cin >> x >> y;
    maze.setEnd(x, y);

    startNode = *getFirstNode(maze);

    startNode.findChildren(maze);

    if (startNode.firstChild == NULL) {
        cout << "No children" << endl;
    } else if (startNode.firstChild->nextSibling != NULL) {
        cout << "Child has sibling" << endl;
    }

    if (startNode.nextSibling == NULL) {
        cout << "No siblings" << endl;
    }
}
