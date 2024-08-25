#ifndef _node_hpp_
#define _node_hpp_

#include "mazepoint.hpp"

class Node {
    public:
        MazePoint info;
        Node *firstChild;
        Node *nextSibling;

        Node();

        Node(MazePoint info);

        void addChild(Node child);

        void addSibling(Node sibling);

        void findChildren();
};

#endif