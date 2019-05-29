#pragma once
#include <string>
#include <iostream>
#include "QuestStatus.hpp"
#include "IOthers.hpp"
#include "IMixture.hpp"
#include "Weapon.hpp"
#include "Armor.hpp"
#include "Helmet.hpp"
#include "Boots.hpp"
#include "Pants.hpp"
#include <memory>

class Quest
{
public:
	using sI = std::shared_ptr<IItems>;
	Quest();
	Quest(std::string _idS, std::string _title, std::string _description, int _exp, int _rew);
	Quest(std::string _idS, std::string _title, std::string _description, int _exp, int _rew, QuestStatus _status);
	Quest(std::string _idS, std::string _title, std::string _description, int _exp, int _rew, sI _item);
	std::string getTitleQ() const { return titleQ; } 
	std::string getDescripQ() const{ return descriptionQ; }
	std::string getidS() const { return idS; }
	int getExp() const { return exp; }
	int getReward() const { return reward; }
	QuestStatus getQuestStatus() const { return status; }
	sI getItem() { return item; };
	std::string stausToString();
	void changeStatus(QuestStatus nStatus);

private:
	std::string titleQ;
	std::string descriptionQ;
	int exp;
	int reward;
	QuestStatus status;
	std::string idS;
	sI item{ nullptr };
};

