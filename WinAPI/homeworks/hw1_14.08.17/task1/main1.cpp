/*	Дан файл text.txt, в котором есть текст в кодировке ANSI.Запишите этот
же текст в файл с кодировкой UTF - 8. При работе вам понадобится :
	подключить <codecvt>
	использовать поток wofstream
	дописать две строчки :
		std::locale loc(std::locale::classic(), new
			std::codecvt_utf8<wchar_t>);
		fout.imbue(loc);
*Реализуйте чтение из файла разными способами, например:
	с помощью метода getline;
	с помощью метода read;
	с помощью метода get. */


#include <fstream>
#include <codecvt>
#include <tchar.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "russian");

	std::ifstream ifile("text.txt");
	if (!ifile.is_open())
	{
		return 1;
	}

	std::wofstream ofile("result.txt");

	std::locale loc(std::locale::classic(), new std::codecvt_utf8<wchar_t>);
	ofile.imbue(loc);


	/*char strAnsi[256];
	while (ifile.getline(strAnsi, 256))
	{
		size_t len = mbstowcs(NULL, strAnsi, 0) + 1;
		wchar_t* strUtf = new wchar_t[len];
		mbstowcs(strUtf, strAnsi, len);
		ofile << strUtf << std::endl;
	}*/


	/*ifile.seekg(0, SEEK_END);
	int textAnsiLen = ifile.tellg();
	ifile.seekg(0);

	char* textAnsi = new char[textAnsiLen];
	ifile.read(textAnsi, textAnsiLen);
	size_t len = mbstowcs(NULL, textAnsi, 0) + 1;
	wchar_t* textUtf = new wchar_t[len];
	mbstowcs(textUtf, textAnsi, len);
	ofile << textUtf;
	delete[] textAnsi;*/


	char textAnsi[256];
	while (ifile.get(textAnsi, 256, 0))
	{
		size_t len = mbstowcs(NULL, textAnsi, 0) + 1;
		wchar_t* textUtf = new wchar_t[len];
		mbstowcs(textUtf, textAnsi, len);
		ofile << textUtf;
	}
	

	ifile.close();
	ofile.close();

	return 0;
}