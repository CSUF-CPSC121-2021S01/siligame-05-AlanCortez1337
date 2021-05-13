#include "opponent.h"
#include "cpputils/graphics/image.h"
// opponent
void Opponent::Draw(graphics::Image &oppSPRT) {
  int x, y;
  x = GetX();
  y = GetY();
  // outline for oppenent sprite
  oppSPRT.DrawCircle(x + 26, y + 25, 14, 225, 180, 0);
  // outline for oppenent sprite
  oppSPRT.DrawLine(x + 22, y + 14, x + 23, y + 14, 0, 0, 0, 1);
  oppSPRT.DrawLine(x + 23, y + 14, x + 25, y + 16, 0, 0, 0, 1);
  oppSPRT.DrawLine(x + 25, y + 16, x + 29, y + 16, 0, 0, 0, 1);
  oppSPRT.DrawLine(x + 29, y + 16, x + 31, y + 14, 0, 0, 0, 1);
  oppSPRT.DrawLine(x + 31, y + 14, x + 33, y + 16, 0, 0, 0, 1);
  oppSPRT.DrawLine(x + 33, y + 17, x + 35, y + 23, 0, 0, 0, 1);
  oppSPRT.DrawLine(x + 36, y + 24, x + 36, y + 28, 0, 0, 0, 1);
  oppSPRT.DrawLine(x + 36, y + 28, x + 32, y + 33, 0, 0, 0, 1);
  oppSPRT.DrawLine(x + 32, y + 33, x + 20, y + 33, 0, 0, 0, 1);
  oppSPRT.DrawLine(x + 20, y + 33, x + 17, y + 29, 0, 0, 0, 1);
  oppSPRT.DrawLine(x + 17, y + 29, x + 17, y + 24, 0, 0, 0, 1);
  oppSPRT.DrawLine(x + 17, y + 24, x + 22, y + 14, 0, 0, 0, 1);
  // colors
  oppSPRT.DrawRectangle(x + 22, y + 15, 2, 18, 239, 178, 97);
  oppSPRT.DrawRectangle(x + 21, y + 17, 12, 16, 239, 178, 97);
  oppSPRT.DrawLine(x + 20, y + 19, x + 20, y + 32, 239, 178, 97, 1);
  oppSPRT.DrawLine(x + 19, y + 21, x + 19, y + 30, 239, 178, 97, 1);
  oppSPRT.DrawRectangle(x + 18, y + 24, 15, 6, 239, 178, 97);
  // eye 1
  oppSPRT.DrawLine(x + 24, y + 22, x + 25, y + 22, 0, 0, 0, 1);
  oppSPRT.DrawLine(x + 24, y + 23, x + 25, y + 23, 0, 0, 0, 1);
  oppSPRT.SetRed(x + 24, y + 22, 255);
  oppSPRT.DrawLine(x + 26, y + 22, x + 26, y + 23, 0, 0, 0, 1);
  oppSPRT.DrawLine(x + 24, y + 20, x + 25, y + 20, 0, 0, 0, 1);
  oppSPRT.DrawLine(x + 25, y + 20, x + 26, y + 21, 0, 0, 0, 1);
  // eye 2
  oppSPRT.DrawLine(x + 31, y + 21, x + 32, y + 21, 0, 0, 0, 1);
  oppSPRT.DrawLine(x + 31, y + 22, x + 32, y + 22, 0, 0, 0, 1);
  oppSPRT.SetRed(x + 31, 21, 255);
  oppSPRT.DrawLine(x + 33, y + 21, x + 33, y + 22, 0, 0, 0, 1);
  oppSPRT.DrawLine(x + 33, y + 19, x + 32, y + 19, 0, 0, 0, 1);
  oppSPRT.DrawLine(x + 32, y + 19, x + 31, y + 20, 0, 0, 0, 1);
  // nose & mouth
  oppSPRT.DrawLine(x + 31, y + 25, x + 34, y + 25, 0, 0, 0, 1);
  oppSPRT.DrawLine(x + 31, y + 22, x + 32, y + 22, 0, 0, 0, 1);
  oppSPRT.DrawRectangle(x + 32, y + 26, 3, 2, 0, 0, 0);
  oppSPRT.DrawLine(x + 33, y + 28, x + 32, y + 29, 0, 0, 0, 1);
  oppSPRT.DrawLine(x + 32, y + 29, x + 28, y + 29, 0, 0, 0, 1);
  oppSPRT.DrawLine(x + 28, y + 29, x + 27, y + 30, 0, 0, 0, 1);
  oppSPRT.SaveImageBmp("opponent.bmp");
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
  // fire outline
  oppProjSPRT.DrawLine(x + 1, y + 4, x + 3, y + 4, 255, 0, 0, 1);
  oppProjSPRT.DrawLine(x + 0, y + 2, x + 0, y + 3, 255, 0, 0, 1);
  oppProjSPRT.DrawLine(x + 4, y + 2, x + 4, y + 3, 255, 0, 0, 1);
  oppProjSPRT.DrawLine(x + 0, y + 2, x + 2, y + 0, 255, 0, 0, 1);
  oppProjSPRT.DrawLine(x + 2, y + 0, x + 4, y + 2, 255, 0, 0, 1);
  // colors inside the fire
  oppProjSPRT.DrawLine(x + 1, y + 3, x + 3, y + 3, 255, 229, 124, 1);
  oppProjSPRT.DrawLine(x + 1, y + 2, x + 3, y + 2, 255, 131, 0, 1);
  oppProjSPRT.DrawLine(x + 2, y + 1, x + 2, y + 1, 255, 0, 0, 1);
  oppProjSPRT.SaveImageBmp("o_projectile.bmp");
}

void OpponentProjectile::Move(const graphics::Image &img) {
  SetY(GetY() + 3);
  // checks if out of bounds

  if (IsOutOfBounds(img)) {
    SetIsActive(false);
  }
}

std::unique_ptr<class OpponentProjectile>
Opponent::LaunchProjectile(GameElement* opp) {
  std::unique_ptr<OpponentProjectile> ptr_heatBlst;
  if (timer == 10) { // oppj timer runs out then return the thing
    ptr_heatBlst = std::make_unique<OpponentProjectile>(opp->GetX(), opp->GetY());
    return std::move(ptr_heatBlst);
  } else {
    timer++;
  }
  return nullptr;
}
