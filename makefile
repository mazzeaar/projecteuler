CXX = g++
CXXFLAGS = -Iinclude -Wall -std=c++17

TARGET = main

${TARGET}: src/main.cpp 
	${CXX} ${CXXFLAGS} -o ${TARGET} src/main.cpp 

run: all
	./${TARGET}

clean:
	rm -f ${TARGET}
