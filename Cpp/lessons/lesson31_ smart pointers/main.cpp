#include <memory>
#include <string>
#include <iostream>
#include <fstream>

void main()
{
	// Inetrface cpp - гуглить
	
	std::cout << "Enter path to the file which you wont to open:";
	std::string filePath;
	std::cin >> filePath;
	

	int operation = 0;
	do
	{
		std::unique_ptr<std::fstream> ifile = std::make_unique<std::fstream>(filePath, std::ios::in);
		std::cout << "Chose operation(0 - exit 1-print 2 - find): ";
		std::cin >> operation;
		switch (operation)
		{
		case 1:
		{
				  while (!ifile->eof())
				  {
					  std::unique_ptr<char[], std::default_delete<char[]>> buf(new char[100]);
					  std::memset(buf.get(), 0, 100);
					  ifile->read(buf.get(), 100);
					  std::cout << buf.get();
				  }
				  break;
		}
		case 2:
		{
				  std::string word;
				  std::cout << "Enter word: ";
				  std::cin >> word;
				  if (!word.empty())
				  {
					  auto begin = std::istreambuf_iterator<char>(*ifile);
					  auto end = std::istreambuf_iterator<char>();
					  auto itr = begin;
					  bool found = false;
					  while (itr != end)
					  {
						  itr = std::find(itr, std::istreambuf_iterator<char>(), word[0]);
						  auto stritr = word.begin();
						  for (; stritr != word.end(); ++stritr, ++itr) {
							  if (itr == end || *stritr != *itr)
							  {
								  break;
							  }
						  }
						  if (stritr == word.end()) {
							  found = true;
							  break;
						  }
					  }
					  if (found)
					  {
						  std::cout << "Woohoo!\n";
					  }
					  else
					  {
						  std::cout << "Not found!\n";
					  }
				  }
				  break;
		}
		default:
			break;
		}
	} while (operation != 0);
}
