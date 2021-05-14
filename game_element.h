#ifndef GAME_ELEMENT_H
#define GAME_ELEMENT_H
#include "cpputils/graphics/image.h"
class GameElement {
 protected:
  int x_;
  int y_;
  int width_ = 50;
  int height_ = 50;
  bool is_active_ = true;

 public:
  GameElement() : GameElement(0, 0, 50, 50) {}
  GameElement(int x, int y, int width, int height)
      : x_(x), y_(y), width_(width), height_(height) {}
  // Getters
  int GetX() const { return x_; }
  int GetY() const { return y_; }
  int GetWidth() const { return width_; }
  int GetHeight() const { return height_; }
  bool GetIsActive() const { return is_active_; }
  // Setters
  void SetX(int x) { x_ = x; }
  void SetY(int y) { y_ = y; }
  void SetIsActive(bool is_active) { is_active_ = is_active; }
  // Memeber Fuctions
  virtual void Draw(graphics::Image &gameEl) = 0;
  virtual void Move(const graphics::Image &img) = 0;
  bool IntersectsWith(GameElement *newEl);
  bool IsOutOfBounds(const graphics::Image &imgObj);
};
#endif
