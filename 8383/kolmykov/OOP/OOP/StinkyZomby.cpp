#include "StinkyZomby.h"



StinkyZomby::StinkyZomby()
{
	attackBehavior = std::shared_ptr<AttackBehavior>(new StinkyAttack());
	weapon = std::shared_ptr<Weapon>(new StinkingBody());
	type = UnitType::STINKY_ZOMBY;
}

StinkyZomby::StinkyZomby(int hp, int maxHP, int ownArmor, int ownDamage, bool visability, int level, int landDamage, int landDefence, std::shared_ptr<std::shared_ptr<ObserverInterface>[]> observers, int observerSize, int observerCount, int coordX, int coordY, std::shared_ptr<Mediator> mediator)
:CommonZomby(hp, maxHP, ownArmor, ownDamage, visability, level, landDamage, landDefence, observers, observerSize, observerCount, coordX, coordY, mediator){
	attackBehavior = std::shared_ptr<AttackBehavior>(new StinkyAttack());
	weapon = std::shared_ptr<Weapon>(new StinkingBody());
	type = UnitType::STINKY_ZOMBY;
}

StinkyZomby::StinkyZomby(int x, int y, int level):CommonZomby(x, y, level)
{
	attackBehavior = std::shared_ptr<AttackBehavior>(new StinkyAttack());
	weapon = std::shared_ptr<Weapon>(new StinkingBody());
	type = UnitType::STINKY_ZOMBY;
}

StinkyZomby::StinkyZomby(const StinkyZomby & other):CommonZomby(other)
{
}


StinkyZomby::StinkyZomby(StinkyZomby && other):CommonZomby(other)
{
}

StinkyZomby& StinkyZomby::operator=(const StinkyZomby & other)
{
	this->hp = other.hp;
	this->maxHP = other.maxHP;
	this->ownArmor = other.ownArmor;
	this->ownDamage = other.ownDamage;
	this->visability = other.visability;
	this->level = other.level;
	this->landDamage = other.landDamage;
	this->landDefence = other.landDefence;

	this->weapon = std::shared_ptr<Weapon>(new Weapon(*other.weapon));
	this->armor = std::shared_ptr<Armor>(new Armor(*other.armor));
	this->moveBehavior = std::shared_ptr<MoveBehavior>(new MoveBehavior(*other.moveBehavior));
	this->attackBehavior = std::shared_ptr<AttackBehavior>(new AttackBehavior(*other.attackBehavior));

	this->observerSize = 0;
	this->observerCount = 0;
	this->coordX = other.coordX;
	this->coordY = other.coordY;

	return *this;
}

StinkyZomby & StinkyZomby::operator=(StinkyZomby && other)
{
	if (&other == this) {
		return *this;
	}

	this->hp = other.hp;
	this->maxHP = other.maxHP;
	this->ownArmor = other.ownArmor;
	this->ownDamage = other.ownDamage;
	this->visability = other.visability;
	this->level = other.level;
	this->landDamage = other.landDamage;
	this->landDefence = other.landDefence;

	this->weapon = std::shared_ptr<Weapon>(new Weapon(*other.weapon));
	this->armor = std::shared_ptr<Armor>(new Armor(*other.armor));
	this->moveBehavior = std::shared_ptr<MoveBehavior>(new MoveBehavior(*other.moveBehavior));
	this->attackBehavior = std::shared_ptr<AttackBehavior>(new AttackBehavior(*other.attackBehavior));

	this->observerSize = 0;
	this->observerCount = 0;
	this->coordX = other.coordX;
	this->coordY = other.coordY;

	return *this;
}

StinkyZomby::~StinkyZomby()
{
}

char StinkyZomby::getChar()
{
	return 'F';
}
