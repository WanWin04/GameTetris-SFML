g++ -c main.cpp Grid/Grid.cpp -I "D:\SFML\include"
g++ main.o Grid.o -o main.exe -L "D:\SFML\lib" -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
./main.exe