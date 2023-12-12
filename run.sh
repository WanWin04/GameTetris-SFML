#!/bin/bash

INCLUDE_DIR="D:\SFML\include"
LIB_DIR="D:\SFML\lib"

EXECUTABLE="main.exe"

OBJECT_FILE="main.o Grid.o Colors.o Position.o Block.o TypeBlocks.o GameState.o Game.o Score.o Next.o UI.o GameOver.o UpdateScore.o"
CPP_FILE="main.cpp src/Grid/Grid.cpp src/Colors/Colors.cpp src/Position/Position.cpp src/Block/Block.cpp src/TypeBlocks/TypeBlocks.cpp src/GameState/GameState.cpp src/Game/Game.cpp src/Interface/Score/Score.cpp src/Interface/Next/Next.cpp src/Interface/UI/UI.cpp src/Interface/GameOver/GameOver.cpp src/Interface/UpdateScore/UpdateScore.cpp"

g++ -c $CPP_FILE -I $INCLUDE_DIR
g++ $OBJECT_FILE -o $EXECUTABLE -L $LIB_DIR -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network

./$EXECUTABLE