#!/bin/bash

INCLUDE_DIR="D:\SFML\include"
LIB_DIR="D:\SFML\lib"

EXECUTABLE="main.exe"

OBJECT_FILE="main.o Grid.o Colors.o Position.o Block.o TypeBlocks.o GameState.o Application.o Score.o Next.o UI.o GameOver.o UpdateScore.o Control.o Music.o Sound.o Animation.o Medal.o Time.o PlayAgain.o Level.o UpdateLevel.o"
CPP_FILE="main.cpp src/Grid/Grid.cpp src/Colors/Colors.cpp src/Position/Position.cpp src/Block/Block.cpp src/TypeBlocks/TypeBlocks.cpp src/GameState/GameState.cpp src/Application/Application.cpp src/Interface/Score/Score.cpp src/Interface/Level/Level.cpp src/Interface/UpdateLevel/UpdateLevel.cpp src/Interface/Medal/Medal.cpp src/Interface/PlayAgain/PlayAgain.cpp src/Interface/Time/Time.cpp src/Interface/Control/Control.cpp src/Interface/Next/Next.cpp src/Interface/UI/UI.cpp src/Interface/GameOver/GameOver.cpp src/Interface/UpdateScore/UpdateScore.cpp src/Music/Music.cpp src/Sound/Sound.cpp src/Animation/Animation.cpp"

g++ -c $CPP_FILE -I $INCLUDE_DIR
g++ $OBJECT_FILE -o $EXECUTABLE -L $LIB_DIR -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network

./$EXECUTABLE