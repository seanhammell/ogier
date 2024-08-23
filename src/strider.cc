#include "SDL2/SDL.h"

#include "include/strider/strider.h"
#include "src/graphics.h"

namespace strider {

void SetWindowSize(const int window_width, const int window_height) {
  graphics::Graphics::set_window_width(window_width);
  graphics::Graphics::set_window_height(window_height);
}

void SetVirtualResolution(const int virtual_width, const int virtual_height) {
  graphics::Graphics::set_virtual_width(virtual_width);
  graphics::Graphics::set_virtual_height(virtual_height);
}

}  // namspace strider

int main() {
  using graphics = ::strider::graphics::Graphics;

  strider::Load();

  graphics::GetInstance().Init();

  SDL_Event e;
  while (true) {
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT) {
        return 0;
      }
    }

    SDL_SetRenderDrawColor(graphics::GetInstance().renderer(), 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(graphics::GetInstance().renderer());
    SDL_RenderPresent(graphics::GetInstance().renderer());
  }

  return 0;
}
