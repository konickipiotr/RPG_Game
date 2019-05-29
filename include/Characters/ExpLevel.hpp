#pragma once
class ExpLevel
{
public:
	ExpLevel();
	void addExp(int _exp);
	int getLevel() const { return level; }
	int getExp() const { return exp; }
	int next_level() const { return next_Level; }
	int getSkilPoints() const { return skillPoints; }
	void newLeveScreen();
	void useSkillPoint();
	void displeyLeveInfo();

private:
	void nextLevelCalc();

	int level;
	int exp;
	int next_Level;
	int skillPoints;
};

