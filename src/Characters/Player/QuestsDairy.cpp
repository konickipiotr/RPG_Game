#include "QuestsDairy.hpp"
#include <locale.h>
#include "GlobFunc.hpp"


QuestsDairy::QuestsDairy()
{
	setlocale(LC_ALL, "polish");
	vMainQuests.push_back(sQ(new Quest("main","Gdzie ja jestem", "\tTrafi�e� do nowego kr�lestwa, o kt�rym nic nie wiesz. Odwied� najbli�sz� \n\t\twiosk� i dowiedz sie czego� o okolicy", 0, 0, QuestStatus::CURR)));
	vMainQuests.push_back(sQ(new Quest("main", "Nowy w mie�cie", "W�adca okolicznych ziem, Lorda Arison, szyuka najemnika do pewnego zadania", 0, 0)));
	vMainQuests.push_back(sQ(new Quest("main", "Zabij Bandyt�", "Niebezpieczny bandyta zbieg�a na po�udnie. Odszukaj go i zabije", 100, 0)));
	vMainQuests.push_back(sQ(new Quest("main", "Odbierz nagrode za bandyte", "Wr�c do Lorda Arisona i odbierz nagrode", 100, 100)));
	vMainQuests.push_back(sQ(new Quest("main", "Cmentarz", "Sprawd� co si� dzieje na cmentarzu", 150, 0)));
	vMainQuests.push_back(sQ(new Quest("main", "Wr�c do Lorda Arisona", "Wr�c do maista i z�o� raport Lordowi Arisonowi ", 180, 150)));
	vMainQuests.push_back(sQ(new Quest("main", "Do kr�la", "Przeka� wie�ci kr�lowi", 180, 100)));
	vMainQuests.push_back(sQ(new Quest("main", "Pocz�tek �ledztwa", "Udaj si� do �wi�tynie w eram i dowiedz si� czego� o obecnej sytuacji", 180, 0)));
	vMainQuests.push_back(sQ(new Quest("main", "Wie�a Maga", "Udaj si� do Maga na po�udniowym-wschodzie", 200, 0)));
	vMainQuests.push_back(sQ(new Quest("main", "Archeolog", "Udaj si� do ruin staro�ytnej fortecy i znajd� jakie� \n\t\tinformacje z przeszo�ci", 300, 0)));
	vMainQuests.push_back(sQ(new Quest("main", "Wr�c do Maga", "Wr�� ze staro�ytnym zwojem do Maga", 200, 0)));
	vMainQuests.push_back(sQ(new Quest("main", "Labirynt", "Odszykaj w labiryncie miecz zas�ny przez bog�w", 400, 100)));
	vMainQuests.push_back(sQ(new Quest("main", "Zbroaja Farumana", "Odnajd� staro�ytny pancerz kr�la Farumana", 500, 100)));
	vMainQuests.push_back(sQ(new Quest("main", "Wr�� do maga", "Wr�c ze wszytkimi artefaktami do maga", 300, 0)));
	vMainQuests.push_back(sQ(new Quest("main", "Wr�� do kr�la", "Zdaj raport kr�lowi", 300, 500)));
	vMainQuests.push_back(sQ(new Quest("main", "B�ogos�awie�stow", "Uzyskaj p�ogos�awie�stwo od najwy�szego kap�ana", 2000, 0)));
	vMainQuests.push_back(sQ(new Quest("main", "Ostateczna bitwa", "Pokonaj smoka �niwia�a w ostatecznej bitwi i uratuj �wiat", 0, 0)));

	vQuests.push_back(sQ(new Quest("kur1", "Lotr na moscie", "Na moscie do miasta jakis oprych zasadza sie na podroznych, zastrasza ich i wludza okup. \n\t Pozbadz sie go i wroc do wojta po nagrode. ", 30, 30, sI(new IOthers("srebrny pier�cie�", "srebrny pier�cie�", 40)))));
	vQuests.push_back(sQ(new Quest("kur2", "Zabij wilka", "W okolicy grasuje wyglodnialy wilki i zabija owce chlopom. Zabij wilka i odbierz nagrode", 30, 30)));
	vQuests.push_back(sQ(new Quest("kur3", "Gwozdzie", "W wiosce Kurowo trwaja prace nad budowa nowego spichlerza. \n\tNiestet brakuje im gworzdzi. Kup gworzdzie i przynies je do wojta aby ukonczyc zadanie", 40, 100)));
	vQuests.push_back(sQ(new Quest("arad1", "Ork w okolicy", "W okolicy grasuje ork. Na pewno ma co� waro�ciowego przy sobie", 100, 0)));
	vQuests.push_back(sQ(new Quest("arad2", "Paczka dla Karczmarz", "Dostarcz Karczmarzowi w Eram paczk� przypraw", 100, 100)));
	vQuests.push_back(sQ(new Quest("arad3", "Troll", "Pozb�d� si� trolla ze wschodniego traktu", 100, 100)));
	vQuests.push_back(sQ(new Quest("castle1", "Wilko�ak", "W kr�lewskim borze prawdopodobnie grasuje wilko�ak.\n\t Pozb�d� si� go aby my�liwi byli bezpieczni", 100, 150)));
	vQuests.push_back(sQ(new Quest("castle2", "Skarb w wie�y", "Daleko na p�nocy znajduje si� stara wie�, w k�rej podobno znajduje si� wielkie bogactwo", 100, 250)));
	vQuests.push_back(sQ(new Quest("eram1", "Problemy handlowe", "Da drodze do wschodnich kr�lestw grasuje troll, kt�rey napada pod�nych. \n\t\tPozb�d� si� go aby szlaki handlowe znowy by�y bezpieczne", 100, 150)));
	vQuests.push_back(sQ(new Quest("hadik", "Ksi��e Ciemno�ci", "Wie� Hadik jest regularnie n�kana przez wampira. Udaj sie na stary cmentarz i pozb�d� sie problemy", 100, 150)));
}

reward QuestsDairy::completeQuest(std::string idS)
{
	reward newReward;
	for (auto & i : vQuests)
	{
		if (i->getidS() == idS)
		{
			i->changeStatus(QuestStatus::COMPLETE);
			newReward = RewardForQuest(idS);
		}
	}
	return newReward;
}

void QuestsDairy::displayMainCurr()
{
	dairyMenu();
	std::cout << "\t\t  AKUTALNE ZADANIA" << std::endl;
	std::cout << "\t\t-------------------------: \n" << std::endl;
	std::cout << "\tG��WNE" << std::endl;
	std::cout << "\t------" << std::endl;
	for (auto & i : vMainQuests)
	{
		if (i->getQuestStatus() == QuestStatus::CURR)
		{
			using namespace std;
			cout << "\tTYTU�: " << i->getTitleQ() << endl;
			cout << "\tNagroda: " << i->getReward() << endl;
			cout << "\tOPIS: " << i->getDescripQ() << endl;
			cout << "\t\t-------------------------: " << endl;
		}
	}
}

void QuestsDairy::dispalyCurrenQ()
{
	dairyMenu();
	std::cout << "\t\t  AKUTALNE ZADANIA" << std::endl;
	std::cout << "\t\t-------------------------: \n" << std::endl;
	std::cout << "\tPOBOCZNE" << std::endl;
	std::cout << "\t------" << std::endl;
	for (auto & i : vQuests)
	{
		if (i->getQuestStatus() == QuestStatus::CURR || i->getQuestStatus() == QuestStatus::TOREWARD)
		{
			using namespace std;
			cout << "\tTYTU�: " << i->getTitleQ() << endl;
			cout << "\tNagroda: " << i->getReward() << endl;
			cout << "\tOPIS: " << i->getDescripQ() << endl;
			cout << "\t\t-------------------------: " << endl;
		}
	}
}

void QuestsDairy::dispalyOldQ()
{
	dairyMenu();
	std::cout << "\t\t ZAKONCZONE ZADANIA" << std::endl;
	std::cout << "\t\t-------------------------:" << std::endl;
	std::cout << "\tPOBOCZNE" << std::endl;
	std::cout << "\t------" << std::endl;
	for (auto & i : vQuests)
	{
		if (i->getQuestStatus() == QuestStatus::COMPLETE)
		{
			using namespace std;
			cout << "\tTYTU�: " << i->getTitleQ() <<"  "<<i->stausToString() << endl;
			cout << "\tNagroda: " << i->getReward() << endl;
			cout << "\tOPIS: " << i->getDescripQ() << endl;
			cout << "\t\t-------------------------: " << endl;
		}
	}
}

void QuestsDairy::dispalyOldMain()
{
	dairyMenu();
	std::cout << "\t\t ZAKONCZONE ZADANIA" << std::endl;
	std::cout << "\t\t-------------------------:" << std::endl;
	std::cout << "\tG��WNE" << std::endl;
	std::cout << "\t------" << std::endl;
	for (auto & i : vMainQuests)
	{
		if (i->getQuestStatus() == QuestStatus::COMPLETE)
		{
			using namespace std;
			cout << "\tTYTU�: " << i->getTitleQ() << "  " << i->stausToString() << endl;
			cout << "\tNagroda: " << i->getReward() << endl;
			cout << "\tOPIS: " << i->getDescripQ() << endl;
			cout << "\t\t-------------------------: " << endl;
		}
	}
}

void QuestsDairy::dairyMenu()
{
	GlobFunc::clearScreean();
	std::cout << "\n\t\t *** Dziennik Zada� ***\n\n";
	std::cout << "\tAKTUALNE: \t1) G��wne \t\t2) Poboczne" << std::endl;
	std::cout << "\tZAKO�CZONE: \t3) G��wne \t\t4) Poboczne" << std::endl;
	std::cout << "\tESC - Wyj�cie" << std::endl;
}

QuestStatus QuestsDairy::checkstatus(std::string idS, unsigned int id)
{
	if (idS == "main") {
		for (unsigned int i = 0; i < vMainQuests.size(); i++)
		{
			if (i == id)
			{
				return vMainQuests[i]->getQuestStatus();
			}
		}
	}
	else {

		for (auto & i : vQuests)
		{
			if (i->getidS() == idS)
			{
				return i->getQuestStatus();
			}
		}
	}
}

std::string QuestsDairy::statusTostring(std::string ids, int id)
{
	if ("main" == ids)
		return vMainQuests[id]->stausToString();
	else
		return "";
}

sQ QuestsDairy::retuOtherQ(std::string idS)
{
	sQ nQuest;
	for (auto & i : vQuests)
	{
		if (i->getidS() == idS && i->getQuestStatus() == QuestStatus::INACTIV) {
			nQuest = i;
		}
		else
		{
			nQuest = nullptr;
		}
	}
	
	return nQuest;
}

void QuestsDairy::takeQuest(std::string idS)
{
	for (auto & i : vQuests)
	{
		if (i->getidS() == idS )
		{
			i->changeStatus(QuestStatus::CURR);
			break;
		}
	}
}


void QuestsDairy::completeMainQuest(int num)
{
	if (vMainQuests[num]->getQuestStatus() == QuestStatus::CURR) {
		vMainQuests[num]->changeStatus(QuestStatus::COMPLETE);
		
		if (num < 16) {
			vMainQuests[num + 1]->changeStatus(QuestStatus::CURR);
		}
	}
}

void QuestsDairy::completeOtherQuest(std::string idS)
{
	for (auto & i : vQuests)
	{
		if (i->getidS() == idS)
			i->changeStatus(QuestStatus::COMPLETE);
	}

}

void QuestsDairy::toreward(std::string idS)
{
	for (auto & i : vQuests) {
		if (i->getidS() == idS)
			i->changeStatus(QuestStatus::TOREWARD);
	}
}

void QuestsDairy::dairyQuests()
{
	
	
	char c = 49;
	do {
		switch (c)
		{
		case 27: return; break;
		case 49: displayMainCurr(); break;
		case 50: dispalyCurrenQ(); break;
		case 51: dispalyOldMain(); break;
		case 52: dispalyOldQ(); break;
		}
		c = GlobFunc::getch();
	} while (true);
}

reward QuestsDairy::RewardForQuest(int num)
{
	reward newReward;
	newReward.exp = vMainQuests[num]->getExp();
	newReward.gold = vMainQuests[num]->getReward();
	newReward.rewItem = vMainQuests[num]->getItem();
	return newReward;
}

reward QuestsDairy::RewardForQuest(std::string idS)
{
	reward newReward;
	for (auto & i : vQuests)
	{
		if (i->getidS() == idS)
		{
			newReward.exp = i->getExp();
			newReward.gold = i->getReward();
			newReward.rewItem = i->getItem();
			return newReward;
		}
	}
	return {};
}

