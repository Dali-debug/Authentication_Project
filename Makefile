CXX = g++
CXXFLAGS = -Wall -std=c++17
LDFLAGS = -lssl -lcrypto

SRC = main.cpp user.cpp file_handler.cpp hash.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = auth_app

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(OBJ) $(TARGET)
