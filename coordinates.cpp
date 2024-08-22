class Coordinates {
    public:
        int x;
        int y;

        Coordinates(int x, int y) {
            this->x = x;
            this->y = y;
        }

        bool equals(Coordinates coords) {
            return this->x == coords.x && this->y == coords.y;
        }
};