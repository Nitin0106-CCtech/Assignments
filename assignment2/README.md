# Assignment 2 — Extend Assignment 1 to 3D (minimum changes)

## What changed vs. Assignment 1

| File | Change |
|---|---|
| `Point2D.h/.cpp` | Added `virtual getCoordinates()` and a `vector<double>` constructor. Everything else untouched. |
| `Point3D.h/.cpp` | **New.** Inherits from `Point2D`, adds only `z`. |
| `LineSegment` | Converted from a plain class to `LineSegment<PointT>` (template). The interpolation math is byte-for-byte the same as Assignment 1 — it just loops over `getCoordinates().size()` instead of hardcoding x/y. Since it's a template it's now header-only (`LineSegment.h`, no `.cpp`). |
| `main.cpp` | Runs the same segment logic twice: once with `LineSegment<Point2D>`, once with `LineSegment<Point3D>`. |

This is the "inheritance + templates" combo the prerequisites called for: **inheritance**
(`Point3D : public Point2D`) gets you the new data (z), and **templates**
(`LineSegment<PointT>`) let the one interpolation implementation serve both
dimensions without duplicating it.

## Structure
```
assignment2/
├── App/
│   └── main.cpp
├── Geometry/
│   ├── Point2D.h/.cpp
│   ├── Point3D.h/.cpp       # new
│   └── LineSegment.h        # now a template, header-only
├── Makefile
└── output2d.dat / output3d.dat   # generated after running
```

## Build & run
```bash
make
./build/assignment2
```
Produces `output2d.dat` (same as Assignment 1) and `output3d.dat` (x y z rows).

## Plot
```bash
gnuplot -e "plot 'output2d.dat' with linespoints; pause -1"
gnuplot -e "splot 'output3d.dat' with linespoints; pause -1"   # splot for 3D
```

## Push to git
Same as Assignment 1 — either push as a new commit in the same repo, or a
fresh private repo:
```bash
git add .
git commit -m "Assignment 2: extend line interpolation to 3D via templates + inheritance"
git push
```
