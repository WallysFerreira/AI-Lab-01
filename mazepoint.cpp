#include "mazepoint.hpp"
#include <string>
using namespace std;

MazePoint::MazePoint() {
}

MazePoint::MazePoint(Coordinates coords, bool isWall, bool isStart, bool isEnd) {
    this->isWall = isWall;
    this->isStart = isStart;
    this->isEnd = isEnd;
    this->coords = coords;
}

string MazePoint::toString() {
    if (isWall) {
        return "\u25A0\u25A0";
    } else if (isStart) {
        return "**";
    } else if (isEnd) {
        return "++";
    } else if (hasBeenWalked) {
        return "\033[22;33m\u25A0\u25A0\033[0m";
    } else {
        return "  ";
    }
}