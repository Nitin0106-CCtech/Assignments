# Assignment 1 — 2D Line Segment Interpolation

## Structure
```
assignment1/
├── App/
│   └── main.cpp          # entry point, CLI args, writes output.dat
├── Geometry/
│   ├── Point2D.h/.cpp     # simple 2D point
│   └── LineSegment.h/.cpp # holds start/end, does the interpolation + file write
├── Makefile
└── output.dat             # generated after running
```

## Build & run (WSL)
```bash
make              # builds build/assignment1
./build/assignment1              # uses default points (0,0) -> (10,5), 8 inner points
./build/assignment1 0 0 10 5 8   # or pass x1 y1 x2 y2 numInnerPoints explicitly
```

This writes `output.dat` as plain space-separated `x y` rows — one row per point,
including both endpoints.

## Plot with GNU Plot
```bash
gnuplot -e "plot 'output.dat' with linespoints; pause -1"
```
Or open the gnuplot prompt and type interactively:
```
gnuplot> plot 'output.dat' with linespoints
```

## Push to a private GitHub repo
```bash
cd assignment1
git init
git add .
git commit -m "Assignment 1: 2D line segment interpolation"
```
Then on GitHub: create a **new private repo** (no README/gitignore, so it's empty),
copy the URL it gives you, and:
```bash
git remote add origin <your-private-repo-url>
git branch -M main
git push -u origin main
```

## Notes on the approach
- `LineSegment::interpolate(n)` returns `n + 2` points total (start + n interior + end),
  using `t = i / (n+1)` linear interpolation — so the endpoints land exactly on the
  given coordinates rather than being approximated.
- Header/source split per class, matching the "Classes with header files separate"
  requirement.
- `App` and `Geometry` are separate folders/concerns per the prescribed project structure.
