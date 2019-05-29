#include "TawernGame.hpp"
#include <iostream>
#include "GlobFunc.hpp"

TawernGame::TawernGame()
{
}

TawernGame::TawernGame(Player * _player)
{
	player = _player;
}

void TawernGame::startGame()
{
	using namespace std::chrono_literals;
	int pool;
	do {
		pool = choosePool();
		if ((player->getGold() - pool) < 0)
		{
			std::cout << "\t Nie masz tyle pieniedzy" << std::endl;
			GlobFunc::key();
		}
	} while ((player->getGold() - pool) < 0);

	if (pool == 0)
		return;
	player->buyGiveMoney(pool);
	pool *= 2;

	throwAnimation("Przeciwnik");
	std::random_device rd{};
	std::mt19937 gen{ rd() };
	std::uniform_int_distribution<> a(0, 120);
	std::uniform_int_distribution<> b(1, 6);
	
	int random = a(gen);
	int enemyThrow = gameThrow(random);
	GlobFunc::clearScreean();
	std::cout << "\n\t Rzut  Przeciwnik" << std::endl;
	std::cout << "\n\t" << enemyThrow;
	std::this_thread::sleep_for(3s);

	throwAnimation(player->getName());
	random = a(gen);
	random += player->getLucky();
	int playerThrow = gameThrow(random);

	GlobFunc::clearScreean();
	std::cout << "\n\t Rzut "<<player->getName() << std::endl;
	std::cout << "\n\t" << playerThrow;
	std::this_thread::sleep_for(3s);

	GlobFunc::clearScreean();
	heder(pool);
	std::cout << "\tTy: " << playerThrow << " \tvs\tPrzecienik: " << enemyThrow << std::endl;
	if (playerThrow > enemyThrow) {
		std::cout << "\n\tWygrales " << pool << std::endl;
		player->takeMoney(pool);
	}
	else if (playerThrow < enemyThrow) {
		std::cout << "\n\tPrzegrales " << std::endl;
	}
	else if (playerThrow == enemyThrow) {
		std::cout << "\n\tRemis " << std::endl;
		std::cout << "\tZostaj zwrocone "<< pool/2 << std::endl;
		player->takeMoney(pool/2);
	}
	std::cout << std::endl;
	system("pause");


}

int TawernGame::choosePool()
{
	using namespace std;
	do {
		GlobFunc::clearScreean();
		cout << "\tWybierz stawke?" << endl;
		cout << "\t 1. 10 gold" << endl;
		cout << "\t 2. 50 gold" << endl;
		cout << "\t 3. 100 gold" << endl;
		cout << "\t 4. 200 gold" << endl;
		cout << "\t x. Wycofaj sie" << endl;
		GlobFunc::getch();
		char c = GlobFunc::getch();
		switch (c)
		{
		case 49: return 10; break;
		case 50: return 50; break;
		case 51: return 100; break;
		case 52: return 200; break;
		case 'x': return 0; break;
		}

	} while (true);
}

void TawernGame::heder(int pool)
{
	std::cout << "\n\t *** GRA W KOSCI ***\n " << std::endl;
	std::cout << "\tPULA: " << pool << "\t Szczescie: " << player->getLucky() << std::endl;
}

int TawernGame::gameThrow(int random)
{
	

	int gamethrow;
	if (random >= 100) {
		gamethrow = 6;
	}
	else if (random < 100 && random >= 80) {
		gamethrow = 5;
	}
	else if (random < 80 && random >= 60) {
		gamethrow = 4;
	}
	else if (random < 60 && random >= 40) {
		gamethrow = 3;
	}
	else if (random < 40 && random >= 20) {
		gamethrow = 2;
	}
	else if (random < 20 && random >= 0) {
		gamethrow = 1;
	}
	return gamethrow;
}

void TawernGame::throwAnimation(std::string name)
{
	
	std::random_device rd{};
	std::mt19937 gen{ rd() };
	std::uniform_int_distribution<> b(1, 6);
	int random;

	for (int i = 0; i < 20; i++)
	{
		using namespace std::chrono_literals;
		GlobFunc::clearScreean();
		std::cout << "\n\t Rzut " << name << std::endl;
		random = b(gen);
		std::cout << "\n\t" << random;
		std::this_thread::sleep_for(200ms);
	}
}
