#pragma once
#include <vector>
#include <iostream>
#include <string>
class GlobFunc
{
public:
	GlobFunc();
	static int controlPanel(const std::vector<std::string> & labels, std::string heder="");
	static void key();
	static char getch();
	static void pause();
	static void clearScreean();
	static void controlInfo();
};

