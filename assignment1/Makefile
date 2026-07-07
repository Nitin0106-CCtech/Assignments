CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17
BUILD_DIR := build
TARGET := $(BUILD_DIR)/assignment1

SRCS := App/main.cpp Geometry/Point2D.cpp Geometry/LineSegment.cpp
OBJS := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SRCS))

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: all
	./$(TARGET)

clean:
	rm -rf $(BUILD_DIR)
