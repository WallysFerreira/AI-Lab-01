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

        Node(MazePoint info);

        void addChild(Node child);

        void addSibling(Node sibling);

        void findChildren(Maze maze);

        void lookLeft(MazePoint matrix[MAX_ROWS][MAX_COLS]);

        void lookBelow(MazePoint matrix[MAX_ROWS][MAX_COLS]);

        void lookRight(MazePoint matrix[MAX_ROWS][MAX_COLS]);

        void lookUp(MazePoint matrix[MAX_ROWS][MAX_COLS]);
};

#endif