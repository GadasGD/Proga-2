all: main run clear
main:
	cc -Wall -o main main.c
run:
	./main
clear:
	rm main

