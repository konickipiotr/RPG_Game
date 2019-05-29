#include "MixtureBelt.hpp"
#include "GlobFunc.hpp"
#include <iostream>
#include <algorithm>
#include <vector>

MixtureBelt::MixtureBelt()
{
	mixtureBelt.reserve(3);

}

void MixtureBelt::addToBelt(uqMix toAddMix)
{
	if (mixtureBelt.size() < 3)
	{
		mixtureBelt.push_back(toAddMix);
	}
	else 
	{
		std::cout << "Nie ma wolnego miejsca dla tej mikstury" << std::endl;
	}
}

void MixtureBelt::removeFromBelt(const int & num)
{
	mixtureBelt.erase(mixtureBelt.begin() + num);
}


uqMix MixtureBelt::displayBelt()
{
	int x = -1;
	do {
		std::vector<std::string> mix{ "    EMPTY         ","    EMPTY         ", "    EMPTY         " };
		if (!mixtureBelt.empty()) {
			for (unsigned int i = 0; i < mixtureBelt.size(); ++i)
			{
				mix.at(i) = mixtureBelt.at(i)->getName();
			}
		}

		uqMix temp{ nullptr };
		x=graph(mix);
		if (x == -1)
			return temp;
		
		temp = mixtureBelt[x];
		mixtureBelt.erase(mixtureBelt.begin() + x);
		mix.erase(mix.begin() + x);
		return temp;
	} while (true);
	
}

int MixtureBelt::graph(std::vector<std::string> & mix)
{
	std::string cursor = "       _/\\_       ";
	std::vector<std::string> ctrl { "                  ", "                  ", "                  " };
	
	using namespace std;
	unsigned int pos = 0;
	do
	{
		for (unsigned int i = 0; i < ctrl.size(); ++i)
			ctrl.at(i) = "                  ";
		
		GlobFunc::clearScreean();
		ctrl.at(pos) = cursor;
		cout << "\t----------------------------------------------------------------" << endl;
		cout << "\t\t\t\t MIXTURES BELT " << endl;
		cout << "\t----------------------------------------------------------------" << endl;
		cout << "\t|" << mix.at(0) << " | " << mix.at(1) << " | " << mix.at(2) << " |" << endl;
		cout << "\t----------------------------------------------------------------" << endl;
		cout << "\t|";
		for (unsigned int i = 0; i < ctrl.size(); ++i)
		{
			cout << ctrl.at(i) << " | ";
		}
		cout << endl;
		cout << "\t----------------------------------------------------------------" << endl;

		char ch = GlobFunc::getch();

		switch (ch)
		{
		case 'd':
		{
			if (pos < ctrl.size() - 1)
			{
				ctrl.at(pos) = "                  ";
				pos++;
				ctrl.at(pos) = "       _/\\_       ";
			}
		}
		break;
		case 'w':
		{
			if (pos > 0)
			{
				ctrl.at(pos) = "                  ";
				pos--;
				ctrl.at(pos) = "       _/\\_       ";
			}
		}
		break;
		case 'o':
		{
			if (mix.at(pos) != "    EMPTY         ") {
				return pos;
			}
		}
		break;
		case 27:
		{
			return -1;
		}
		break;
		}

	} while (true);

}
