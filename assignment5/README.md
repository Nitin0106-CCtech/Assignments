# Assignment 5 — Full Shape Library (2D/3D, Curves, Polygons, Solids)

## What's in it

| Class | New or reused | Demonstrates |
|---|---|---|
| `Point2D` / `Point3D` | Reused from Assignment 2 | Inheritance (`Point3D : public Point2D`) |
| `LineSegment<PointT>` | Reused from Assignment 2 | Templates (works for 2D and 3D) |
| `BezierCurve<PointT>` | **New** | Templates + de Casteljau's algorithm |
| `Polygon2D` | **New** | Encapsulation, shoelace-formula area |
| `Cuboid` | **New** | A 3D solid: volume, surface area, vertex export |

## De Casteljau's algorithm (the core of `BezierCurve`)
Given control points P0..Pn, to evaluate the curve at parameter `t`:
repeatedly replace each adjacent pair of points with their linear
interpolation at `t`, until only one point remains — that's the point on
the curve. Do this for a sweep of `t` from 0 to 1 and you get the whole
curve.

This is implemented once, generically, over `PointT::getCoordinates()` —
the exact same code produces a 2D curve for `BezierCurve<Point2D>` and a
3D curve for `BezierCurve<Point3D>`, with zero duplicated logic. It also
naturally supports any number of control points (quadratic, cubic, or
higher) — nothing is hardcoded to "4 control points."

**Verified**: sampling `BezierCurve<Point2D>` and `BezierCurve<Point3D>`
confirms the curve starts exactly at the first control point (t=0) and
ends exactly at the last one (t=1), which is the defining property of a
Bezier curve.

## Polygon2D — area and perimeter for any simple polygon
- `perimeter()`: sums the Euclidean distance between each consecutive
  vertex pair (wrapping around from the last vertex back to the first).
- `area()`: the shoelace formula — `|Σ(x_i·y_i+1 − x_i+1·y_i)| / 2`. Works
  for any simple (non-self-intersecting) polygon, any number of sides ≥ 3,
  convex or not.

Demo uses a pentagon; verified output: perimeter ≈ 11.74, area ≈ 9.48.

## Cuboid — a basic 3D solid
Axis-aligned box, one corner at the origin. `volume()` = l×w×h,
`surfaceArea()` = 2(lw + wh + hl). Demo uses a 4×3×2 box — verified
volume = 24, surface area = 52 (both checked by hand).
`vertices()` returns the 8 corners in an order you can connect edge-by-edge
for a wireframe plot.

## Build & run
```bash
make
./build/assignment5
```
Produces: `line.dat`, `bezier2d.dat`, `bezier3d.dat`, `polygon.dat`,
`cuboid_vertices.dat`.

## Plot
```bash
gnuplot -e "plot 'line.dat' with linespoints; pause -1"
gnuplot -e "plot 'bezier2d.dat' with lines, 'line.dat' with points; pause -1"
gnuplot -e "splot 'bezier3d.dat' with lines; pause -1"
gnuplot -e "plot 'polygon.dat' with linespoints; pause -1"
gnuplot -e "splot 'cuboid_vertices.dat' with points pointsize 2; pause -1"
```
(macOS and Linux both have `gnuplot` available the same way once installed;
no platform-specific flags needed here, unlike Assignment 4's linker work.)

## Where this could go next (not built yet, flagging honestly)
The prerequisite list for later assignments (sketcher app, STL/OBJ export,
boolean ops) will want:
- A common `Shape` interface unifying `Polygon2D`/`Cuboid` the way
  Assignment 3's `Shape` unified `Circle`/`Rectangle` — not added here to
  keep this assignment's scope matched to what was asked, but straightforward
  to bolt on later.
- `Polygon2D`/`Cuboid` don't yet have inheritance from each other or a
  shared base, since 2D area/perimeter and 3D volume/surface-area aren't
  the same interface shape. Worth deciding deliberately when #8+ needs a
  unified `Sketchable` or similar.

## Push to git
```bash
git add .
git commit -m "Assignment 5: shape library - Bezier curves, polygon, cuboid"
git push
```
