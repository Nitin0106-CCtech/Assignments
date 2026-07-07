CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17
BUILD_DIR := build
LIB_DIR := lib

GEOM_SRCS := $(wildcard Geometry/*.cpp)
STATIC_OBJS := $(patsubst Geometry/%.cpp,$(BUILD_DIR)/static-obj/%.o,$(GEOM_SRCS))
SHARED_OBJS := $(patsubst Geometry/%.cpp,$(BUILD_DIR)/shared-obj/%.o,$(GEOM_SRCS))

STATIC_LIB := $(LIB_DIR)/libshapes.a
SHARED_LIB := $(LIB_DIR)/libshapes.so

STATIC_APP := $(BUILD_DIR)/app_static
SHARED_APP := $(BUILD_DIR)/app_shared

.PHONY: all static shared run-static run-shared inspect clean

UNAME := $(shell uname)

all: $(STATIC_APP) $(SHARED_APP)

# ---------------------------------------------------------------------------
# STATIC LIBRARY: plain .o files archived together with `ar`. Whatever links
# against libshapes.a gets a COPY of this code baked directly into its binary
# at link time - no runtime dependency on libshapes at all afterwards.
# ---------------------------------------------------------------------------
static: $(STATIC_LIB)

$(STATIC_LIB): $(STATIC_OBJS)
	@mkdir -p $(LIB_DIR)
	ar rcs $@ $^

$(BUILD_DIR)/static-obj/%.o: Geometry/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# ---------------------------------------------------------------------------
# SHARED LIBRARY: compiled with -fPIC (position-independent code, required
# for shared libs) and linked with -shared into a .so. The app below does
# NOT copy this code in - it just records "I need libshapes.so" and the
# dynamic linker (ld.so) resolves and loads it at *runtime*.
# ---------------------------------------------------------------------------
shared: $(SHARED_LIB)

$(SHARED_LIB): $(SHARED_OBJS)
	@mkdir -p $(LIB_DIR)
	$(CXX) -shared -o $@ $^

$(BUILD_DIR)/shared-obj/%.o: Geometry/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -fPIC -c $< -o $@

# ---------------------------------------------------------------------------
# Two app binaries, same main.cpp, linked two different ways.
# ---------------------------------------------------------------------------
$(STATIC_APP): App/main.cpp $(STATIC_LIB)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) App/main.cpp $(STATIC_LIB) -o $@

# -Wl,-rpath,'$$ORIGIN/../lib' bakes a *relative* search path into the binary
# itself, so it finds lib/libshapes.so next to it without needing
# LD_LIBRARY_PATH set manually or the library installed system-wide.
$(SHARED_APP): App/main.cpp $(SHARED_LIB)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) App/main.cpp -L$(LIB_DIR) -lshapes -Wl,-rpath,'$$ORIGIN/../lib' -o $@

run-static: $(STATIC_APP)
	./$(STATIC_APP)

run-shared: $(SHARED_APP)
	./$(SHARED_APP)

# Shows the actual difference between the two link modes.
inspect: $(STATIC_APP) $(SHARED_APP)
	@echo "=== runtime link check ==="
	@if [ "$(UNAME)" = "Darwin" ]; then \
		echo "=== otool -L on app_shared (macOS) ==="; \
		otool -L $(SHARED_APP); \
		echo ""; \
		echo "=== otool -L on app_static (macOS) ==="; \
		otool -L $(STATIC_APP); \
	else \
		echo "=== ldd on app_shared (dynamically linked against libshapes.so) ==="; \
		ldd $(SHARED_APP); \
		echo ""; \
		echo "=== ldd on app_static (libshapes baked in; only libc/libstdc++ still dynamic) ==="; \
		ldd $(STATIC_APP); \
	fi
	@echo ""
	@echo "=== binary sizes (static app is bigger - it's carrying libshapes' code) ==="
	@du -h $(STATIC_APP) $(SHARED_APP)
	@echo ""
	@echo "=== exported symbols from shared lib ==="
	@if [ "$(UNAME)" = "Darwin" ]; then \
		nm -g $(SHARED_LIB) | c++filt | grep -i " T "; \
	else \
		nm -D $(SHARED_LIB) | grep -i " T " | c++filt; \
	fi

clean:
	rm -rf $(BUILD_DIR) $(LIB_DIR)
