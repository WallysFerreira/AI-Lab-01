#include <vector>
#include "maze.hpp"
#include "coordinates.cpp"

using namespace std;

class Node {
    public:
        int x;
        int y;
        vector<Node> nextNodes;
        vector<Coordinates> ignoreList;

        Node() {
        }

        Node(int x, int y, MazePoint maze[MAX_ROWS][MAX_COLS], vector<Coordinates> ignoreList) {
            this->x = x;
            this->y = y;

            ignoreList.push_back(Coordinates(x, y));
            this->ignoreList = ignoreList;
            getPossibleChildren(maze);
        }

        void getPossibleChildren(MazePoint maze[MAX_ROWS][MAX_COLS]) {
            getNodeToTheLeft(maze);
            getNodeBelow(maze);
            getNodeToTheRight(maze);
            getNodeAbove(maze);
        }

        void getNodeToTheLeft(MazePoint maze[MAX_ROWS][MAX_COLS]) {
            int transformedX = this->x - 1;
            bool shouldIgnore = false;
            Coordinates nextCoords = Coordinates(transformedX, this->y);

            for (int i = 0; i < ignoreList.size(); i++) {
                if (ignoreList.at(i).equals(nextCoords)) {
                    shouldIgnore = true;
                    return;
                }
            }

            if (transformedX >= 0 && !shouldIgnore) {
                if (!maze[this->y][transformedX].isWall) {
                    addNode(Node(transformedX, this->y, maze, this->ignoreList));
                }
            }
        }

        void getNodeBelow(MazePoint maze[MAX_ROWS][MAX_COLS]) {
            int transformedY = this->y + 1;
            bool shouldIgnore = false;
            Coordinates nextCoords = Coordinates(this->x, transformedY);

            for (int i = 0; i < ignoreList.size(); i++) {
                if (ignoreList.at(i).equals(nextCoords)) {
                    shouldIgnore = true;
                    return;
                }
            }

            if (transformedY < MAX_ROWS && !shouldIgnore) {
                if (!maze[transformedY][this->x].isWall) {
                    addNode(Node(this->x, transformedY, maze, this->ignoreList));
                }
            }
        }

        void getNodeToTheRight(MazePoint maze[MAX_ROWS][MAX_COLS]) {
            int transformedX = this->x + 1;
            bool shouldIgnore = false;
            Coordinates nextCoords = Coordinates(transformedX, this->y);

            for (int i = 0; i < ignoreList.size(); i++) {
                if (ignoreList.at(i).equals(nextCoords)) {
                    shouldIgnore = true;
                    return;
                }
            }

            if (transformedX < MAX_COLS && !shouldIgnore) {
                if (!maze[this->y][transformedX].isWall) {
                    addNode(Node(transformedX, this->y, maze, this->ignoreList));
                }
            }
        }

        void getNodeAbove(MazePoint maze[MAX_ROWS][MAX_COLS]) {
            int transformedY = this->y - 1;
            bool shouldIgnore = false;
            Coordinates nextCoords = Coordinates(this->x, transformedY);

            for (int i = 0; i < ignoreList.size(); i++) {
                if (ignoreList.at(i).equals(nextCoords)) {
                    shouldIgnore = true;
                    return;
                }
            }

            if (transformedY >= 0 && !shouldIgnore) {
                if (!maze[transformedY][this->x].isWall) {
                    addNode(Node(this->x, transformedY, maze, this->ignoreList));
                }
            }
        }

        void addNode(Node node) {
            nextNodes.push_back(node);
        }
};