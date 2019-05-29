#include <iostream>
#include "Mapa.hpp"
#include "GlobFunc.hpp"
#include <vector>
int main()
{
	int x = 0;
	std::vector<std::string> labels{ "Nowa gra", "Wyjscie" };
	do {
		x = GlobFunc::controlPanel(labels, "RPG GAME");
		if (x == 0) {
			std::string name;
			GlobFunc::clearScreean();
			std::cout << "\n\n\t Podaj swoje imie: ";
			std::cin >> name;
			GlobFunc::clearScreean();
			Mapa m(name);
			m.displayMap();
		}
	} while (x != 1);
	return 0;

}