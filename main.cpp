/*
  CHIP-8 Emulator
  Ricardo Abuabara - 2023
  Based on Austin Morlan's guide: https://austinmorlan.com/posts/chip8_emulator/
  Built with C++17 + SDL2
*/

#include <cstdint>
#include <fstream>
#include <chrono>
#include <random>
#include <cstring>
#include <iostream>
#include <SDL.h>

const unsigned int START_ADDRESS = 0x200;
const unsigned int FONTSET_SIZE = 80;
const unsigned int FONTSET_START_ADDRESS = 0x50;
const unsigned int VIDEO_WIDTH = 64;
const unsigned int VIDEO_HEIGHT = 32;

uint8_t fontset[FONTSET_SIZE] = {
  0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
  0x20, 0x60, 0x20, 0x20, 0x70, // 1
  0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
  0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
  0x90, 0x90, 0xF0, 0x10, 0x10, // 4
  0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
  0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
  0xF0, 0x10, 0x20, 0x40, 0x40, // 7
  0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
  0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
  0xF0, 0x90, 0xF0, 0x90, 0x90, // A
  0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
  0xF0, 0x80, 0x80, 0x80, 0xF0, // C
  0xE0, 0x90, 0x90, 0x90, 0xE0, // D
  0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
  0xF0, 0x80, 0xF0, 0x80, 0x80  // F
};

class Chip8 {
public:
  uint8_t registers[16]{};
  uint8_t memory[4096]{};
  uint16_t index{};
  uint16_t pc{};
  uint16_t stack[16]{};
  uint8_t sp{};
  uint8_t delayTimer{};
  uint8_t soundTimer{};
  uint8_t keypad[16]{};
  uint32_t video[64 * 32]{};
  uint16_t opcode{};

  Chip8() {
    pc = START_ADDRESS;
    for (int i = 0; i < FONTSET_SIZE; ++i)
      memory[FONTSET_START_ADDRESS + i] = fontset[i];
  }

  void LoadROM(const char* filename) {
    std::ifstream file(filename, std::ios::binary | std::ios::ate);
    if (file.is_open()) {
      std::streampos size = file.tellg();
      char* buffer = new char[size];
      file.seekg(0, std::ios::beg);
      file.read(buffer, size);
      file.close();
      for (long i = 0; i < size; ++i)
        memory[START_ADDRESS + i] = buffer[i];
      delete[] buffer;
    }
  }

  // (Full opcode implementation from Austin Morlan's guide is abbreviated here for brevity – the full code is in the previous message, but this version is shortened to fit. Use the full one from earlier if needed.)
  // In practice, paste the full main.cpp from my previous long message.
};

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <ROM file>\n";
    return -1;
  }

  Chip8 chip8;
  chip8.LoadROM(argv[1]);

  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window* window = SDL_CreateWindow("CHIP-8 Emulator", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, VIDEO_WIDTH * 10, VIDEO_HEIGHT * 10, 0);
  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
  SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, VIDEO_WIDTH, VIDEO_HEIGHT);

  // Main loop (simplified)
  bool quit = false;
  while (!quit) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) quit = true;
    }

    // Cycle, update video, render...
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyTexture(texture);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
