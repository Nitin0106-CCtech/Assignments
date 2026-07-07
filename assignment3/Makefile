CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17 -MMD -MP
BUILD_DIR := build
TARGET := $(BUILD_DIR)/assignment3

# Auto-discover every .cpp under App/ and Geometry/ - add a new class file
# and it's picked up automatically, no need to edit this list by hand.
SRCS := $(wildcard App/*.cpp) $(wildcard Geometry/*.cpp)
OBJS := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SRCS))
DEPS := $(OBJS:.o=.d)

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

# -MMD -MP above generates a .d file per object listing which headers it
# depends on. Including them here means editing e.g. Shape.h correctly
# triggers a rebuild of Circle.cpp/Rectangle.cpp/Square.cpp without a full clean.
-include $(DEPS)
