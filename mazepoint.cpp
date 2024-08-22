#include <string>
using namespace std;

class MazePoint {
    public:
        bool isWall;
        bool isStart;
        bool isEnd;
        bool hasBeenWalked = false;
        
        MazePoint() {
        }

        MazePoint(bool isWall, bool isStart, bool isEnd) {
            this->isWall = isWall;
            this->isStart = isStart;
            this->isEnd = isEnd;
        }

        string toString() {
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
};