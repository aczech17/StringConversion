#include "TemplateFile.h"
TemplateFile::TemplateFile(std::string iN, std::string oN, const char tS) : inputName(iN), outputName(oN), templateSign(tS)//currentword.file == this
{
	input.open(inputName);
	output.open(outputName);
	inTemplate = 0;
}

TemplateFile::~TemplateFile()
{
	input.close();
	output.close();
}

void TemplateFile::loadWord()
{
	input >> word;
	if (word[0] == templateSign)
	{
		inTemplate = 1;
	}
	if (inTemplate)
	{
		replaceableWords.push_back(word);//dodajemy to s³owo do wektora s³ów znajduj¹cych siê w szablonie
	}
	else//zwyk³e s³owo, a nie szablon
	{
		output << word;
	}
	if (word[word.size() - 1] == templateSign)
	{
		inTemplate = 0;
		replace();
	}
}

void TemplateFile::replace()
{
	std::cout << "Podaj ";
	for (unsigned short i = 0; i < replaceableWords.size(); i++)
	{
		std::cout << replaceableWords[i];
	}
	while (!replaceableWords.empty())
		replaceableWords.pop_back();
	std::cout << ": ";
	std::string replacingWords;
	getline(std::cin, replacingWords);
	output << replacingWords;
}

void TemplateFile::loadFile()
{
	while (!input.eof())
	{
		loadWord();
	}
}