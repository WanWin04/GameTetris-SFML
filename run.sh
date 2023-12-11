#!/bin/bash

INCLUDE_DIR="D:\SFML\include"
LIB_DIR="D:\SFML\lib"

EXECUTABLE="main.exe"

OBJECT_FILE="main.o Grid.o Colors.o Position.o Block.o TypeBlocks.o GameState.o Game.o Score.o Next.o UI.o GameOver.o"
CPP_FILE="main.cpp Grid/Grid.cpp Colors/Colors.cpp Position/Position.cpp Block/Block.cpp TypeBlocks/TypeBlocks.cpp GameState/GameState.cpp Game/Game.cpp Interface/Score/Score.cpp Interface/Next/Next.cpp Interface/UI/UI.cpp Interface/GameOver/GameOver.cpp"

g++ -c $CPP_FILE -I $INCLUDE_DIR
g++ $OBJECT_FILE -o $EXECUTABLE -L $LIB_DIR -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network

./$EXECUTABLE