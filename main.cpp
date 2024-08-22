#include <iostream>
#include "maze.cpp"
#include "tree.cpp"

using namespace std;

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

    int x, y;

    cout << "input x and y coodinates of start point" << endl;
    cin >> x >> y;
    maze.setStart(x, y);

    cout << "input x and y coodinates of end point" << endl;
    cin >> x >> y;
    maze.setEnd(x, y);

    Tree tree = Tree(maze.matrix);
    cout << tree.startNode.nextNodes.size() << endl << endl;
    for (int i = 0; i < tree.startNode.nextNodes.size(); i++) {
        cout << tree.startNode.nextNodes.at(i).x << ", " << tree.startNode.nextNodes.at(i).y << endl;
    }

    for (int i = 0; i < tree.startNode.nextNodes.at(0).nextNodes.size(); i++) {
        cout << tree.startNode.nextNodes.at(0).nextNodes.at(i).x << ", " << tree.startNode.nextNodes.at(0).nextNodes.at(i).y << endl;
    }
}

