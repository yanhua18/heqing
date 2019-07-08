#include"contact.h"
//在初始化前，加载文件中存储的内容
void LoadContact(Contact *pcon)
{
	FILE *pf = fopen("Contact.bat", "rb");
	PersonInfo tmp = { 0 };
	if (pf == NULL)
	{
		return;
	}
	//fread这个函数的返回值是读取成功的字节数
	while(fread(&tmp, sizeof(PersonInfo), 1, pf)>0)
	{
		CheckFullAndRe(pcon);//从文件中读取到per中，必须判断是否为满（即从文件中读取的个数是否比capacity大，如果大，则需要扩容）
		pcon->per[pcon->usedsize++] = tmp;
	}
	fclose(pf);
	pf = NULL;
}
//初始化通讯录**************************************************
void InitContact(Contact *pcon)
{
	pcon->usedsize = 0;//将结构体变量中的usedsize初始化为0
	pcon->capacity = DEFAULT_SIZE;
	pcon->per = (PersonInfo *)malloc(sizeof(PersonInfo)*pcon->capacity);
	assert(pcon->per != NULL);
	LoadContact(pcon);
}
//返回值代表是否扩容成功
static int CheckFullAndRe(Contact *pcon)//在初始化时需要判断是否已经满了(>capacity),满了则需要realloc来进行扩容
{
	PersonInfo *ptr;//定义一个临时变量，防止realloc申请空间失败导致pcon->per所指向的目标丢失
	if (pcon->usedsize == pcon->capacity)
	{
		ptr = (PersonInfo *)realloc(pcon->per, sizeof(PersonInfo)*pcon->capacity * 2);
		if (ptr != NULL)
		{
			pcon->per = ptr;
			pcon->capacity *= 2;//扩容后容量变为原来的两倍
			printf("扩容已经成功！\n");
			return 1;
		}
		else
		{
			return 0;//扩容失败
		}
	}
	return 1;
}
//添加成员*******************************************************
void AddContact(Contact *pcon)
{
	if (CheckFullAndRe(pcon) != 1)
	{
		printf("扩容失败\n");
		return;
	}
	printf("请输入下列各项信息:\n");
	printf("请输入名字:>");
	scanf("%s", pcon->per[pcon->usedsize].name);
	printf("请输入性别:>");
	scanf("%s", pcon->per[pcon->usedsize].sex);
	printf("请输入年龄:>");
	scanf("%d", &pcon->per[pcon->usedsize].age);
	printf("请输入电话号码:>");
	scanf("%s", pcon->per[pcon->usedsize].tele);
	printf("请输入地址:>");
	scanf("%s", pcon->per[pcon->usedsize].addr);
	pcon->usedsize++;
	printf("添加联系人成功！");
}

//打印通讯录*******************************************************
void ShowContact(Contact *pcon)
{
	int i = 0;
	if (pcon->usedsize == 0)
	{
		printf("该通讯录为空，目前没有可Show的\n");
		return;
	}
	for (i = 0; i < pcon->usedsize; i++)
	{
		printf("姓名:%s   ", pcon->per[i].name);
		printf("性别:%s   ", pcon->per[i].sex);
		printf("年龄:%d   ", pcon->per[i].age);
		printf("电话号码:%s   ", pcon->per[i].tele);
		printf("地址:%s   ", pcon->per[i].addr);
		printf("\n");
	}
}

//查找联系人***************************************************
int SearchContact(Contact *pcon)
{
	int i = 0;
	char name[MAX_NAME] = { 0 };
	if (pcon->usedsize == 0)
	{
		printf("抱歉，该通讯录为空！");
		return -1;
	}
	printf("请输入要查找的联系人姓名：");
		scanf("%s", &name);
		for (i = 0; i < pcon->usedsize; i++)
		{
			if(strcmp(pcon->per[i].name, name) == 0)
			{
				return i;
			}
		}
		return -1;
}

//删除联系人*****************************************************
void DelContact(Contact *pcon)
{
	int i = 0;
	int index = SearchContact(pcon);
	if (index == -1)
	{
		printf("未找到此人！");
		return;
	}
	for (i = index; i < pcon->usedsize - 1; i++)
	{
		pcon->per[i] = pcon->per[i + 1];
	}
	pcon->usedsize--;
	printf("删除联系人成功！");
}
//清空联系人*****************************************************
void ClearContact(Contact *pcon)
{
	pcon->usedsize = 0;
	printf("清空联系人成功！");
}
//文件摧毁之前，现将联系人存储到文件中
void SaveContact(Contact *pcon)
{
	int i = 0;
	FILE *pf = fopen("Contact.bat", "wb");
	assert(pf != NULL);
	for (i = 0; i < pcon->usedsize; i++)
	{
		fwrite(pcon->per + i,sizeof(PersonInfo),1,pf );
	}
	fclose(pf);
	pf = NULL;
}


//摧毁通讯录********************************************************
void DestoryContact(Contact *pcon)//摧毁通讯录
{
	SaveContact(pcon);
	free(pcon->per);
	pcon->per = NULL;//预防野指针
	pcon->capacity = 0;
	pcon->usedsize = 0;
}




