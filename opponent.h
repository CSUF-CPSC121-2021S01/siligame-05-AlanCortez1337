#ifndef OPPONENT_H
#define OPPONENT_H
#include "cpputils/graphics/image.h"
#include "game_element.h"
#include <memory>

class Opponent : public GameElement {
private:
  int timer = 0;

public:
  Opponent() : Opponent(0, 0) {}
  Opponent(int x, int y) : GameElement(x, y, 50, 50) {}
  void Draw(graphics::Image &oppSPRT) override;
  void Move(const graphics::Image &moveObj) override;
  std::unique_ptr<class OpponentProjectile> LaunchProjectile(GameElement* opp);
};

class OpponentProjectile : public GameElement {

public:
  OpponentProjectile() : OpponentProjectile(0, 0) {}
  OpponentProjectile(int x, int y) : GameElement(x, y, 5, 5) {}
  void Draw(graphics::Image &oppProjSPRT) override;
  void Move(const graphics::Image &moveObj) override;
};
#endif
