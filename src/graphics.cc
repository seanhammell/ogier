#include "src/graphics.h"

#include <assert.h>
#include <stdio.h>

#include "SDL2/SDL.h"

namespace ogier {
namespace graphics {

Graphics& Graphics::GetInstance() {
  static Graphics graphics;
  return graphics;
}

bool Graphics::Init() {
  assert(!initialized_);

  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    fprintf(stderr, "Error initializing SDL: %s\n", SDL_GetError());
    goto quit;
  }

  SDL_Rect monitor;
  SDL_GetDisplayBounds(SDL_GetNumVideoDisplays() - 1, &monitor);
  monitor.x += (monitor.w - window_width_) / 2;
  monitor.y += (monitor.h - window_height_) / 2;
  window_ = SDL_CreateWindow("", monitor.x, monitor.y, window_width_, window_height_, SDL_WINDOW_SHOWN);
  if (!window_) {
    fprintf(stderr, "Error creating window: %s\n", SDL_GetError());
    goto quit;
  }

  renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (!renderer_) {
    fprintf(stderr, "Error creating renderer: %s\n", SDL_GetError());
    goto quit;
  }

  if (virtual_width_ > 0 && virtual_height_ > 0) {
    if (SDL_RenderSetLogicalSize(renderer_, virtual_width_, virtual_height_) != 0) {
      fprintf(stderr, "Error setting virtual resolution: %s\n", SDL_GetError());
      goto quit;
    }
  }

  initialized_ = true;
  return initialized_;

quit:
  Quit();
  return initialized_;
}

SDL_Renderer *Graphics::renderer() { return renderer_; }

void Graphics::set_window_width(const int window_width) {
  window_width_ = window_width;
}

void Graphics::set_window_height(const int window_height) {
  window_height_ = window_height;
}

void Graphics::set_virtual_width(const int virtual_width) {
  virtual_width_ = virtual_width;
}

void Graphics::set_virtual_height(const int virtual_height) {
  virtual_height_ = virtual_height;
}

Graphics::Graphics() : window_(nullptr), renderer_(nullptr) {}

Graphics::~Graphics() { Quit(); }

void Graphics::Quit() {
  if (renderer_) {
    SDL_DestroyRenderer(renderer_);
    renderer_ = nullptr;
  }

  if (window_) {
    SDL_DestroyWindow(window_);
    window_ = nullptr;
  }

  SDL_Quit();
  initialized_ = false;
}

}  // namespace graphics
}  // namespace ogier
