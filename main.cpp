#include <iostream>
#include "maze.cpp"
#include "node.cpp"
#include <queue>

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

void breadthFirstSearch(Maze *maze, queue<Node *> queue) {
    Node *currentNode = queue.front();
    queue.pop();
    currentNode->info.hasBeenWalked = true;
    maze->matrix[currentNode->info.coords.y][currentNode->info.coords.x].hasBeenWalked = true;

    cout << "Analyzing: " << currentNode->info.coords.x << ", " << currentNode->info.coords.y << endl;

    if (currentNode->info.isEnd) {
        cout << currentNode->info.coords.x << ", " << currentNode->info.coords.y << "is the end" << endl;
        return;
    }

    if (currentNode->nextSibling != NULL) {
        queue.push(currentNode->nextSibling);
    } 

    if (currentNode->firstChild != NULL) {
        queue.push(currentNode->firstChild);
    }

    if (!queue.empty()) {
        breadthFirstSearch(maze, queue);
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
    queue<Node *> queue;

    int x, y;

    cout << "input x and y coodinates of start point" << endl;
    cin >> x >> y;
    maze.setStart(x, y);

    cout << "input x and y coodinates of end point" << endl;
    cin >> x >> y;
    maze.setEnd(x, y);

    startNode = *getFirstNode(maze);
    queue.push(&startNode);

    //cout << breadthFirstSearch(&startNode, &maze) << endl;
    breadthFirstSearch(&maze, queue);
    maze.print();
}
