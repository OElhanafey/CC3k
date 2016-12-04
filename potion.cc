#include "potion.h"

std::string Potion::usedRH = "unknown potion";
std::string Potion::usedBA = "unknown potion";
std::string Potion::usedBD = "unknown potion";
std::string Potion::usedPH = "unknown potion";
std::string Potion::usedWA = "unknown potion";
std::string Potion::usedWD = "unknown potion";

Potion::Potion(int x, int y):
   GameObject(x , y, 'P') {}

Potion::~Potion() {}

   // RESTORE HEALTH: Boosts up the health
   RestoreHp::RestoreHp(int x, int y):
      Potion(x,y) { }

std::string RestoreHp::potionType() {
   return usedRH;
}

void RestoreHp::usePotion(GameObject& player) {
   // Change string if potion used for the first time
   if (usedRH == "unknown potion") usedRH = "Restore Health";

   // Calculate the amount of boost in health received by a player
   int diff = player.getMaxHp() - player.getHP();
   int boost = 10 * player.getPotionEffect();
   if((player.getRace() != "Vampire") && (boost > diff)) boost = diff;

   player.setHP(player.getHP() + boost);
}

// BOOST ATTACK: Increases the attack points
BoostAtk::BoostAtk(int x, int y):
   Potion(x,y) {}

std::string BoostAtk::potionType() {
   return usedBA;
}

void BoostAtk::usePotion(GameObject& player) {
   if (usedBA == "unknown potion") usedBA = "Boost Attack";
   int boost = 5 * player.getPotionEffect();
   player.setAtk(player.getAtk() + boost);
}

// BOOST DEFENSE: Increases the defense points
BoostDef::BoostDef(int x, int y):
   Potion(x,y) {}

std::string BoostDef::potionType() {
   return usedBD;
}

void BoostDef::usePotion(GameObject& player) {
   if (usedBD == "unknown potion") usedBD = "Boost Defence";
   int boost = 5 * player.getPotionEffect();
   player.setDef(player.getDef() + boost);
}

// POISON HEALTH: Decreases the health points. Cannot fall before 0.
PoisonHp::PoisonHp(int x, int y):
   Potion(x,y) {}

std::string PoisonHp::potionType() {
   return usedPH;
}

void PoisonHp::usePotion(GameObject& player) {
   if (usedPH == "unknown potion") usedPH = "Poison Health";

   // Calculate the amount of boost in health received by a player
   int damage = 10 * player.getPotionEffect();
   if ((player.getHP() - damage) < 0) damage = player.getHP();

   player.setHP(player.getHP() - damage);

   // Throw game over exception if health goes down to 0
   if(player.getHP() == 0) throw "Game Over";
}

// WOUND ATTACK: Decreases the attack points.
WoundAtk::WoundAtk(int x, int y):
   Potion(x,y) {}

std::string WoundAtk::potionType() {
   return usedWA;
}

void WoundAtk::usePotion(GameObject& player) {
   if (usedWA == "unknown potion") usedWA = "Wound Attack";

   int damage = 5 * player.getPotionEffect();
   if ((player.getAtk() - 5) < 0) damage = player.getAtk();

   player.setAtk(player.getAtk() - damage);
}

// WOUND DEFENSE: Decreases the defense points.
WoundDef::WoundDef(int x, int y):
   Potion(x,y) {}

std::string WoundDef::potionType() {
   return usedWD;
}

void WoundDef::usePotion(GameObject& player) {
   if (usedWD == "unknown potion") usedWD = "Wound Defence";

   int damage = 5 * player.getPotionEffect();
   if ((player.getDef() - 5) < 0) damage = player.getDef();

   player.setAtk(player.getDef() - damage);
}
