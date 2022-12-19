#include <iostream>
#include "userin.h"


class ForbiddenLengthException : public std::exception
{
	public:
		const char* what() const override
		{
			return "Вы ввели слово запрещенной длины! До свидания.";
		}
};

int lengthStr(std::string str, int forbidden_length)
{
	//int current_length = str.length();
	
	size_t len = 0;

 	for (size_t i = 0; i < str.size(); i++) len += ((str[i] & 0xc0) != 0x80);

	int current_length = static_cast<int>(len);

	if (current_length == forbidden_length)
	{
		throw "Вы ввели слово запрещенной длины! До свидания.";
	}

	return current_length;
}

int main()
{
	const std::string lable_forbidden_length = "Введите запретную длину: ";
	const std::string lable_word = "Введите слово: ";
	const std::string lable_length_word = "Длина слова ";
	const std::string lable_equal = " равна ";

	std::string row = "";
	int forbidden_length = 0;
	int current_length = 0;

	userIn(forbidden_length, lable_forbidden_length);

	try
	{
		while (forbidden_length != current_length)
		{
			std::cout << lable_word;
			std::getline(std::cin, row);

			current_length = lengthStr(row, forbidden_length);

			std::cout << lable_length_word << "\"" << row << "\"" << 
				lable_equal << current_length << std::endl;
		}
	}
	catch (ForbiddenLengthException& err)
	{
		std::cout << err.what() << std::endl;
	}

	return 0;
}
