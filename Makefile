CC = g++
CFLAGS = -Wall -Werror -Wextra -std=c++11
DIR = ../build/

all: 
	$(CC) $(CFLAGS) laba2_test.cpp Matrix.cpp -o $(DIR)Quest_1.exe
clean:
	rm -f *.o $(DIR)Quest_1
rebuild:
	clean all