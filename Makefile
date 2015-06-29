
all: tree-test

tree-test: tree-test.cpp
	g++ ${shell root-config --cflags --libs} -o tree-test tree-test.cpp
