#include"contact.h"
void menu()
{
	printf("                                                                 \n");
	printf("#################################################################\n");
	printf("############################ͨ Ѷ ¼#############################\n");
	printf("-----------------------------------------------------------------\n");
	printf("  1,�����ϵ����Ϣ                            2��ɾ����ϵ����Ϣ  \n");
	printf("  3,������ϵ����Ϣ                            4����ʾ��ϵ����Ϣ  \n");
	printf("  5,�����ϵ����Ϣ                            6���ݻ���ϵ����Ϣ  \n");
	printf("-----------------------------------------------------------------\n");
	printf("               ��    ��    ��    ��    0    ��                   \n");
	printf("#################################################################\n");
	printf("���������ѡ�񣺣�0~9��                                         \n");
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