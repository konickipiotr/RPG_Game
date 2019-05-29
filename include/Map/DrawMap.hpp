#pragma once
#include "Player.hpp"
struct xyStruct { int x; int y; };


class DrawMap
{
public:
	DrawMap();
	DrawMap(Player * _player);
	void winBattlePlace(char m[70][25], int _x, int _y );
	void upadateMap(char m[70][25]);
	void draw(char m[70][25]);
	void drawAll(char m[70][25]);
	void unlockMap(int x, std::string idS = "main" );
	void showMainQuests(char m[70][25]);
	void showOtherQuests(char m[70][25]);

	void MQ1(char m[70][25]);
	void MQ2(char m[70][25]);
	void MQ3(char m[70][25]);
	void MQ4(char m[70][25]);
	void MQ5(char m[70][25]);
	void MQ6(char m[70][25]);
	void MQ7(char m[70][25]);
	void MQ8(char m[70][25]);
	void MQ9(char m[70][25]);
	void MQ10(char m[70][25]);
	void MQ11(char m[70][25]);


	void OQ1(char m[70][25]);
	void OQ2(char m[70][25]); //wilcza jama
	void OQ3(char m[70][25]); // ork
	void OQ4(char m[70][25]);	 //wilkolak
	void OQ6(char m[70][25]); //grota trola
	void OQ5(char m[70][25]); //wiezaHarpi
	void OQ7(char m[70][25]); //smok
	void OQ8(char m[70][25]); //wampir
	void OQ9(char m[70][25]); //wampir
	Player * player;
	xyStruct xy;
	std::vector<xyStruct> coord{};
	std::vector<int>completeMainQuest;
	std::vector<int>completeOthersQuest;

	void(DrawMap::*funkcje[11])(char m[70][25]);
	void(DrawMap::*others[9])(char m[70][25]);
	void addFuncMap();


};
