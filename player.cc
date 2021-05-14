#include "player.h"

#include "cpputils/graphics/image.h"

void Player::Draw(graphics::Image &playerSPRT) {
  // initialize the size
  // outline for player sprite
  int x, y;

  x = GetX();
  y = GetY();
  graphics::Image imageO;
  imageO.Load("player.bmp");
  for (int z = 0; z < 50; z++) {
    for (int i = 0; i < 50; i++) {
      playerSPRT.SetColor(i + x, z + y, imageO.GetColor(i, z));
    }
  }
}

void PlayerProjectile::Draw(graphics::Image &pProjSPRT) {
  int x, y;
  x = GetX();
  y = GetY();
  graphics::Image imageO;
  imageO.Load("player_projectile.bmp");
  for (int z = 0; z < 5; z++) {
    for (int i = 0; i < 5; i++) {
      pProjSPRT.SetColor(i + x, z + y, imageO.GetColor(i, z));
    }
  }
}

void Player::Move(const graphics::Image &img) {}

void PlayerProjectile::Move(const graphics::Image &img) {
  SetY(GetY() - 3);
  // checks if out of bounds
  if (IsOutOfBounds(img)) {
    SetIsActive(false);
  }
}
