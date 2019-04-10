#ifndef FILETEMPLATE
#define FILETEMPLATE
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
class TemplateFile
{
	std::string inputName;
	std::string outputName;
	std::ifstream input;
	std::ofstream output;
	const char templateSign;
	std::string word;
	bool inTemplate;
	std::vector <std::string> replaceableWords;
	void loadWord();
	void replace();
public:
	void loadFile();
	TemplateFile(std::string iN, std::string oN, const char tS = '*');
	~TemplateFile();
};
#endif