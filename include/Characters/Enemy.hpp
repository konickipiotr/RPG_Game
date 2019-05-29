#pragma once
#include "ICharacter.hpp"
#include "../Items/IItems.hpp"
#include "../reward.hpp"
#include <memory>


class Enemy :
	public ICharacter
{
	typedef std::shared_ptr<IItems> sI;
public:
	Enemy(std::string _name, int _hp, int _streight, int _stamina, int _lucky, int _gold, int _exp, std::string _nickname = "", sI _item = { nullptr });
	virtual int powerFullAttack();
	virtual int specialAttack();
	virtual void statInfo();
	reward getEnemyReward();
	int enemyAttack(int z);
	std::string getNickname() const { return nickname; }
private:
	int exp;
	int gold;
	sI item{ nullptr };
	std::string nickname;
};

