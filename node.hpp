#ifndef _node_hpp_
#define _node_hpp_

#include "maze.hpp"
#include "mazepoint.hpp"

class Node {
    public:
        MazePoint info;
        Node *firstChild = NULL;
        Node *nextSibling = NULL;

        Node();

        Node(MazePoint info, Maze maze);

        void addChild(Node *child);

        void addSibling(Node *sibling);

        void findChildren(Maze *maze);

        void lookLeft(Maze *maze);

        void lookBelow(Maze *maze);

        void lookRight(Maze *maze);

        void lookUp(Maze *maze);
};

#endif