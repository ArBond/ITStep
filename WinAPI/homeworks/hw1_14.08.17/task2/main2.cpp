/*	��� ��������� ���� karatkevich.txt � ��������� UTF - 8. ������� ����� :
������ �������� �����, � ����� ��� ����� ����� � �� ����������;
������ ��������� �����, � ����� ��� ����� ����� � �� ����������;
������� ����� �����.
�������� ���������� ���������� � ���� � ��������� UTF - 8. */

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

	ofile << L"����� ������� �����(" << maxLen << L" ��������): " << longestWords.size() << L" ��!\n";
	for (auto& it : longestWords)
	{
		ofile << it << std::endl;
	}

	ofile << L"\n����� �������� �����(" << minLen << L" ��������): " << shortestWords.size() << L" ��!\n";
	for (auto& it : shortestWords)
	{
		ofile << it << " ";
	}

	ofile << L"\n\n������� ������ �����: " << allLen / float(wordsCount) << L" ��������!" << std::endl;


	ifile.clear();
	ofile.close();

	return 0;
}