build:
	gcc -Wall -Wextra -std=c99 ./src/*.c -lSDL2 -lm -o raycast;
run: 
	./raycast
clean:
	rm raycast