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

Node* getEndNode(Maze maze) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            if (maze.matrix[i][j].isEnd) {
                return new Node(maze.matrix[i][j], maze);
            }
        }
    }

    return NULL;
}

int countWalked(Maze maze) {
    int count = 0;

    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            if (maze.matrix[i][j].hasBeenWalked) {
                count++;
            }
        }
    }

    return count - 1;
}

void breadthFirstSearch(queue<Node *> queue, Maze *maze) {
    Node *currentNode = queue.front();
    queue.pop();
    currentNode->info.hasBeenWalked = true;
    maze->matrix[currentNode->info.coords.y][currentNode->info.coords.x].hasBeenWalked = true;

    if (currentNode->info.isEnd) {
        return;
    }

    if (currentNode->nextSibling != NULL) {
        queue.push(currentNode->nextSibling);
    } 

    if (currentNode->firstChild != NULL) {
        queue.push(currentNode->firstChild);
    }

    if (!queue.empty()) {
        breadthFirstSearch(queue, maze);
    }
}

void depthFirstSearch(queue<Node *> childrenQueue, queue <Node *> siblingQueue, Maze *maze) {
    Node *currentNode;

    if (!childrenQueue.empty()) {
        currentNode = childrenQueue.front();
        childrenQueue.pop();
    } else {
        currentNode = siblingQueue.front();
        siblingQueue.pop();
    }

    currentNode->info.hasBeenAddedToTree = true;
    maze->matrix[currentNode->info.coords.y][currentNode->info.coords.x].hasBeenWalked = true;

    if (currentNode->info.isEnd) {
        return;
    }

    if (currentNode->firstChild != NULL) {
        childrenQueue.push(currentNode->firstChild);
    }

    if (currentNode->nextSibling != NULL) {
        siblingQueue.push(currentNode->nextSibling);
    }

    if (!childrenQueue.empty() || !siblingQueue.empty()) {
        depthFirstSearch(childrenQueue, siblingQueue, maze);
    }
}

void greedyFirstSearch(queue<Node *> prioQueue, queue<Node *> queue, Maze *maze, Node *endNode) {
    Node *currentNode;

    if (!prioQueue.empty()) {
        currentNode = prioQueue.front();
        prioQueue.pop();
    } else {
        currentNode = queue.front();
        queue.pop();
    }

    currentNode->info.hasBeenAddedToTree = true;
    maze->matrix[currentNode->info.coords.y][currentNode->info.coords.x].hasBeenWalked = true;

    if (currentNode->info.isEnd) {
        return;
    }

    if (currentNode->firstChild != NULL) {
        if (currentNode->firstChild->nextSibling != NULL) {
            int distanceFromChildToEnd = maze->getManhattanDistance(currentNode->firstChild->info.coords, endNode->info.coords);
            int distanceFromChildSiblingToEnd = maze->getManhattanDistance(currentNode->firstChild->nextSibling->info.coords, endNode->info.coords);

            if (distanceFromChildToEnd <= distanceFromChildSiblingToEnd) {
                prioQueue.push(currentNode->firstChild);
                queue.push(currentNode->nextSibling);
            }  else {
                prioQueue.push(currentNode->firstChild->nextSibling);
                queue.push(currentNode->firstChild);
            }
        } else {
            prioQueue.push(currentNode->firstChild);
        }
    }

    if (currentNode->nextSibling != NULL) {
        queue.push(currentNode->nextSibling);
    }

    if (!prioQueue.empty() || !queue.empty()) {
        greedyFirstSearch(prioQueue, queue, maze, endNode);
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

    int x, y;

    cout << "input x and y coodinates of start point" << endl;
    cin >> x >> y;
    maze.setStart(x, y);

    cout << "input x and y coodinates of end point" << endl;
    cin >> x >> y;
    maze.setEnd(x, y);

    Node startNode = *getFirstNode(maze);
    Node endNode = *getEndNode(maze);

    cout << "Choose your search algorithm\n1 - Breadth-First (Default)\n2- Depth-First\n3 - Greedy-First\n4 - A*" << endl;
    int choice = 1;
    cin >> choice;

    queue<Node *> mainQueue;
    queue<Node *> secondaryQueue;

    switch (choice) {
        case 1:
            mainQueue.push(&startNode);
            breadthFirstSearch(mainQueue, &maze);
            maze.print();
            break;
        case 2:
            mainQueue.push(&startNode);
            depthFirstSearch(mainQueue, secondaryQueue, &maze);
            maze.print();
            break;
        case 3:
            mainQueue.push(&startNode);
            greedyFirstSearch(mainQueue, secondaryQueue, &maze, &endNode);
            maze.print();
            break;
    }

    cout << "Took " << countWalked(maze) << " steps" << endl;
}
