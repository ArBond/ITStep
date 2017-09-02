/*	�������� ����������, ������� ���������� ���������� ������������� �����
�� 1 �� 100. ��� ������� � ������������ ����������� ���� ���������.�������� ��
���������� �������. */

#include <Windows.h>
#include <time.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int)
{
	if (MessageBox(NULL, L"������� ����� �� 1 �� 100 � � ��� ������!", L"��������", MB_OKCANCEL) == IDOK)
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
			wsprintf(buff, L"��� ����� ������ %i ?", number);
			id = MessageBox(NULL, buff, L"��������", MB_YESNOCANCEL);
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
		wsprintf(buff, L"��� ����� %i!\n� ������ �� %i ������� =)", botBorder, count);
		MessageBox(NULL, buff, L"��������", MB_OK);
	}
	return 0;
}