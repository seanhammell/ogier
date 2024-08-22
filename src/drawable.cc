#include "src/drawable.h"

namespace strider {
namespace graphics {

Drawable::Drawable() : texture_(nullptr), width_(0), height_(0) {}

Drawable::~Drawable() {}

void Drawable::Draw(const int x, const int y) {
  SDL_Rect dest = {x, y, width_, height_};
  SDL_RenderCopy(nullptr, texture_, nullptr, &dest);
}

SDL_Texture *Drawable::texture() { return texture_; }

int Drawable::width() const { return width_; }

int Drawable::height() const { return height_; }

void Drawable::set_texture(SDL_Texture *texture) { texture_ = texture; }

void Drawable::set_width(const int width) { width_ = width; }

void Drawable::set_height(const int height) { height_ = height; }

}  // namespace graphics
}  // namespace strider
