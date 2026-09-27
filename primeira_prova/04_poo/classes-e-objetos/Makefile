CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
EXEC = programa

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)
