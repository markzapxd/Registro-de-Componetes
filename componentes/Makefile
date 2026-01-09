CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I libs

SRC_DIR = src
LIBS_DIR = libs

MAIN = $(SRC_DIR)/main.cpp

LIBS_SRCS = $(wildcard $(LIBS_DIR)/*.cpp) \
            $(wildcard $(LIBS_DIR)/*/*.cpp)

SRCS = $(MAIN) $(LIBS_SRCS)

TARGET = componentes

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

rebuild: clean all

.PHONY: all run clean rebuild
