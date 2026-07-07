# Assignment 4 — Shared Libraries, Static vs Dynamic Linking

Builds on Assignment 3's `Shape`/`Circle`/`Rectangle`/`Square` hierarchy — same
code, but now compiled into libraries two different ways so you can actually
see, not just read about, what "static" and "dynamic" mean.

## The two library types

| | Static (`libshapes.a`) | Shared (`libshapes.so`) |
|---|---|---|
| Built with | `ar rcs` (archiver) | `g++ -shared`, objects compiled with `-fPIC` |
| Linked how | Code is **copied into** the final binary at link time | Binary only stores a *reference*; code is loaded at **runtime** by `ld.so` |
| Runtime dependency | None — self-contained | Needs `libshapes.so` to be findable at runtime |
| Binary size | Bigger (72K here) | Smaller (60K here) |
| Update the library later | Must relink every app that uses it | Every app picks up the new `.so` automatically, no relink needed |

## Verified output (this exact run)

`ldd build/app_shared` lists `libshapes.so` as a dependency:
```
libshapes.so => /home/claude/assignment4/build/../lib/libshapes.so (...)
libstdc++.so.6 => ...
libc.so.6 => ...
```

`ldd build/app_static` does **not** — `libshapes` isn't there at all, only the
standard C/C++ runtime libs (which are dynamic by default on Linux regardless):
```
libstdc++.so.6 => ...
libc.so.6 => ...
```

That's the whole lesson in one command: the static binary doesn't need
`libshapes` at runtime because it's already inside it.

## Why `app_shared` runs without extra setup
Normally a `.so` that isn't installed system-wide (e.g. not in `/usr/lib`)
needs `LD_LIBRARY_PATH` set so the dynamic linker can find it. This project
avoids that by baking a **relative** rpath into the binary at link time:
```
-Wl,-rpath,'$ORIGIN/../lib'
```
`$ORIGIN` means "wherever this binary actually is," so `build/app_shared`
always looks in `../lib` relative to itself — it works regardless of which
directory you run it from, with no environment variables to set.

## Build & run
```bash
make              # builds both libs + both app binaries
make run-static    # ./build/app_static
make run-shared    # ./build/app_shared
make inspect       # ldd on both, size comparison, symbol list from the .so
make clean
```

## Useful Linux commands this touches (per the prerequisites)
- `ar rcs lib.a *.o` — bundle object files into a static archive
- `g++ -fPIC -c ...` — compile position-independent code (required for `.so`)
- `g++ -shared -o lib.so *.o` — link objects into a shared library
- `ldd binary` — list a binary's runtime shared-library dependencies
- `nm -D lib.so` — list a shared library's exported (dynamic) symbols
- `du -h` — compare binary sizes

## Push to git
```bash
git add .
git commit -m "Assignment 4: static (.a) vs shared (.so) libs, linked two ways"
git push
```
