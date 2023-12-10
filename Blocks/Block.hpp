#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <vector>
#include <map>

#include "../Position/Position.hpp"

class Block {
public:
    Block();

    int ID;
    std::map<int, std::vector<Position>> cells;

private:
    int cellSize;
    int rotationState;
};

#endif