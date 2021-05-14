#include "opponent.h"

#include "cpputils/graphics/image.h"
// opponent
void Opponent::Draw(graphics::Image &oppSPRT) {
  int x, y;
  x = GetX();
  y = GetY();
  graphics::Image imageO;
  imageO.Load("opponent.bmp");
  for (int z = 0; z < 50; z++) {
    for (int i = 0; i < 50; i++) {
      oppSPRT.SetColor(i + x, z + y, imageO.GetColor(i, z));
    }
  }
}

void Opponent::Move(const graphics::Image &img) {
  SetY(GetY() + 1);
  SetX(GetX() + 1);
  // checks if out of bounds

  if (IsOutOfBounds(img)) {
    SetIsActive(false);
  }
}

// opponent projectile
void OpponentProjectile::Draw(graphics::Image &oppProjSPRT) {
  int x, y;
  x = GetX();
  y = GetY();
  graphics::Image imageO;
  imageO.Load("opponent_projectile.bmp");
  for (int z = 0; z < 5; z++) {
    for (int i = 0; i < 5; i++) {
      oppProjSPRT.SetColor(i + x, z + y, imageO.GetColor(i, z));
    }
  }
}

void OpponentProjectile::Move(const graphics::Image &img) {
  SetY(GetY() + 3);
  // checks if out of bounds
  if (IsOutOfBounds(img)) {
    SetIsActive(false);
  }
}

std::unique_ptr<class OpponentProjectile> Opponent::LaunchProjectile() {
  std::unique_ptr<OpponentProjectile> ptr_heatBlst;
  timer++;
  if (timer == 100) {  // oppj timer runs out then return the thing
    ptr_heatBlst = std::make_unique<OpponentProjectile>(GetX(), GetY());
    timer = 0;
    return std::move(ptr_heatBlst);
  } else {
    return nullptr;
  }
}
