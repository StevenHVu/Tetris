all: compile link

compile:
	g++ -IC:\SFML\include -c main.cpp -o main.o

link:
	g++ -LC:\SFML\lib .\main.o -o run -lmingw32 -lsfml-graphics -lsfml-window -lsfml-system -lsfml-main -mwindows

clean:
	rm -rf *.o main