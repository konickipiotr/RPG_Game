#pragma once	
#include "Arena.hpp"
#include "Place.hpp"
#include "KurowoVillage.hpp"
#include "AradTown.hpp"
#include "DrawMap.hpp"
#include "KingsCastle.hpp"
#include "HadikVillage.hpp"
#include "Eram.hpp"
#include "HarpyTower.hpp"
#include "Labyrinth.hpp"
#include "OldFortress.hpp"
#include "MagTower.hpp"
#include "Pyramid.hpp"
#include "Quests/QTexts.hpp"
#include "GlobFunc.hpp"
#include "Player.hpp"
#include <memory>


class Mapa
{
public:
	Mapa();
	Mapa(std::string name);
	void displayMap();
	void visitPlace(std::shared_ptr<Place> plac);
	void newPlace(int x, int y, std::shared_ptr<Place> & nPlace);
	void ArenaPlace(const int & posX, const int & posY, int v, int h);
	void checkQuestComplete();
	void winGame();
	//void idzdoxy(int x, int y);
	void playerlose();

	//private:
	int posX;
	int posY;
	char playerPos;
	char m[70][25];
	bool gameOver{ false };

	Player player;
	DrawMap drawmap;
	QTexts qt;
};

