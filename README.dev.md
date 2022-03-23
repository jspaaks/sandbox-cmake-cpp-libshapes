# Developer notes

## Prerequisites

- cmake >= 3.10 
- g++ compiler >= 9

## Building

```shell
cd <project root>
cmake -S . B build
```

Use `nm` to see the symbols that are included in a binary. For example:

```shell
nm --debug-syms --numeric-sort addition.cpp.o
0000000000000000 a addition.cpp
0000000000000000 b .bss
0000000000000000 n .comment
0000000000000000 d .data
0000000000000000 r .eh_frame
0000000000000000 n .note.GNU-stack
0000000000000000 t .text
0000000000000000 T _ZN10operations3addEii

# shorthand
nm -an addition.cpp.o
```

The last line is a bit difficult to read, use `c++filt` to present it in a readable fashion:

```shell
nm -an addition.cpp.o | c++filt
0000000000000000 a addition.cpp
0000000000000000 b .bss
0000000000000000 n .comment
0000000000000000 d .data
0000000000000000 r .eh_frame
0000000000000000 n .note.GNU-stack
0000000000000000 t .text
0000000000000000 T operations::add(int, int)
```

When `liboperations.a` is compiled as a static object library, looking into its contents shows it contains the addition
and subtraction objects:

```shell
nm -an liboperations.a | c++filt

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
ar -t liboperations.a
addition.cpp.o
subtraction.cpp.o
```

Or for even more information, use `readelf`, for example:

```shell
readelf -a addition.cpp.o | c++filt

ELF Header:
  Magic:   7f 45 4c 46 02 01 01 00 00 00 00 00 00 00 00 00 
  Class:                             ELF64
  Data:                              2s complement, little endian
  Version:                           1 (current)
  OS/ABI:                            UNIX - System V
  ABI Version:                       0
  Type:                              REL (Relocatable file)
  Machine:                           Advanced Micro Devices X86-64
  Version:                           0x1
  Entry point address:               0x0
  Start of program headers:          0 (bytes into file)
  Start of section headers:          552 (bytes into file)
  Flags:                             0x0
  Size of this header:               64 (bytes)
  Size of program headers:           0 (bytes)
  Number of program headers:         0
  Size of section headers:           64 (bytes)
  Number of section headers:         11
  Section header string table index: 10

Section Headers:
  [Nr] Name              Type             Address           Offset
       Size              EntSize          Flags  Link  Info  Align
  [ 0]                   NULL             0000000000000000  00000000
       0000000000000000  0000000000000000           0     0     0
  [ 1] .text             PROGBITS         0000000000000000  00000040
       0000000000000014  0000000000000000  AX       0     0     1
  [ 2] .data             PROGBITS         0000000000000000  00000054
       0000000000000000  0000000000000000  WA       0     0     1
  [ 3] .bss              NOBITS           0000000000000000  00000054
       0000000000000000  0000000000000000  WA       0     0     1
  [ 4] .comment          PROGBITS         0000000000000000  00000054
       000000000000002a  0000000000000001  MS       0     0     1
  [ 5] .note.GNU-stack   PROGBITS         0000000000000000  0000007e
       0000000000000000  0000000000000000           0     0     1
  [ 6] .eh_frame         PROGBITS         0000000000000000  00000080
       0000000000000038  0000000000000000   A       0     0     8
  [ 7] .rela.eh_frame    RELA             0000000000000000  000001b8
       0000000000000018  0000000000000018   I       8     6     8
  [ 8] .symtab           SYMTAB           0000000000000000  000000b8
       00000000000000d8  0000000000000018           9     8     8
  [ 9] .strtab           STRTAB           0000000000000000  00000190
       0000000000000025  0000000000000000           0     0     1
  [10] .shstrtab         STRTAB           0000000000000000  000001d0
       0000000000000054  0000000000000000           0     0     1
Key to Flags:
  W (write), A (alloc), X (execute), M (merge), S (strings), I (info),
  L (link order), O (extra OS processing required), G (group), T (TLS),
  C (compressed), x (unknown), o (OS specific), E (exclude),
  l (large), p (processor specific)

There are no section groups in this file.

There are no program headers in this file.

There is no dynamic section in this file.

Relocation section '.rela.eh_frame' at offset 0x1b8 contains 1 entry:
  Offset          Info           Type           Sym. Value    Sym. Name + Addend
000000000020  000200000002 R_X86_64_PC32     0000000000000000 .text + 0

The decoding of unwind sections for machine type Advanced Micro Devices X86-64 is not currently supported.

Symbol table '.symtab' contains 9 entries:
   Num:    Value          Size Type    Bind   Vis      Ndx Name
     0: 0000000000000000     0 NOTYPE  LOCAL  DEFAULT  UND 
     1: 0000000000000000     0 FILE    LOCAL  DEFAULT  ABS addition.cpp
     2: 0000000000000000     0 SECTION LOCAL  DEFAULT    1 
     3: 0000000000000000     0 SECTION LOCAL  DEFAULT    2 
     4: 0000000000000000     0 SECTION LOCAL  DEFAULT    3 
     5: 0000000000000000     0 SECTION LOCAL  DEFAULT    5 
     6: 0000000000000000     0 SECTION LOCAL  DEFAULT    6 
     7: 0000000000000000     0 SECTION LOCAL  DEFAULT    4 
     8: 0000000000000000    20 FUNC    GLOBAL DEFAULT    1 operations::add(int, int)

No version information found in this file.
```

Generate dependency graphs with CMake:

```shell
cmake --graphviz=build/dependencies.dot -S . -B build
dot -Tpng build/dependencies.dot -o build/dependencies.png
```

## Other resources

## Best practices

- _Canonical Project Structure_ http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/p1204r0.html
- _The Pitchfork Layout (PFL)_ https://api.csswg.org/bikeshed/?force=1&url=https://raw.githubusercontent.com/vector-of-bool/pitchfork/develop/data/spec.bs#src.header-placement.merged

### Videos

- _Effective CMake_ - Daniel Pfeifer - C++Now 2017 https://www.youtube.com/watch?v=bsXLMQ6WgIk
- _Using Modern CMake Patterns to Enforce a Good Modular Design_ - Mathieu Ropert - CppCon 2017 https://www.youtube.com/watch?v=eC9-iRN2b04
- _Deep CMake for Library Authors_ - Craig Scott - CppCon 2019 https://www.youtube.com/watch?v=m0DwB4OvDXk
