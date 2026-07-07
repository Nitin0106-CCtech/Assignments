CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17 -MMD -MP
BUILD_DIR := build
TARGET := $(BUILD_DIR)/assignment5

SRCS := $(wildcard App/*.cpp) $(wildcard Geometry/*.cpp)
OBJS := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SRCS))
DEPS := $(OBJS:.o=.d)

.PHONY: all run clean

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

-include $(DEPS)
