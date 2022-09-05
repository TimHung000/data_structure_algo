#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>

#define COLUMN 8
#define ROW 8

std::string checkState(int king, int queen, int to)
{
    // king and queen cannot in the same place
    if(king == queen)
        return "Illegal state";

    // move both col and row or doesn't move are both illegal
    if(queen == to || (to - queen) % COLUMN != 0 && to / COLUMN != queen / COLUMN)
        return "Illegal move";

    // move across king
    // same row or same col
    if((king-queen) % COLUMN == 0 && (king-to) % COLUMN == 0 ||
            king / COLUMN == queen / COLUMN && king / COLUMN == to / COLUMN)
    {
        // queen move over king
        if(king <= std::max(queen, to) && king >= std::min(queen, to))
            return "Illegal move";
    }

    // queen can't move to the 4 sides of king
    int diff = std::max(king, to) - std::min(king, to);
    if(diff == COLUMN || king / COLUMN == to / COLUMN && diff == 1)
        return "Move not allowed";

    // king is in the corner and queen move to the place that king can't move
    if(king == 0 && to == king + COLUMN + 1
            || king == COLUMN - 1 && to == king + COLUMN - 1
            || king == COLUMN * (ROW - 1) && to == king - COLUMN + 1
            || king == COLUMN * ROW -1 && to == king - COLUMN - 1)
        return "Stop";

    return "Continue";
}


int main(int argc, char** argv)
{
    int king, queen, to;
//    std::string line;
//    std::vector<std::string> all;
//    while(std::getline(std::cin, line))
//    {
//        if(std::cin.eof())
//            break;
//        all.push_back(line);
//    }
//
//    for(auto it = all.begin(); it != all.end(); ++it)
//    {
//        std::stringstream tmp(*it);
//        tmp >> king >> queen >> to;
//        std::cout << checkState(king, queen, to) << "\n";
//    }
    while(std::cin >> king >> queen >> to)
    {
        std::cout << checkState(king, queen, to) << "\n";
    }
    return 0;
}
