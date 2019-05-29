#pragma once
#include "Player.hpp"
#include "Enemy.hpp"
#include "reward.hpp"
#include "IItems.hpp"
#include <vector>
#include <functional>
#include <memory>



class Arena
{
	typedef std::shared_ptr<IItems> sI;
public:
	Arena(Player * _player, int x, int y);
	int fight();
	void showInfo();
	void statisticBar(int value, int currVal);
	int menuControl(std::vector<std::string>& labels);
	int pAttack(Player::wskAttak wskAtt = nullptr);
	std::shared_ptr<Enemy> chooseEnemy(int x, int y);
	void playerWin();
	bool enoughEnergy(int x);
	void fillCheckBox(std::vector<char> & checkBox, const int & size );
	void displayFightOption(std::vector<char> & checkBox, const std::vector<std::string>& labels);
	void keyChoose(std::vector<char> & checkBox, unsigned int & pos, int direct);

	Player::wskAttak wskAtt{ nullptr };
	Player * player;
	std::shared_ptr<Enemy> enemy;
};

