#ifndef GAME_H
#define GAME_H
#include <vector>
#include "cpputils/graphics/image.h"
#include "game_element.h"
#include "opponent.h"
#include "player.h"
#include <memory>

class Game : graphics::AnimationEventListener, graphics::MouseEventListener {
 private:
  graphics::Image gScreen_;
  std::vector<std::unique_ptr<Opponent>> opponent_;
  std::vector<std::unique_ptr<OpponentProjectile>> oppProj_;
  std::vector<std::unique_ptr<PlayerProjectile>> plyrProj_;
  Player player_;
  int p_score_ = 0;
  bool playing_ = false;

 public:
  Game() : gScreen_(800, 600) {}
  Game(int width, int height) : gScreen_(width, height) {}
  // getters
  graphics::Image &GetGameScreen() { return gScreen_; }
  std::vector<std::unique_ptr<Opponent>> &GetOpponents() { return opponent_; }
  std::vector<std::unique_ptr<OpponentProjectile>> &GetOpponentProjectiles() { return oppProj_; }
  std::vector<std::unique_ptr<PlayerProjectile>> &GetPlayerProjectiles() { return plyrProj_; }
  Player &GetPlayer() { return player_; }
  int GetScore() const { return p_score_; }
  bool HasLost() const { return playing_; }// might need to add onto this?
  // member fuctions
  void CreateOpponents();            // creates the opponents
  //void CreateOpponentProjectiles();  // creates the opponent projectiles
  //void CreatePlayerProjectiles();    // creates the player projectiles
  void Init();  // initializes the opponents, opponent projectiles, player
                // projectiles
  void LaunchProjectiles();
  void MoveGameElements();
  void FilterIntersections();
  void UpdateScreen();  // updates the game screen
  void OnAnimationStep() override;
  void OnMouseEvent(const graphics::MouseEvent &event) override;
  void Start() { gScreen_.ShowUntilClosed(); }  // starts the game
  void RemoveInactive();
};
#endif
