#include "player.h"
#include "cpputils/graphics/image.h"

void Player::Draw(graphics::Image &playerSPRT) {
  // initialize the size
  // outline for player sprite
  int x, y;

  x = GetX();
  y = GetY();

  playerSPRT.DrawLine(x + 13, y + 12, x + 38, y + 12, 0, 0, 0, 1);
  playerSPRT.DrawLine(x + 12, y + 13, x + 12, y + 29, 0, 0, 0, 1);
  playerSPRT.DrawLine(x + 39, y + 13, x + 39, y + 29, 0, 0, 0, 1);
  playerSPRT.DrawLine(x + 13, y + 30, x + 38, y + 30, 0, 0, 0, 1);
  playerSPRT.DrawLine(x + 11, y + 33, x + 40, y + 33, 0, 0, 0, 1);
  playerSPRT.DrawLine(x + 11, y + 34, x + 11, y + 37, 0, 0, 0, 1);
  playerSPRT.DrawLine(x + 40, y + 34, x + 40, y + 37, 0, 0, 0, 1);
  playerSPRT.DrawLine(x + 11, y + 38, x + 40, y + 38, 0, 0, 0, 1);
  playerSPRT.DrawLine(x + 14, y + 31, x + 14, y + 32, 0, 0, 0, 1);
  playerSPRT.DrawLine(x + 37, y + 31, x + 37, y + 32, 0, 0, 0, 1);
  // color for player sprite
  playerSPRT.DrawRectangle(x + 15, y + 15, 22, 13, 0, 0, 250);
  playerSPRT.DrawLine(x + 13, y + 13, x + 38, y + 13, 128, 128, 128, 1);
  playerSPRT.DrawLine(x + 13, y + 29, x + 38, y + 29, 128, 128, 128, 1);
  playerSPRT.DrawLine(x + 13, y + 14, x + 13, y + 28, 128, 128, 128, 1);
  playerSPRT.DrawLine(x + 38, y + 14, x + 38, y + 28, 128, 128, 128, 1);
  playerSPRT.DrawLine(x + 16, y + 18, x + 18, y + 16, 255, 255, 255, 1);
  playerSPRT.DrawLine(x + 17, y + 22, x + 22, y + 17, 255, 255, 255, 1);
  playerSPRT.DrawRectangle(x + 15, y + 31, 22, 2, 128, 128, 128);
  playerSPRT.DrawRectangle(x + 12, y + 31, 28, 2, 110, 110, 110);
  playerSPRT.DrawRectangle(x + 12, y + 36, 28, 2, 100, 100, 100);

  playerSPRT.SaveImageBmp("player.bmp");
}

void PlayerProjectile::Draw(graphics::Image &pProjSPRT) {
  // initialize the size
  // outline for player sprite
  int x, y;

  x = GetX();
  y = GetY();
  pProjSPRT.DrawLine(x + 0, y + 4, x + 4, y + 0, 87, 65, 47, 1);
  pProjSPRT.DrawLine(x + 1, y + 0, x + 3, y + 0, 0, 183, 235, 1);
  pProjSPRT.DrawLine(x + 4, y + 1, x + 4, y + 3, 0, 183, 235, 1);

  pProjSPRT.SaveImageBmp("p_projectile.bmp");
}

void Player::Move(const graphics::Image &img) {}

void PlayerProjectile::Move(const graphics::Image &img) {
  SetY(GetY() - 3);
  // checks if out of bounds
  if (IsOutOfBounds(img)) {
    SetIsActive(false);
  }
}
