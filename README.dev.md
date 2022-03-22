## Prerequisites

- cmake >= 3.10 
- g++ compiler >= 9

## Building

```shell
cd <project root>
cmake -S . B build
```

Use `nm` to see the symbols that are included in a binary and `c++filt` to present them in a readable fashion. For a library file called `liboperations.a`:

```shell
nm --debug-syms --numeric-sort liboperations.a | c++filt
# equivalent shorthand form
nm -an liboperations.a | c++filt
```

Example output:

```shell
$ nm -an build/external/operations/liboperations.a | c++filt

addition.cpp.o:
0000000000000000 b .bss
0000000000000000 n .comment
0000000000000000 d .data
0000000000000000 r .eh_frame
0000000000000000 n .note.GNU-stack
0000000000000000 r .note.gnu.property
0000000000000000 t .text
0000000000000000 T operations::add(int, int)
0000000000000000 a addition.cpp

subtraction.cpp.o:
                 U _GLOBAL_OFFSET_TABLE_
                 U operations::add(int, int)
0000000000000000 b .bss
0000000000000000 n .comment
0000000000000000 d .data
0000000000000000 r .eh_frame
0000000000000000 n .note.GNU-stack
0000000000000000 r .note.gnu.property
0000000000000000 t .text
0000000000000000 T operations::subtract(int, int)
0000000000000000 a subtraction.cpp
```

See the contents of a static library with `ar`, for example:

```shell
$ ar -t build/external/operations/liboperations.a
addition.cpp.o
subtraction.cpp.o
```

Or for even more information, use `readelf`, for example:

```shell
$ readelf -a build/external/operations/liboperations.a
```
