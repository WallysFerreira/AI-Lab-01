#include <iostream>
#include "node.hpp"
#include "constants.hpp"

Node::Node() {
}

Node::Node(MazePoint info) {
    this->info = info;
}

void Node::addChild(Node child) {
    if (this->firstChild == NULL) {
        this->firstChild = &child;
    } else {
        this->nextSibling->addSibling(child);
    }
}

void Node::addSibling(Node sibling) {
    if (this->nextSibling == NULL) {
        this->nextSibling = &sibling;
    } else {
        this->nextSibling->addSibling(sibling);
    }
}

void addChildAt(Node *node, int x, int y, MazePoint matrix[MAX_ROWS][MAX_COLS]) {
    MazePoint foundPoint = matrix[y][x];

    if (!foundPoint.isWall && !foundPoint.hasBeenWalked) {
        node->addChild(Node(foundPoint));
    }
}

bool isInsideMatrix(int x, int y) {
    return x >= 0 && x < MAX_COLS && y >= 0 && y < MAX_ROWS;
}

void Node::lookLeft(MazePoint matrix[MAX_ROWS][MAX_COLS]) {
    int transformedX = this->info.coords.x - 1;
    int transformedY = this->info.coords.y;

    if (isInsideMatrix(transformedX, transformedY)) {
        addChildAt(this, transformedX, transformedY, matrix);
    }
}

void Node::lookBelow(MazePoint matrix[MAX_ROWS][MAX_COLS]) {
    int transformedX = this->info.coords.x;
    int transformedY = this->info.coords.y - 1;

    if (isInsideMatrix(transformedX, transformedY)) {
        addChildAt(this, transformedX, transformedY, matrix);
    }
}

void Node::lookRight(MazePoint matrix[MAX_ROWS][MAX_COLS]) {
    int transformedX = this->info.coords.x + 1;
    int transformedY = this->info.coords.y;

    if (isInsideMatrix(transformedX, transformedY)) {
        addChildAt(this, transformedX, transformedY, matrix);
    }
}

void Node::lookUp(MazePoint matrix[MAX_ROWS][MAX_COLS]) {
    int transformedX = this->info.coords.x;
    int transformedY = this->info.coords.y + 1;

    if (isInsideMatrix(transformedX, transformedY)) {
        addChildAt(this, transformedX, transformedY, matrix);
    }
}

void Node::findChildren(Maze maze) {
    lookLeft(maze.matrix);
    lookBelow(maze.matrix);
    lookRight(maze.matrix);
    lookUp(maze.matrix);
}