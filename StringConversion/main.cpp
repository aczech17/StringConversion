#include "TemplateFile.h"
int main()
{
	TemplateFile file1("input.txt", "output.txt");
	file1.loadFile();
}