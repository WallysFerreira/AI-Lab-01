#ifndef _mazepoint_hpp_
#define _mazepoint_hpp_

#include <string>
using namespace std;

class MazePoint {
    public:
        bool isWall;
        bool isStart;
        bool isEnd;
        bool hasBeenWalked = false;
        
        MazePoint();

        MazePoint(bool isWall, bool isStart, bool isEnd);

        string toString();
};

#endif
