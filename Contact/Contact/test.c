#include"contact.h"
void menu()
{
	printf("                                                                 \n");
	printf("#################################################################\n");
	printf("############################通 讯 录#############################\n");
	printf("-----------------------------------------------------------------\n");
	printf("  1,添加联系人信息                            2，删除联系人信息  \n");
	printf("  3,查找联系人信息                            4，显示联系人信息  \n");
	printf("  5,清空联系人信息                            6，摧毁联系人信息  \n");
	printf("-----------------------------------------------------------------\n");
	printf("               退    出    请    按    0    ！                   \n");
	printf("#################################################################\n");
	printf("请输入你的选择：（0~9）                                         \n");
}

int main()
{
	int input = 1;
	Contact con;
	InitContact(&con);
	do{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case EXIT:
			break;
		case ADD:AddContact(&con);
			break;
		case DEL:DelContact(&con);
			break;
		case SEAR:SearchContact(&con);
			break;
		case SHOW:ShowContact(&con);
			break;
		case CLEAR:ClearContact(&con);
			break;
		case DESTORY:DestoryContact(&con);
			break;
		default:
			break;
		}
	} while(input);
	system("pause");
	return 0;
}