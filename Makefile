UNAME_S = $(shell uname -s)

CC = clang
CXX = clang++
CXXFLAGS = -std=c++20 -g -Wall -Wextra -fsanitize=address,undefined
CXXFLAGS += -Ilib/glad/include 
LDFLAGS = lib/glad/src/glad.o -fsanitize=address,undefined
GLFW_CFLAGS := $(shell pkg-config --cflags glfw3)
GLFW_LIBS   := $(shell pkg-config --libs glfw3)

CXXFLAGS += $(GLFW_CFLAGS)
LDFLAGS += $(GLFW_LIBS)

ifeq ($(UNAME_S), Darwin)
	LDFLAGS += -framework OpenGL -framework IOKit -framework CoreVideo -framework Cocoa -framework QuartzCore -framework Metal
endif

ifeq ($(UNAME_S), Linux)
	LDFLAGS += -ldl -lpthread
endif

SRC = $(wildcard src/*.cpp) $(wildcard src/**/*.cpp)
OBJ  = $(patsubst src/%.cpp,$(BUILD)/%.o,$(SRC))
BIN = bin
BUILD = build

.PHONY: all clean

all: dirs libs game

libs:
	cd lib/glad && $(CC) -o src/glad.o -Iinclude -c src/glad.c

dirs:
	mkdir -p $(BIN) $(BUILD)

run: all
	$(BIN)/game

game: $(OBJ)
	$(CXX) -o $(BIN)/game -Iinclude $^ $(LDFLAGS)

$(BUILD)/%.o: src/%.cpp
	mkdir -p $(dir $@)
	$(CXX) -o $@ -c $< $(CXXFLAGS)

clean: 
	rm -rf $(BIN) $(BUILD)
