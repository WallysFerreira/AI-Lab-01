#include <string>
using namespace std;

class MazePoint {
    public:
        bool isWall;
        bool isStart;
        bool isEnd;
        
        MazePoint() {
        }

        MazePoint(bool isWall, bool isStart, bool isEnd) {
            this->isWall = isWall;
            this->isStart = isStart;
            this->isEnd = isEnd;
        }

        string toString() {
            if (isWall) {
                return "##";
            } else if (isStart) {
                return "**";
            } else if (isEnd) {
                return "++";
            } else {
                return "  ";
            }
        }
};