CC = g++ -g -Wall -std=c++14
exe_file = run

$(exe_file): driver.o game.o
	$(CC) driver.o game.o -o $(exe_file)

driver.o: driver.cpp
	$(CC) -c driver.cpp

game.o: game.cpp
	$(CC) -c game.cpp

clean:
	rm -rf *.o $(exe_file)