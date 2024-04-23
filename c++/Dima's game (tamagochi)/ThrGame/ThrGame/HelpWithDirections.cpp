#include <stdio.h>
#include <stdlib.h>
#include "windows.h"


string fu1nc() 
{
	setlocale(LC_ALL, "rus");
	char Name[MAX_PATH];
	GetModuleFileNameA(NULL, Name, MAX_PATH);
	std::string s = Name;

	if (s.rfind("Debug") != 1)
	{ 
		s.erase(s.rfind("Debug"),s.length()-s.rfind("Debug")); 
	}
	else if (s.rfind("Release") != 1)
	{
		s.erase(s.rfind("Release"), s.length() - s.rfind("Release"));
	}
	else 
	{
		s.erase(s.rfind("\\"),s.length() - s.rfind("\\"));
		s += "\\";
	}
	//s += "ThrGame\\";
	
	return s;

}	