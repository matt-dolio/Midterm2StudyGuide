CXX=g++
CXXFLAGS=-std=c++17 -g

BINARIES=main

all: $(BINARIES)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $^

main: main.o bst.o
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(BINARIES) *.o
