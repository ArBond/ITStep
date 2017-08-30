#include <fstream>
#include <iostream>
#include <string>
#include <tchar.h>

int main()
{
	//		ОТХОДИМ ОТ КАНИКУЛ

	/*std::ifstream ifile("lopatin.txt");
	if (!ifile.is_open())
	{
		return 1;
	}

	int letterCount;
	std::cout << "How many letters you want?\n";
	std::cin >> letterCount;

	std::ofstream ofile("result.txt", std::ios::trunc);

	std::string str;
	std::string arrVowels("аяоёуюиыэе");

	while (std::getline(ifile, str))
	{
		if (str.length() == letterCount)
		{
			int vowelsCount = 0;
			for (int i = 0; i < str.length(); ++i)
			{
				for (int j = 0; j < arrVowels.length(); ++j)
				{
					str[i] == arrVowels[j] ? vowelsCount++ : 0;
				}
			}
			if (vowelsCount == 2)
			{
				ofile << str << std::endl;
			}
		}
	}
	ifile.close();
	ofile.close();*/


	/*wchar_t c;
	std::wstring str1 = L"abacaba";
	std::wcout << str1;

	TCHAR* str2 = L"abacaba";
	TCHAR* str3 = _TEXT("abacaba");*/

	char str1[] = "string";
	size_t len = mbstowcs(NULL, str1, 0) + 1;
	wchar_t* str2 = new wchar_t[len];
	mbstowcs(str2, str1, len);
	std::wcout << str2 << std::endl;

	len = wcstombs(NULL, str2, 0) + 1;
	char* str3 = new char[len];
	wcstombs(str3, str2, len);
	std::cout << str3 << std::endl;

	return 0;
}
