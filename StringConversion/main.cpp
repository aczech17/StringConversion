#include "TemplateFile.h"
using namespace std;
int main()
{
	string inName, outName;
	char repChar;
	cout << "Podaj nazwe pliku wejsciowego: ";
	cin >> inName;
	
	cout << "Podaj nazwe pliku wyjsciowego: ";
	cin >> outName;
	
	cout << "Podaj znak oznaczajacy slowa do zastapienia: ";
	cin >> repChar;

	TemplateFile file(inName, outName, repChar);
	if (!file.good())
	{
		cerr << "Blad otwarcia pliku."<<endl;
	}
	file.loadFile();
}