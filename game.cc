#include "game.h"
#include "cpputils/graphics/image.h"
#include <memory>

const std::string score = "Doge Coins: ";
const graphics::Color white(255, 255, 255);
const graphics::Color black(0, 0, 0);

void Game::CreateOpponents() {
  Opponent frstOpp(0, 0);
  Opponent scndOpp(50, 0);
  std::unique_ptr<Opponent> opp1 = std::make_unique<Opponent>(frstOpp);
  opponent_.push_back(std::move(opp1));
  std::unique_ptr<Opponent> opp2 = std::make_unique<Opponent>(scndOpp);
  opponent_.push_back(std::move(opp2));

}
/*
void Game::CreateOpponentProjectiles() {
  OpponentProjectile frstoppProj(0, 0);
  OpponentProjectile scndoppProj(50, 0);
  std::unique_ptr<OpponentProjectile> oppProj1 =
      std::make_unique<OpponentProjectile>(frstoppProj);
  oppProj_.push_back(std::move(oppProj1));
  std::unique_ptr<OpponentProjectile> oppProj2 =
      std::make_unique<OpponentProjectile>(scndoppProj);
  oppProj_.push_back(std::move(oppProj2));
}

void Game::CreatePlayerProjectiles() {
  PlayerProjectile frstplyrProj(150, 150);
  std::unique_ptr<PlayerProjectile> plyrProj =
      std::make_unique<PlayerProjectile>(frstplyrProj);
  plyrProj_.push_back(std::move(plyrProj));
}
*/
void Game::Init() {
  player_.SetX(400);
  player_.SetY(300);
  //CreateOpponents();
  //CreateOpponentProjectiles();
  //CreatePlayerProjectiles();
  gScreen_.AddMouseEventListener(*this);
  gScreen_.AddAnimationEventListener(*this);
}

void Game::MoveGameElements() {
  for (int index = 0; index < opponent_.size(); index++) {
    opponent_[index]->Move(gScreen_);
  }
  for (int index = 0; index < oppProj_.size(); index++) {
    oppProj_[index]->Move(gScreen_);
  }
  for (int index = 0; index < plyrProj_.size(); index++) {
    plyrProj_[index]->Move(gScreen_);
  }
}

void Game::FilterIntersections() { // MIGHT NEED TO CHANGE SOME VARIABLES
  // checks if player proj intersects with opponent

  for (int i = 0; i < opponent_.size(); i++) {

    if (opponent_[i]->GetIsActive() && player_.GetIsActive() && player_.IntersectsWith(opponent_[i].get())) {
      // opponents_.erase(opponents_.begin() + i);
      opponent_[i]->SetIsActive(false);
      player_.SetIsActive(false);
      playing_ = true;
    } else {
      for (int j = 0; j < plyrProj_.size(); j++) {
        if (opponent_[i]->GetIsActive() && plyrProj_[j]->GetIsActive() && plyrProj_[j]->IntersectsWith(opponent_[i].get())) {
         opponent_[i]->SetIsActive(false);
         plyrProj_[j]->SetIsActive(false);
         p_score_++;
        }
      }
    }
  }
  for (int i = 0; i < oppProj_.size(); i++) {
    if (oppProj_[i]->GetIsActive() && player_.GetIsActive() && player_.IntersectsWith(oppProj_[i].get())) {
      oppProj_[i]->SetIsActive(false);
      player_.SetIsActive(false);
      playing_ = true;
    }
  }
}

void Game::UpdateScreen() {
  gScreen_.DrawRectangle(0, 0, 800, 600, white);
  gScreen_.DrawText(0, 0, score + std::to_string(GetScore()), 12, black);
  if (player_.GetIsActive()) {
    player_.Draw(gScreen_);
  }
  for (int index = 0; index < opponent_.size(); index++) { // opponent

    if (opponent_[index]->GetIsActive()) {
      opponent_[index]->Draw(gScreen_);
    }
  }
  for (int index = 0; index < oppProj_.size(); index++) { // opponent projectile
    if (opponent_[index]->GetIsActive()) {
      oppProj_[index]->Draw(gScreen_);
    }
  }
  for (int index = 0; index < plyrProj_.size(); index++) { // player projectile
    if (plyrProj_[index]->GetIsActive()) {
      plyrProj_[index]->Draw(gScreen_);
    }
  }
}

void Game::RemoveInactive() {
  //if (!player_.GetIsActive()) {
  //  player_.erase();
  //}
  for (int index = opponent_.size(); index >= 0; index--) { // opponent
    if (!opponent_[index]->GetIsActive()) {
      opponent_.erase(opponent_.begin() + index);// possibly need to change index to osmething else
    }
  }
  for (int index = oppProj_.size(); index >= 0; index--) { // opponent projectile
    if (!opponent_[index]->GetIsActive()) {
      oppProj_.erase(oppProj_.begin() + index);
    }
  }
  for (int index = plyrProj_.size(); index >= 0; index--) { // player projectile
    if (!plyrProj_[index]->GetIsActive()) {
      plyrProj_.erase(plyrProj_.begin() + index);
    }
  }
}
void Game::LaunchProjectiles(){
  std::unique_ptr<OpponentProjectile> projectile;
  for (int index = 0; index < opponent_.size(); index++) { // opponent
    projectile = opponent_[index]->LaunchProjectile();
    if (projectile != nullptr) {
    oppProj_.push_back(std::move(projectile));
    }
  }
}
void Game::OnAnimationStep() {
  if(opponent_.size() == 0){
    CreateOpponents();
  }
  MoveGameElements();
  LaunchProjectiles();
  FilterIntersections();
  RemoveInactive();
  UpdateScreen();
  gScreen_.Flush();
}

void Game::OnMouseEvent(const graphics::MouseEvent &event) {
  if (event.GetMouseAction() == graphics::MouseAction::kMoved || event.GetMouseAction() == graphics::MouseAction::kDragged) {
    int new_x = event.GetX() - player_.GetWidth() / 2;
    int new_y = event.GetY() - player_.GetHeight() / 2;
    int old_x = player_.GetX();
    int old_y = player_.GetY();
    player_.SetX(new_x);
    player_.SetY(new_y);
    if (player_.IsOutOfBounds(gScreen_)) {
      player_.SetX(old_x);
      player_.SetY(old_y);
    }
  }
  if ((event.GetMouseAction() == graphics::MouseAction::kPressed || event.GetMouseAction() == graphics::MouseAction::kDragged) && player_.GetIsActive()){ // AND IS ACTIVE
    PlayerProjectile newPPJ(player_.GetX()+10, player_.GetY()+10);// might need to adjust y
    std::unique_ptr<PlayerProjectile> ptr_newPPJ = std::make_unique<PlayerProjectile>(newPPJ);
    plyrProj_.push_back(std::move(ptr_newPPJ));
  }
}
