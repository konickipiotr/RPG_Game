#include "GlobFunc.hpp"
#include <unistd.h>
#include <termios.h>
#include <iostream>

GlobFunc::GlobFunc()
{
}

char GlobFunc::getch()
{
    char buf=0;
    struct termios old={0};
    fflush(stdout);
    if(tcgetattr(0, &old)<0)
        perror("tcsetattr()");
    old.c_lflag&=~ICANON;
    old.c_lflag&=~ECHO;
    old.c_cc[VMIN]=1;
    old.c_cc[VTIME]=0;
    if(tcsetattr(0, TCSANOW, &old)<0)
        perror("tcsetattr ICANON");
    if(read(0,&buf,1)<0)
        perror("read()");
    old.c_lflag|=ICANON;
    old.c_lflag|=ECHO;
    if(tcsetattr(0, TCSADRAIN, &old)<0)
        perror ("tcsetattr ~ICANON");
    return buf;
}

void GlobFunc::pause()
{
	std::cout<<"\tPress any key to continue ...\n";
	std::cin.get();
}

void GlobFunc::clearScreean()
{
    #ifdef WINDOWS
        std::GlobFunc::clearScreean();
    #else
        std::system ("clear");
    #endif
}

void GlobFunc::controlInfo()
{
	std::cout<<"\n\t[w,s,d,a] - sterowanie \t [o] - enter\n";
}

int GlobFunc::controlPanel(const std::vector<std::string>& labels, std::string heder)
{
	std::vector<char> checkBox;
	for (unsigned int i = 0; i < labels.size(); i++)
	{
		checkBox.push_back(' ');
	}

	unsigned int pos = 0;
	do
	{
		GlobFunc::clearScreean();
		if (heder != "") {
			std::cout <<"\n\t\t *** "<< heder<<" *** \n\n";
		}
		
		checkBox.at(pos) = 'X';
		for (unsigned int i = 0; i < labels.size(); i++)
		{
			std::cout << "\t[" << checkBox.at(i) << "]  " << labels.at(i) << std::endl;
		}
		char key;
		GlobFunc::controlInfo();
		key = GlobFunc::getch();

		switch (key)
		{
		case 's':
		{
			if (pos < checkBox.size() - 1)
			{
				checkBox.at(pos) = ' ';
				pos++;
				checkBox.at(pos) = 'X';
			}
		}
		break;
		case 'w':
		{
			if (pos > 0)
			{
				checkBox.at(pos) = ' ';
				pos--;
				checkBox.at(pos) = 'X';
			}
		}
		break;
		case 'o':
		{
			return pos;
		}
		}
	} while (true);
}

void GlobFunc::key()
{
	std::cout << "\n\n\tNcisinij dowony klawisz any kontynuowac..." << std::endl;
	GlobFunc::getch(); GlobFunc::getch();
}

