#include "OldFortress.hpp"

OldFortress::OldFortress()
{
}


OldFortress::OldFortress(Player *_player, std::string idS, DrawMap * _drawmap, QTexts * _qt)
	:Place(_player, idS, _drawmap, _qt)
{
}

void OldFortress::displayMainMenu()
{
	GlobFunc::clearScreean();
	if (player->qdairy.checkstatus("main", 9) == QuestStatus::CURR) {
		std::shared_ptr<IItems> oldScroll(new IOthers("Stary zw�j", "przepowiednia", 0));
		player->addItem(oldScroll);
	}
	GlobFunc::clearScreean();
	bool found = player->equi.backpack.findItem("Stary zw�j        ", ItemType::Othres);
	if (found == true)
	{
		player->qdairy.completeMainQuest(9);
	}

	cout << "\n\tCa�y dzie� bezskutecznie przeszukujesz ruiny starej fortecy, gdy nagle \n\tpromienie zachodz�cego s�o�ca roz�witalaj� ma�� szczeline w �cienia.\n\tZa �cian� znajduje si� ma�e pomieszczenie.\n\tRozwalasz star� krusz�c� si� �cianie i w odkrytym pomieszczeniu \n\twidziesz ma�a skrzynk�, w kt�rej znajduje si� zw�j zapisany w nieznanym Ci jezyku. " << endl;
	GlobFunc::key();
	GlobFunc::clearScreean();
}
