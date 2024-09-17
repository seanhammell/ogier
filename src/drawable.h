#ifndef SRC_DRAWABLE_H_
#define SRC_DRAWABLE_H_

#include "SDL2/SDL.h"

namespace ogier {
namespace graphics {

class Drawable {
 public:
  Drawable();
  Drawable(const Drawable &) = delete;
  Drawable &operator=(const Drawable &) = delete;

  virtual ~Drawable() = 0;

  virtual void Draw(const int x, const int y);

 protected:
  SDL_Texture *texture();
  int width() const;
  int height() const;

  void set_texture(SDL_Texture *texture);
  void set_width(const int width);
  void set_height(const int height);

 private:
  SDL_Texture *texture_;
  int width_;
  int height_;
};

}  // namespace graphics
}  // namespace ogier

#endif  // SRC_DRAWABLE_H_
