EXE := main

LIB := -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

SRC := ${wildcard *.cpp}

OBJ := ${SRC:%.cpp=%.o}

CXX := g++

FLG := -std=c++17

all: ${OBJ}
	${CXX} ${OBJ} ${LIB} -o ${EXE} 
	
%.o: %.cpp
	${CXX} -c $< ${FLG}

clean:
	rm ${OBJ} ${EXE}

.PHONY: all clean

