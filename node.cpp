#include <iostream>
#include "node.hpp"
#include "constants.hpp"

Node::Node() {
}

Node::Node(MazePoint info, Maze maze) {
    this->info = info;
    findChildren(&maze);
}

void Node::addChild(Node *child) {
    if (this->firstChild == NULL) {
        this->firstChild = child;
    } else {
        this->firstChild->addSibling(child);
    }
}

void Node::addSibling(Node *sibling) {
    if (this->nextSibling == NULL) {
        this->nextSibling = sibling;
    } else {
        this->nextSibling->addSibling(sibling);
    }
}

void addChildAt(Node *node, int x, int y, Maze *maze) {
    MazePoint foundPoint = maze->matrix[y][x];

    if (!foundPoint.isWall && !foundPoint.hasBeenAddedToTree) {
        maze->matrix[y][x].hasBeenAddedToTree = true;
        Node *newNode = new Node(maze->matrix[y][x], *maze);
        node->addChild(newNode);
    }
}

bool isInsideMatrix(int x, int y) {
    return x >= 0 && x < MAX_COLS && y >= 0 && y < MAX_ROWS;
}

void Node::lookLeft(Maze *maze) {
    int transformedX = this->info.coords.x - 1;
    int transformedY = this->info.coords.y;

    if (isInsideMatrix(transformedX, transformedY)) {
        addChildAt(this, transformedX, transformedY, maze);
    }
}

void Node::lookBelow(Maze *maze) {
    int transformedX = this->info.coords.x;
    int transformedY = this->info.coords.y + 1;

    if (isInsideMatrix(transformedX, transformedY)) {
        addChildAt(this, transformedX, transformedY, maze);
    }
}

void Node::lookRight(Maze *maze) {
    int transformedX = this->info.coords.x + 1;
    int transformedY = this->info.coords.y;

    if (isInsideMatrix(transformedX, transformedY)) {
        addChildAt(this, transformedX, transformedY, maze);
    }
}

void Node::lookUp(Maze *maze) {
    int transformedX = this->info.coords.x;
    int transformedY = this->info.coords.y - 1;

    if (isInsideMatrix(transformedX, transformedY)) {
        addChildAt(this, transformedX, transformedY, maze);
    }
}

void Node::findChildren(Maze *maze) {
    lookLeft(maze);
    lookBelow(maze);
    lookRight(maze);
    lookUp(maze);
}