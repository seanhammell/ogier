#ifndef SRC_GRAPHICS_H_
#define SRC_GRAPHICS_H_

#include "SDL2/SDL.h"

namespace strider {
namespace graphics {

class Graphics {
 public:
  static Graphics& GetInstance();

  bool Init();

  SDL_Renderer *renderer();

  static void set_window_width(const int window_width);
  static void set_window_height(const int window_height);
  static void set_virtual_width(const int virtual_width);
  static void set_virtual_height(const int virtual_height);

 private:
  Graphics();
  Graphics(const Graphics&) = delete;
  Graphics &operator=(const Graphics&) = delete;

  ~Graphics();

  void Quit();

  inline static bool initialized_ = false;

  inline static int window_width_ = 0;
  inline static int window_height_ = 0;
  inline static int virtual_width_ = 0;
  inline static int virtual_height_ = 0;

  SDL_Window *window_;
  SDL_Renderer *renderer_;
};

}  // namespace graphics
}  // namespace strider

#endif  // SRC_GRAPHICS_H_
