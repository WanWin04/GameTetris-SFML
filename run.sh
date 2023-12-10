g++ -c main.cpp Grid/Grid.cpp Colors/Colors.cpp Position/Position.cpp Blocks/Block.cpp Blocks/Blocks.cpp GameState/GameState.cpp -I "D:\SFML\include"
g++ main.o Grid.o Colors.o Position.o Block.o Blocks.o GameState.o -o main.exe -L "D:\SFML\lib" -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
./main.exe