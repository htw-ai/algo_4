CC=gcc
SOURCE=*.c
OPTIONS=-g -lm --std=c99 -Wall
DESTINATION=main.out


all: $(SOURCE)
	$(CC) $(SOURCE) -o $(DESTINATION) $(OPTIONS)

run:
	./$(DESTINATION)

clean:
	rm -f ./$(DESTINATION)