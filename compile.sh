#!/bin/bash
LIBS="-lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lsfml-network"
PACKAGES="src/*.cpp"
g++ -o out $PACKAGES $LIBS
