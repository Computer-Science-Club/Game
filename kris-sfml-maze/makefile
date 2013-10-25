CC=clang++
CFLAGS=-std=c++11 -g
IMPORTS=-lsfml-graphics -lsfml-window -lsfml-system

SRC=Game.cpp Render.cpp
EXE=Game-App

all: execute

clean:
	@echo deleting $(EXE)
	rm -rf $(EXE).o

build:
	@clear;clear
	@echo Compiling $(EXE)
	$(CC) $(CFLAGS) $(SRC) $(IMPORTS) -o $(EXE)

execute: build
	@echo Running $(EXE)
	./$(EXE)
