#include "node.hpp"

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