#include <iostream>
#include "userin.h"


static const std::string fail_msg = "Неверный ввод числа!";

void userIn(double& val, const std::string& msg)
{
	std::string in_user = "";
	bool check = false;

	do
	{
		std::cout << msg;
		std::cin >> in_user;
		try
		{
			val = std::stod(in_user);
			check = true;
		}
		catch (std::invalid_argument e)
		{
			std::cout << fail_msg << std::endl;
			check = false;
		}
		
	} while (!check);
}

void userIn(int& val, const std::string& msg)
{
	std::string in_user = "";
	bool check = false;

	do
	{
		std::cout << msg;
		std::cin >> in_user;
		try
		{
			val = std::stoi(in_user);
			check = true;
		}
		catch (std::invalid_argument e)
		{
			std::cout << fail_msg << std::endl;
			check = false;
		}
		
	} while (!check);
}
