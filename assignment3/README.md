# Assignment 3 — Multifile Compilation with a Makefile (Classes, Objects, Inheritance)

## The point of this assignment
Not just "does it compile" — the Makefile itself needs to correctly handle
multiple source files, and correctly rebuild only what's needed when a
header changes.

## Class hierarchy (the "classes, objects, inheritance" part)
```
Shape (abstract base)
├── Circle
└── Rectangle
    └── Square   (multi-level inheritance)
```
- `Shape` declares pure virtual `area()`, `perimeter()`, `name()`, plus a
  **non-virtual** `printSummary()` that every derived class gets for free.
- `Circle` and `Rectangle` each live in their own `.h`/`.cpp` pair.
- `Square` inherits from `Rectangle` (not `Shape` directly) — it just forces
  width == height in its constructor and reuses `Rectangle`'s `area()`/`perimeter()`
  unchanged, overriding only `name()`.
- `main.cpp` builds a `vector<unique_ptr<Shape>>` holding all three types and
  calls `printSummary()` on each — this is where runtime polymorphism (virtual
  dispatch) actually gets exercised.

## The Makefile (the "use makefile" part)
```makefile
SRCS := $(wildcard App/*.cpp) $(wildcard Geometry/*.cpp)
OBJS := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SRCS))
DEPS := $(OBJS:.o=.d)
...
CXXFLAGS := -Wall -Wextra -std=c++17 -MMD -MP
...
-include $(DEPS)
```
Two things worth understanding, not just copying:

1. **`$(wildcard ...)`** auto-discovers every `.cpp` under `App/` and
   `Geometry/`. Add a new class file and it's picked up automatically —
   you never have to edit the source list by hand.
2. **`-MMD -MP`** tells g++ to emit a `.d` file alongside every `.o`, listing
   exactly which headers that object depends on. `-include $(DEPS)` pulls
   those into the Makefile, so editing `Shape.h` correctly triggers a rebuild
   of `Shape.cpp`, `Circle.cpp`, `Rectangle.cpp`, `Square.cpp`, and `main.cpp`
   — without needing `make clean` first. **This was verified**: touching
   `Shape.h` alone (no `.cpp` edited) triggered a rebuild of all five object
   files, confirmed by running it.

## Build & run
```bash
make          # builds build/assignment3
make run      # builds (if needed) and runs it
make clean    # wipes build/
```

Expected output:
```
Shape hierarchy demo (Makefile-driven multifile build)
--------------------------------------------------------
Circle -> area = 78.5398, perimeter = 31.4159
Rectangle -> area = 24, perimeter = 20
Square -> area = 9, perimeter = 12
```

## Push to git
```bash
git add .
git commit -m "Assignment 3: multifile Makefile build with Shape/Circle/Rectangle/Square inheritance"
git push
```
