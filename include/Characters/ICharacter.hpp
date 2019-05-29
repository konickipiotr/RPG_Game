#pragma once
#include <string>
class ICharacter
{
public:
	virtual int powerFullAttack() = 0;
	virtual int specialAttack() = 0;
	virtual void statInfo() = 0;
	void printLogFight();

	int attack();
	void recieveDamage(int damage);
	void avoid(int damage);
	std::string getName()const { return name; };
	int getHp() const { return hp; };
	int getCurrHp() const { return currHp; };
	int getStamina() const { return stamina; };
	int getCurrStamina() const { return currStamina; };
	bool checkDead()const { return death; };

protected:
	bool criticalHit();
	int randomLucky();
	void printLogFight(std::string attackType, int damage, std::string isCritical);
	void printLogAvoid(std::string avoid, int damage, int stram);

	int hp;
	int currHp;
	int streight;
	int attackModify;
	int stamina;
	int currStamina;
	bool death;
	int lucky;
	std::string name;
};

