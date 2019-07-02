#include"Mine.h"

void Menu()
{
	printf("###########################\n");
	printf("###1.Play         2.Exit###\n");
	printf("###########################\n");
	printf("Please Select:");
}

int main()
{
	int quit = 0;
	int select = 0;
	while (!quit)
	{
		Menu();
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			Game();
			break;
		case 2:
			printf("拜拜！");
			quit=1;
		default:
			printf("选择错误，请重新选择：");
			break;
		}
	}
	system("pause");
	return 0;
}