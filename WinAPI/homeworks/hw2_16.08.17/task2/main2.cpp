/*	Напишите приложение, которое «угадывает» задуманное пользователем число
от 1 до 100. Для запроса к пользователю используйте окна сообщений.Оформите их
подходящим образом. */

#include <Windows.h>
#include <time.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int)
{
	if (MessageBox(NULL, L"Загадай число от 1 до 100 и я его угадаю!", L"Угадайка", MB_OKCANCEL) == IDOK)
	{
		srand(time(0));
		wchar_t buff[50];
		int botBorder = 1;
		int topBorder = 99;
		int count = 0;
		int number;
		int preBorder;
		int id;

		while(topBorder != 0)
		{
			number = botBorder + rand() % topBorder;
			count++;
			wsprintf(buff, L"Это число больше %i ?", number);
			id = MessageBox(NULL, buff, L"Угадайка", MB_YESNOCANCEL);
			if (id == IDYES)
			{
				preBorder = botBorder;
				botBorder = number + 1;	
				topBorder -= botBorder - preBorder;

			}
			else if (id == IDNO)
			{
				topBorder = number - botBorder;
			}
			else
			{
				return 0;
			}
		}
		wsprintf(buff, L"Это число %i!\nЯ Угадал за %i попыток =)", botBorder, count);
		MessageBox(NULL, buff, L"Угадайка", MB_OK);
	}
	return 0;
}