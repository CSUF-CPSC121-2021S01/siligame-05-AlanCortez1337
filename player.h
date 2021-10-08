#ifndef PLAYER_H
#define PLAYER_H
#include "cpputils/graphics/image.h"
#include "game_element.h"
#include "opponent.h"

class Player : public GameElement {
 public:
  Player() : Player(0, 0) {}
  Player(int x, int y) : GameElement(x, y, 50, 50) {}
  void Draw(graphics::Image &playerSPRT) override;
  // bool IntersectsWith(const Opponent &opponent);
  // bool IntersectsWith(const OpponentProjectile &proj);
  void Move(const graphics::Image &moveObj) override;
};

class PlayerProjectile : public GameElement {
 public:
  PlayerProjectile() : PlayerProjectile(0, 0) {}
  PlayerProjectile(int x, int y) : GameElement(x, y, 5, 5) {}
  // function
  void Draw(graphics::Image &pProjSPRT) override;
  // bool IntersectsWith(const Opponent &opp);
  void Move(const graphics::Image &moveObj) override;
};
#endif
