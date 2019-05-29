#include "Pyramid.hpp"

Pyramid::Pyramid()
{
}

Pyramid::Pyramid(Player *_player, std::string idS, DrawMap * _drawmap, QTexts * _qt)
	:Place(_player, idS, _drawmap, _qt)
{
}

void Pyramid::displayMainMenu()
{
	
	if (player->qdairy.checkstatus("main", 12) == QuestStatus::CURR) {
		if (player->equi.backpack.checkFreeSlots() < 4) {
			std::cout << "Potrzebujesz 4 miesc w plecaku" << std::endl;
			system("pause");
			GlobFunc::clearScreean();
			return;
		}
		GlobFunc::clearScreean();
		cout << "\n\t\t ***PIRAMIDA ***\n";
		cout << "\n\tPod��aj�c w�skim i niskim korytarzem, dostajesz sie w ko�cu\n\tdo komory grobowej. Nigdzie nie wida� zbroji. Jest tu tylko\n\twielki sarkowfag. \n\tLedwie udaje Ci sie przesn�� ci�k� kamienn� p�yt� sarkofagu. \n\tZagl�dasz do �rodka i ... jest. \n\tJeste� zmuszony �ci�gn�� zbroj� z mumii staro�ytnego kr�la.";
		GlobFunc::key();

		std::shared_ptr<IItems> acietnArmor(new Armor(  "Starozytna Zbroja ", "przepowiednia", 1000,500));
		std::shared_ptr<IItems> acientHelmet(new Helmet("Starozytny helm   ", "przepowiednia", 1000,150));
		std::shared_ptr<IItems> acientBoots(new Boots(  "Starozytne buty   ", "przepowiednia", 1000,120));
		std::shared_ptr<IItems> acientPants(new Pants(  "Starozytne spodnie", "przepowiednia", 1000,150));
		player->addItem(acietnArmor);
		player->addItem(acientHelmet);
		player->addItem(acientBoots);
		player->addItem(acientPants);
	}
	bool found = player->equi.backpack.findItem( "Starozytna Zbroja ", ItemType::Armor);
	bool found1 = player->equi.backpack.findItem("Starozytny helm   ", ItemType::Armor);
	bool found2 = player->equi.backpack.findItem("Starozytne buty   ", ItemType::Armor);
	bool found3 = player->equi.backpack.findItem("Starozytne spodnie", ItemType::Armor);


	
	if ((found)&& (found1) && (found2) && (found3))
	{
		player->qdairy.completeMainQuest(12);
	}

}
