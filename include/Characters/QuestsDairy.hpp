#pragma once
#include "Quest.hpp"
#include "reward.hpp"
#include <memory>
#include <vector>

typedef std::shared_ptr<Quest> sQ;

class QuestsDairy
{
public:
	
	typedef std::shared_ptr<IItems> sI;
	QuestsDairy();
	reward completeQuest(std::string idS);

	void displayMainCurr();
	void dispalyCurrenQ();
	void dispalyOldQ();
	void dispalyOldMain();
	void dairyMenu();
	QuestStatus checkstatus(std::string idS, unsigned int id = 0);
	std::string statusTostring(std::string ids, int id);
	sQ retuOtherQ(std::string idS);
	void takeQuest(std::string idS);
	void completeMainQuest(int num);
	void completeOtherQuest(std::string idS);
	void toreward(std::string idS);
	void dairyQuests();
	reward RewardForQuest(int num);
	reward RewardForQuest(std::string idS);

private:
	std::vector<sQ>vQuests;
	std::vector<sQ>vMainQuests;
};

