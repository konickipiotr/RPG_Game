#include "ICharacter.hpp"
#include <random>
#include <iostream>
#include <string>


int ICharacter::attack()
{

	int mstamina = 10;
	std::string isCritical = "  ";
	int hit = 0;
	if ((currStamina - mstamina) >= 0){
		currStamina -= mstamina;
		
		if (criticalHit()){
			isCritical = "!! Critical Hit !!";
			hit = 2 * streight + attackModify;
		}
		else {
			hit = streight + attackModify;
		}

		printLogFight(" Zwykly atak  ", hit, isCritical);

		
		return hit;
	}
	else
		return 0;
}

bool ICharacter::criticalHit(){
	int x = randomLucky();
	if (x >= 90)
		return true;
	else
		return false;
}

void ICharacter::recieveDamage(int damage)
{
	if ((currHp - damage) <= 0) {
		currHp = 0;
	}
	else {
		currHp -= damage;
	}

	if (currHp <= 0)
		death = true;
}

void ICharacter::avoid(int damage)
{
	std::string avoid;
	
	int lucky = randomLucky();
	float mnoznik;
	int stam = 0;
	if (lucky >= 80) {
		damage = 0;
		recieveDamage(damage);
		mnoznik = 0.5;
		avoid = "Perfekcyjny unik";
	}
	else if (lucky > 40 && lucky < 80) {
		damage /= 2;
		recieveDamage(damage);
		mnoznik  = 0.4;
		avoid = "Slaby unik";
	}
	else if(lucky <= 40){
		recieveDamage(damage);
		mnoznik = 0.2;
		avoid = "Fatalny unik";
	}

	if ((currStamina + (stamina * mnoznik))>stamina)
	{
		currStamina = stamina;
	}
	else
	{
		stam = stamina * mnoznik;
		currStamina += stam;
	}
	
	printLogAvoid(avoid, damage, stam);

}

int ICharacter::randomLucky()
{
	std::random_device rd{};
	std::mt19937 gen{ rd() };
	std::uniform_int_distribution<> a(0, 100);
	return a(gen) + lucky;
}

void ICharacter::printLogFight(std::string attackType, int damage , std::string isCritical)
{
	using namespace std;
	cout << "\n\t\t----------------------------------------" << endl;
	cout << "\t\t              "<<isCritical<< endl;
	cout << "\t\t            "<<this->name <<": "<<attackType<< endl;
	cout << "\t\t               OBRAZENIA: "<<damage<< endl;
	cout << "\t\t----------------------------------------" << endl;
}

void ICharacter::printLogAvoid(std::string avoid, int damage,int stam)
{
	using namespace std;
	cout << "\n\t\t----------------------------------------" << endl;
	cout << "\t\t            " << avoid << endl;
	cout << "\t\t      Odzyskana eneria: " << stam << endl;
	cout << "\t\t             OBRAZENIA: " << damage << endl;
	cout << "\t\t----------------------------------------" << endl;
}


