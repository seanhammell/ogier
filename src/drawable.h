// Drawable class
  // pure virtual destructor (make sure to actually define this)
  // Draw function with x position, y position, and optional clip parameters
  // getters and setters for each member
  // SDL_Texture member
  // Width member
  // Height member
// end Drawable class

#include "SDL2/SDL.h"

namespace strider {
namespace graphics {

class Drawable {
 public:
  Drawable();
  Drawable(const Drawable&) = delete;
  Drawable& operator=(const Drawable&) = delete;

  virtual ~Drawable() = 0;

  void Draw(int x, int y);

 protected:
  SDL_Texture *texture();
  int width();
  int height();

  void set_texture(SDL_Texture *texture);
  void set_width(int width);
  void set_height(int height);

 private:
  SDL_Texture *texture_;
  int width_;
  int height_;
};

}  // namespace graphics
}  // namespace strider
