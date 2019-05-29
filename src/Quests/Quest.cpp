#include "Quest.hpp"
Quest::Quest()
	: titleQ{ "Title01" }, descriptionQ{ "description" }, exp{ 100 }, reward{100}
{
	status = QuestStatus::INACTIV;
	
}

Quest::Quest(std::string _idS, std::string _title, std::string _description, int _exp, int _rew)
	: titleQ{ _title }, descriptionQ{ _description }, exp{ _exp }, reward{_rew}, idS{_idS}
{
	status = QuestStatus::INACTIV;
}

Quest::Quest(std::string _idS, std::string _title, std::string _description, int _exp, int _rew, QuestStatus _status )
	: titleQ{ _title }, descriptionQ{ _description }, exp{ _exp }, reward{ _rew }, idS{ _idS }
{
	status = _status;
}

Quest::Quest(std::string _idS, std::string _title, std::string _description, int _exp, int _rew, sI  _item)
	: titleQ{ _title }, descriptionQ{ _description }, exp{ _exp }, reward{ _rew }, idS{ _idS }, item{_item}
{
	status = QuestStatus::INACTIV;
}

std::string Quest::stausToString()
{
	switch (status)
	{
	case QuestStatus::CURR: return "CURR"; break;
	case QuestStatus::COMPLETE: return "COMPLETE"; break;
	case QuestStatus::INACTIV: return "INACTIV"; break;
	}
}

void Quest::changeStatus(QuestStatus nStatus)
{
	switch (nStatus)
	{
	case QuestStatus::CURR: status = QuestStatus::CURR;
		break;
	case QuestStatus::COMPLETE: status = QuestStatus::COMPLETE;
		break;
	case QuestStatus::INACTIV: status = QuestStatus::INACTIV;
		break;
	case QuestStatus::TOREWARD: status = QuestStatus::TOREWARD;
		break;
	}
}

