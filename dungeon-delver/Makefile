CC = g++
CFLAGS = -std=c++14 -Wall

SRC_DIR = .
BUILD_DIR = build
EXECUTABLE = build/dungeon-delver

SRCS := $(shell find $(SRC_DIR) -name '*.cpp')
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)/*.o

play:
	./build/dungeon-delver

run: $(EXECUTABLE) clean
	./$(EXECUTABLE)
