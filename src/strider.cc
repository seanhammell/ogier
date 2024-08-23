#include "SDL2/SDL.h"

#include "src/graphics.h"

int main() {
  strider::graphics::Graphics::set_window_width(720);
  strider::graphics::Graphics::set_window_height(480);

  strider::graphics::Graphics::GetInstance().Init();

  SDL_Event e;
  while (true) {
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT) {
        return 0;
      }
    }

    SDL_SetRenderDrawColor(strider::graphics::Graphics::GetInstance().renderer(), 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(strider::graphics::Graphics::GetInstance().renderer());
    SDL_RenderPresent(strider::graphics::Graphics::GetInstance().renderer());
  }

  return 0;
}
