<p align="center">
  <img width="256" src="res/tver.png">
</p>

> Friendly simple calculator

Tver can be used both as a single header library and as a binary executable.

# Installation

> Make sure you **install** Catch2 from `lib` folder

```sh
make test
make install
```

# Usage

You can write expressions with

- Addition (+)
- Subtraction (-)
- Multiplication (*)
- Division (/)

# Executable

Run `make` to create the executable.
Executable welcomes you with a prompt, where you can write expressions and hit enter too see the result.

# Library

Use `tver::Parser` class to create a parser. Initialize its `text` and call `parse()` to get the result as float.
