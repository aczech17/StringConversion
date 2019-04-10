#include "TemplateFile.h"
using namespace std;
int main()
{
	TemplateFile file1("input.txt", "output.txt");
	file1.loadFile();
}