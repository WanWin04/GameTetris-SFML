g++ -c main.cpp Grid/Grid.cpp Colors/Colors.cpp Position/Position.cpp -I "D:\SFML\include"
g++ main.o Grid.o Colors.o Position.o -o main.exe -L "D:\SFML\lib" -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
./main.exe