#include "Enemy.hpp"
#include <random>
#include <iostream>

Enemy::Enemy(std::string _name, int _hp, int _streight, int _stamina, int _lucky, int _gold, int _exp, std::string _nickname , sI _item)
{
	if (_name.size() < 14) {
		name = _name;
		for (int i = _name.size(); i < 14; i++) {
			name.append(" ");
		}
	}
	else if (_name.size() == 14) {
		name = _name;
	}
	else if (_name.size() == 14) {
		name = _name.substr(0, 14);
	}
	name = _name;
	hp = _hp;
	currHp = hp;
	streight = _streight;
	stamina = _stamina;
	currStamina = _stamina;
	death = false;
	lucky = _lucky;
	attackModify = 0;
	nickname = _nickname;
	gold = _gold;
	exp = _exp;
	item = _item;
}

int Enemy::powerFullAttack()
{
	int mstamina = stamina*0.4;
	int hit;
	std::string isCritical = "  ";
	if (currStamina - mstamina >= 0) {
		currStamina -= mstamina;

		if (criticalHit()) {
			isCritical = "!! Critical Hit !!";
			hit = 3 * streight + attackModify;
		}
		else {
			hit = 2 * streight + attackModify;
		}
		printLogFight("Silny atak ", hit, isCritical);
		return hit;
	}
	else
		return 0;
}

int Enemy::specialAttack()
{
	std::random_device rd{};
	std::mt19937 gen{ rd() };
	std::uniform_int_distribution<> a(0, streight / 60);
	int special = a(gen);
	int mstamina = stamina * 0.3;
	std::string isCritical = "  ";
	int hit = 0;
	if (currStamina - mstamina >= 0) {
		currStamina -= mstamina;

		if (criticalHit()) {
			isCritical = "!! Critical Hit !!";
			hit = 2 * streight + attackModify + special;
		}
		else {
			hit = streight + attackModify + special;
		}
		printLogFight("Atak specjalny ", hit, isCritical);
		return hit;
	}
	else
		return 0;
}

void Enemy::statInfo()
{
}

reward Enemy::getEnemyReward()
{
	reward reward{};
	reward.gold = gold;
	reward.exp = exp;
	if (item != nullptr)
		reward.rewItem = item;
	return reward;
}

int Enemy::enemyAttack(int z)
{
	std::random_device rd{};
	std::mt19937 gen{ rd() };
	int x;
	int v;
	if (currStamina < 10) {
		v = 0;
		x = 0;
	}
	else if (currStamina >= 10 && currStamina < 20) {
		v = 1;
		x = 1;
	}
	else if (currStamina >= 20 && currStamina < 30) {
		v = 1;
		x = 2;
	}
	else if(currStamina>=30) {
		v = 1;
		x = 3;
	}
	std::uniform_int_distribution<> a(v, x);
	int y = a(gen);

	int damage = 0;
	switch (y)
	{
	case 0:avoid(z);
	break;
	case 1:damage = attack();
		break;
	case 2:damage = specialAttack();
		break;
	case 3:damage = powerFullAttack();
		break;
	}
	return damage;
}
