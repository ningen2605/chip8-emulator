# CHIP-8 Emulator

A cycle-accurate CHIP-8 interpreter/emulator written in C++ using SDL2 for graphics and input.

Built in 2023 by Ricardo Abuabara as a low-level systems programming project.

Based on Austin Morlan's excellent guide: https://austinmorlan.com/posts/chip8_emulator/

## Features
- Full support for all 35 original CHIP-8 opcodes
- 64×32 monochrome display with pixel scaling
- Hex keypad input (basic mapping included)
- Delay and sound timers
- Accurate sprite drawing with XOR collision detection (VF flag set on pixel flip)
- ROM loading starting at memory address 0x200
- Built-in fontset loaded at 0x50
- Tested with IBM Logo, Pong, and the Timendus opcode test suite

## Build & Run

### Dependencies
- SDL2 library

**Mac (Homebrew):**
```bash
brew install sdl2
Ubuntu/Linux:
Bashsudo apt-get install libsdl2-dev
Windows: Use MSYS2, vcpkg, or Visual Studio with SDL2 installed.
Compile
Bashg++ main.cpp -o chip8 -lSDL2
Run
Bash./chip8 path/to/your_rom.ch8
Test ROMs & Games
You can find free CHIP-8 ROMs and test suites here:

Opcode test suite: https://github.com/Timendus/chip8-test-suite
Classic games (Pong, Space Invaders, Tetris, etc.): Search "CHIP-8 ROM pack"

Enjoy running retro games on your own emulator!
