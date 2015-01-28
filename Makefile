CC=gcc
SOURCE=*.c
OPTIONS=-g -lm --std=c99 -Wall
DESTINATION=main


all: $(SOURCE)
	$(CC) $(SOURCE) -o $(DESTINATION) $(OPTIONS)

run:
	./$(DESTINATION)




