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
	bool goodbit;
	const char templateSign;
	std::string word;
	void loadLine();
	void replace(int from, int to);
public:
	void loadFile();
	TemplateFile(std::string iN, std::string oN, char tS = '*');
	~TemplateFile();
	bool good();
};
#endif