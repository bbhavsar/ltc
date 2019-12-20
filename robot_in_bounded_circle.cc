// https://leetcode.com/problems/robot-bounded-in-circle/
#include "common.hh"

enum Direction {
    North,
    West,
    South,
    East
};

Direction getNextDirection(Direction currDirection, char instruction) {
    static const unordered_map<Direction, vector<Direction>, hash<int>  > next_direction = {
        {North, {West, East} },
        {West,  {South, North} },
        {South, {East, West} },
        {East,  {North, South} }
     };

    switch (instruction) {
        case 'G':
            return currDirection;
        case 'L':
            return next_direction.at(currDirection)[0];
        case 'R':
            return next_direction.at(currDirection)[1];
        default:
            return currDirection;
    }
}

bool isRobotBounded(string instructions) {
    Direction currDirection = North;
    int posX = 0;
    int posY = 0;

    static const unordered_map<Direction, vector<int>, hash<int> > next_coord = {
        { North, {0, 1} },
        { West,  {-1, 0} },
        { East,  {1, 0}  },
        { South, {0, -1} }
    };

    for (int i = 0; i < 4; i++) {
        for (auto c : instructions) {
            if (c == 'G') {
                auto vec = next_coord.at(currDirection);
                posX += vec[0];
                posY += vec[1];
            } else {
                currDirection = getNextDirection(currDirection, c);
            }
        }
        if (posX == 0 && posY == 0) {
            return true;
        }
    }
    return false;
}

int main() {

    cout << isRobotBounded("GGLLGG") << endl;
    cout << isRobotBounded("GG") << endl;
    cout << isRobotBounded("GL") << endl;

    return 0;
}



