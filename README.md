# CHIP-8 Emulator

Cycle-accurate CHIP-8 interpreter written in C++ using SDL2.

## Features
- Full 35-opcode support
- 64×32 monochrome display
- Hex keypad input
- Delay and sound timers
- Tested with IBM Logo, Pong, and opcode test suites

## Build & Run (Mac)
brew install sdl2
g++ main.cpp -o chip8 -lSDL2
./chip8 path/to/rom.ch8

Built in 2023 – Ricardo Abuabara
