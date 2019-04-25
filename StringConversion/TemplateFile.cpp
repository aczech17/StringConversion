#include "TemplateFile.h"
TemplateFile::TemplateFile(std::string iN, std::string oN, char tS) : inputName(iN), outputName(oN), templateSign(tS)//currentword.file == this
{
	goodbit = 1;
	input.open(inputName);
	if (!input.good())
	{
		goodbit = 0;
	}
	output.open(outputName);
	if (!output.good())
	{
		goodbit = 0;
	}
}

TemplateFile::~TemplateFile()
{
	input.close();
	output.close();
}

void TemplateFile::loadLine()
{
	getline(input, word);
	std::cin.ignore();
	int i = 0;
	int j = 0;
	while (j < word.size())
	{
		while (word[i] != templateSign)
		{
			output << word[i];
			if (i + 1 < word.size())
			{
				i++;
				j++;
			}
			else
			{
				output << std::endl;
				return;
			}
		}
		j++;
		while (word[j] != templateSign && i<word.size())
		{
			j++;
		}
		replace(i, j);
		if(j+1<word.size()) i = j + 1;
		else
		{
			output << std::endl;
			return;
		}
		j = i;
	}
}

void TemplateFile::replace(int from, int to)
{
	std::cout << "Podaj ";
	for (int i = from + 1; i <= to - 1; i++)
	{
		std::cout << word[i];
	}
	std::string newString;
	getline(std::cin, newString);
	output << newString;
	std::cout << std::endl;
}

void TemplateFile::loadFile()
{
	while (!input.eof())
	{
		loadLine();
	}
}

bool TemplateFile::good()
{
	if (goodbit == 0)
		this->~TemplateFile();
	return goodbit;
}