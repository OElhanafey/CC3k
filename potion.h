#ifndef _POTION_H_
#define _POTION_H_

#include <string>
#include "GameObject.h"

class Potion: public GameObject {
   public:
   static std::string usedRH;
   static std::string usedBA;
   static std::string usedBD;
   static std::string usedPH;
   static std::string usedWA;
   static std::string usedWD;

   Potion(int x, int y);
   virtual ~Potion();
};

class RestoreHp: public Potion {
   public:
   RestoreHp(int x, int y);
   std::string potionType() override;
   void usePotion(GameObject& player, Floor *g) override;
};

class BoostAtk: public Potion {
   public:
   BoostAtk(int x, int y);
   std::string potionType() override;
   void usePotion(GameObject& player, Floor *g) override;
};

class BoostDef: public Potion {
   public:
   BoostDef(int x, int y);
   std::string potionType() override;
   void usePotion(GameObject& player, Floor *g) override;
};

class PoisonHp: public Potion {
   public:
   PoisonHp(int x, int y);
   std::string potionType() override;
   void usePotion(GameObject& player, Floor *g) override;
};

class WoundAtk: public Potion {
   public:
   WoundAtk(int x, int y);
   std::string potionType() override;
   void usePotion(GameObject& player, Floor *g) override;
};

class WoundDef: public Potion {
   public:
   WoundDef(int x, int y);
   std::string potionType() override;
   void usePotion(GameObject& player, Floor *g) override;
};

#endif
