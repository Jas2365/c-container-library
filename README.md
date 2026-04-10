# C Container Library

A lightweight, header-based C library providing essential container types and utilities for efficient memory management and data structures. Containers and their utilities are macro based, except string

## Features

- **Dynamic Strings**
- **Generic Lists**
- **Generic Arrays**
- **Generic Stack**
- **Generic Linked Lists**
- **Pointer**
- **Arena Allocator**
- **Type Aliases**

## Quick Start

### Build
```bash
make build
```

### Run
```bash
make run
```

### Clean
```bash
make clean
```

### Build & Run All
```bash
make
```

## Configuration

The arena allocator mode can be configured at build time:
```bash
make build Arena_Mode=_Large_Arena_
```

Default mode: `_Small_Arena_` 64Kib

## Project Structure

```
inc/
├── strings/      # Strings string, *str_ptr
├── lists/        # Lists   List(T)
├── arrays/       # Arrays  Array(T, N)
├── ptr/          # is_ptr(obj), to_ptr(obj)
├── my_defs.h     # Common definitions
└── my_ints.h     # Fixed Length types

```

## Requirements

- **GCC** or compatible C compiler
- **Make** build system
- C23

## License

Apache License 2.0 – See [LICENSE](LICENSE) for details.

Copyright © 2026 Jas2365
