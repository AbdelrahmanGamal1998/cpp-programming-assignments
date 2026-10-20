# C++ Programming Assignments

[![Build](https://github.com/AbdelrahmanGamal1998/cpp-programming-assignments/actions/workflows/build.yml/badge.svg)](https://github.com/AbdelrahmanGamal1998/cpp-programming-assignments/actions/workflows/build.yml)

Eight small C++ programs written during my computer science studies (2021): algorithms, object-oriented
design, a simulation, text and file processing, and linked lists. Each folder is one assignment with its own
`main.cpp`. They are console programs, so you run them and type input.

| #   | Folder                                                  | What it is                                                                                          |
| --- | ------------------------------------------------------- | --------------------------------------------------------------------------------------------------- |
| 01  | [`01-prime-and-gcd-algorithms`](01-prime-and-gcd-algorithms)       | Four ways to test primality (trial division, Fermat, Miller-Rabin and a simple test) and four ways to compute the GCD |
| 02  | [`02-sorting-algorithms`](02-sorting-algorithms)                   | Selection, bubble, insertion and merge sort, with timing to compare them                            |
| 03  | [`03-matrix-calculator-oop`](03-matrix-calculator-oop)             | A `Matrix` class and a menu-driven matrix calculator                                                |
| 04  | [`04-shapes-oop`](04-shapes-oop)                                   | Inheritance and polymorphism: `Shape`, `Rect`, `Square`, `Circle` and a small `ShapeGame`. **Windows only** (uses `windows.h`) |
| 05  | [`05-mouse-island-game`](05-mouse-island-game)                     | Simulation of mice moving randomly on an island grid and counting how many sink, are eaten, escape or starve. **Windows only** |
| 06  | [`06-text-encryption-compression`](06-text-encryption-compression) | Caesar-style encryption and decryption and run-length compression of text                           |
| 07  | [`07-file-encryption-compression`](07-file-encryption-compression) | The same operations applied to the contents of a file (`test.txt` is a sample)                      |
| 08  | [`08-travel-reservation`](08-travel-reservation)                   | A flight reservation system built on a linked list: reserve and cancel tickets, search by name, update by ID, sort and print |

## Build and run

You need a C++ compiler (g++ 9 or newer is fine).

```bash
./build.sh                     # builds every program into build/
./build/02-sorting-algorithms  # run one (add .exe on Windows)
```

`build.sh` compiles every folder with `g++ -std=c++17 -Wall -O2`. On Linux and macOS it skips the two
Windows-only programs (04 and 05). On Windows, run it from Git Bash or MSYS2, or compile a folder by hand:

```bash
g++ -std=c++17 -Wall -O2 -Iinclude main.cpp src/*.cpp -o shapes   # folders with include/ and src/
g++ -std=c++17 -Wall -O2 main.cpp -o sorting                      # single-file folders
```

The GitHub Actions workflow builds all eight programs on Windows and the six portable ones on Ubuntu for every
push.

## Notes

- These are student assignments and keep their original style. The only changes made when the repository was
  cleaned up were removing build output (`.exe`, `.o`, Code::Blocks project files) and the instructor's
  assignment PDFs, and adding this README, a build script and CI.
- The original repositories (one ZIP each) were merged here. Their history is not part of this repository.

## License

[MIT](LICENSE)
