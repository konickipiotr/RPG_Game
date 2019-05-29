#pragma once
#include <locale.h>
#include <iostream>
#include <string>
#include "Player.hpp"
using namespace std;

class QTexts
{
public:
	QTexts();
	QTexts(Player * _player);
	~QTexts();
	void helper();
	void nomore();
	void m1();
	void m2();
	void m3();
	void m4();
	void m5();
	void m6();
	void m7();
	void m8();
	void m85();
	void m9();
	void m10();
	void m11();
	void m12();

	void kur1();
	void kur2();
	void kur3();

	void arad1();
	void arad2();


	void castle1();
	void castle2();

	void eram();

	void hadi();

private:
	Player * player;
};

