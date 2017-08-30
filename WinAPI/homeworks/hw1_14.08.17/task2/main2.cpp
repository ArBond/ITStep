/*	Дан текстовый файл karatkevich.txt в кодировке UTF - 8. Найдите длину :
самого длинного слова, а также все такие слова и их количество;
самого короткого слова, а также все такие слова и их количество;
среднюю длину слова.
Выведите полученную информацию в файл в кодировке UTF - 8. */

#include <vector>
#include <fstream>
#include <codecvt>

int main()
{
	std::wifstream ifile("karatkevich.txt");
	if (!ifile.is_open())
	{
		return 1;
	}

	std::wofstream ofile("result.txt");

	std::locale loc(std::locale::classic(), new std::codecvt_utf8<wchar_t>);
	ofile.imbue(loc);
	ifile.imbue(loc);

	std::wstring word;
	std::vector<std::wstring> shortestWords;
	std::vector<std::wstring> longestWords;

	size_t wordsCount = 0;
	size_t allLen = 0;

	size_t maxLen = 1;
	size_t minLen = 256;
	size_t len;

	while (ifile >> word)
	{
		if (word[0] == '-' || word[0] == '*')
		{
			continue;
		}

		len = word.length();
		wordsCount++;
		allLen += len;

		if (maxLen < len)
		{
			maxLen = len;
			longestWords.clear();
			longestWords.push_back(word);
		}
		else if (maxLen == len)
		{
			longestWords.push_back(word);
		}

		if (minLen > len)
		{
			minLen = len;
			shortestWords.clear();
			shortestWords.push_back(word);
		}
		else if (minLen == len)
		{
			shortestWords.push_back(word);
		}
	}

	ofile << L"Самые длинные слова(" << maxLen << L" символов): " << longestWords.size() << L" шт!\n";
	for (auto& it : longestWords)
	{
		ofile << it << std::endl;
	}

	ofile << L"\nСамые короткие слова(" << minLen << L" символов): " << shortestWords.size() << L" шт!\n";
	for (auto& it : shortestWords)
	{
		ofile << it << " ";
	}

	ofile << L"\n\nСредняя длинна слова: " << allLen / float(wordsCount) << L" символов!" << std::endl;


	ifile.clear();
	ofile.close();

	return 0;
}