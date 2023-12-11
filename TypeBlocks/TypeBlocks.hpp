#ifndef TYPEBLOCKS_HPP
#define TYPEBLOCKS_HPP

#include "../Block/Block.hpp"
#include "../Position/Position.hpp"

class LBlock : public Block {
public:
    LBlock();
    ~LBlock();
};

class JBlock : public Block {
public:
    JBlock();
    ~JBlock();
};

class IBlock : public Block {
public:
    IBlock();
    ~IBlock();
};

class OBlock : public Block {
public:
    OBlock();
    ~OBlock();
};

class SBlock : public Block {
public:
    SBlock();
    ~SBlock();
};

class TBlock : public Block {
public:
    TBlock();
    ~TBlock();
};

class ZBlock : public Block {
public:
    ZBlock();
    ~ZBlock();
};

#endif