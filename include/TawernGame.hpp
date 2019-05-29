#pragma once
#include "Player.hpp"
#include <random>
#include <chrono>
#include <thread>

class TawernGame
{
public:
	TawernGame();
	TawernGame(Player * _player);
	void startGame();	

private:
	int choosePool();
	void heder(int pool);
	int gameThrow(int random);
	void throwAnimation(std::string name);
	Player * player;
};

