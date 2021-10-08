#include "game_element.h"

#include "cpputils/graphics/image.h"

bool GameElement::IntersectsWith(GameElement* newEl) {
  return !(x_ > newEl->GetX() + newEl->GetWidth() ||
           newEl->GetX() > GetX() + GetWidth() ||
           y_ > newEl->GetY() + newEl->GetHeight() ||
           newEl->GetY() > GetY() + GetHeight());
}

bool GameElement::IsOutOfBounds(const graphics::Image& imgObj) {
  if (x_ + GetWidth() > imgObj.GetWidth() ||
      y_ + GetHeight() > imgObj.GetHeight() || x_ <= 0 || y_ <= 0) {
    return true;
  } else {
    return false;
  }
}
