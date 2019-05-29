#pragma once
#include <memory>
#include <vector>
#include "Items/IItems.hpp"
#include "Player.hpp"
#include <string>

typedef std::shared_ptr<IItems> sI;
class Shop
{
	
public:
	Shop();
	Shop(Player ** _player, std::string _name, ItemType itemT, int nrshop);

	int controlPanel(const std::vector<std::string> & labels);
	void displayScreen();
	void infoScreen();
	bool checkPlayerMoney(int idItem);
	int findPosition(int idItem);
	sI buy(int pos);
	void sell(int pos);
	void itemArmor(int nrshop);
	void itemWeapon(int nrshop);
	void itemMixture(int nrshop);
	void itemOther(int nrshop);
private:
	std::vector<sI> vItems;
	std::string name;
	Player * player;
	ItemType shopType;
};

