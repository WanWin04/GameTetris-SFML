g++ -c main.cpp -I "D:\SFML\include"
g++ main.o -o main.exe -L "D:\SFML\lib" -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
./main.exe