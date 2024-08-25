#ifndef _mazepoint_hpp_
#define _mazepoint_hpp_

#include <string>
#include "coordinates.cpp"

using namespace std;

class MazePoint {
    public:
        bool isWall;
        bool isStart;
        bool isEnd;
        bool hasBeenWalked = false;
        bool hasBeenAddedToTree = false;
        Coordinates coords;
        
        MazePoint();

        MazePoint(Coordinates coords, bool isWall, bool isStart, bool isEnd);

        string toString();
};

#endif
