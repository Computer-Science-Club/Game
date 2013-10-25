#!/bin/bash

echo "Testing Game-app"

clang++ -std=c++11 Game.cpp Render.cpp -g -lsfml-graphics -lsfml-window -lsfml-system -o Game-app

echo "Compiled objects"

./Game-app
