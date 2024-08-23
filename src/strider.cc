#include "SDL2/SDL.h"

#include "src/graphics.h"

int main() {
  using graphics = ::strider::graphics::Graphics;
  graphics::set_window_width(720);
  graphics::set_window_height(480);

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
