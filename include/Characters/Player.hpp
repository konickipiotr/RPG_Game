#pragma once
#include <string>
#include "ICharacter.hpp"
#include "ExpLevel.hpp"
#include "Equipment.hpp"
#include "reward.hpp"
#include "QuestsDairy.hpp"


class Player
	: public ICharacter
{
	typedef std::shared_ptr<IItems> sI;
public:
	Player();
	Player(std::string _name);
	~Player();

	virtual int powerFullAttack();
	virtual int specialAttack();
	virtual void statInfo();
	void updateParamtres();
	typedef int (Player::*wskAttak)();
	void equipment();
	void completeQuest(std::string idS);
	int statictiControl();
	void win(reward & r);
	void addItem(sI & _item);
	int getGold() { return gold; }
	int getLucky() const { return lucky; }
	void buyGiveMoney(int price);
	void takeMoney(int price) { gold += price; }
	void addnickname(std::string _nickname);
	std::string getNickname();
	void setCurrStam(int value);
	void setCurrHP(int value);
	void addToAttakModif(int value) { attackModify += value; }
	
	
	ExpLevel levelInfo;
	Equipment equi;
	QuestsDairy qdairy;
private:
	int armor;
	int basicHp;
	int gold;
	std::vector<std::string>nickname{"podroznik"};
};

