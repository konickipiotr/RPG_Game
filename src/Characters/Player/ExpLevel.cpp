#include "ExpLevel.hpp"
#include <iostream>
#include "GlobFunc.hpp"

ExpLevel::ExpLevel()
{
	level = 1;
	exp = 0;
	next_Level = 50;
	skillPoints = 0;
}

void ExpLevel::addExp(int _exp)
{
	exp += _exp;
	while(exp>= next_Level){
		level++;
		nextLevelCalc();
		skillPoints += 5;
		newLeveScreen();
	}
}


void ExpLevel::newLeveScreen()
{
	using namespace std;
	GlobFunc::clearScreean();
	std::cout << "\n\n\t\t *** !!! NOWY POZIOM *** \n\n";
	std::cout << "\t\t\tPoziom: " << level << std::endl;
	std::cout << "\t Otw�rz okno postaci i przydziel punkty";
	GlobFunc::key();
}

void ExpLevel::useSkillPoint()
{
	if (skillPoints > 0)
		skillPoints--;
}

void ExpLevel::displeyLeveInfo()
{
	using namespace std;
	cout << "\t Poziom: " << level << endl;
	cout << "\t Do�wiadczenie: "<<exp<<" \t Nowy poziom: "<<next_Level << endl;
}

void ExpLevel::nextLevelCalc()
{
	next_Level += next_Level+ next_Level * 0.3;
}
