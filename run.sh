#!/bin/bash

INCLUDE_DIR="D:\SFML\include"
LIB_DIR="D:\SFML\lib"

EXECUTABLE="main.exe"

g++ -c main.cpp Grid/Grid.cpp Colors/Colors.cpp Position/Position.cpp Block/Block.cpp TypeBlocks/TypeBlocks.cpp GameState/GameState.cpp -I $INCLUDE_DIR
g++ main.o Grid.o Colors.o Position.o Block.o TypeBlocks.o GameState.o -o $EXECUTABLE -L $LIB_DIR -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network

./$EXECUTABLE