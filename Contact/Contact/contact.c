#include"contact.h"
//�ڳ�ʼ��ǰ�������ļ��д洢������
void LoadContact(Contact *pcon)
{
	FILE *pf = fopen("Contact.bat", "rb");
	PersonInfo tmp = { 0 };
	if (pf == NULL)
	{
		return;
	}
	//fread��������ķ���ֵ�Ƕ�ȡ�ɹ����ֽ���
	while(fread(&tmp, sizeof(PersonInfo), 1, pf)>0)
	{
		CheckFullAndRe(pcon);//���ļ��ж�ȡ��per�У������ж��Ƿ�Ϊ���������ļ��ж�ȡ�ĸ����Ƿ��capacity�����������Ҫ���ݣ�
		pcon->per[pcon->usedsize++] = tmp;
	}
	fclose(pf);
	pf = NULL;
}
//��ʼ��ͨѶ¼**************************************************
void InitContact(Contact *pcon)
{
	pcon->usedsize = 0;//���ṹ������е�usedsize��ʼ��Ϊ0
	pcon->capacity = DEFAULT_SIZE;
	pcon->per = (PersonInfo *)malloc(sizeof(PersonInfo)*pcon->capacity);
	assert(pcon->per != NULL);
	LoadContact(pcon);
}
//����ֵ�����Ƿ����ݳɹ�
static int CheckFullAndRe(Contact *pcon)//�ڳ�ʼ��ʱ��Ҫ�ж��Ƿ��Ѿ�����(>capacity),��������Ҫrealloc����������
{
	PersonInfo *ptr;//����һ����ʱ��������ֹrealloc����ռ�ʧ�ܵ���pcon->per��ָ���Ŀ�궪ʧ
	if (pcon->usedsize == pcon->capacity)
	{
		ptr = (PersonInfo *)realloc(pcon->per, sizeof(PersonInfo)*pcon->capacity * 2);
		if (ptr != NULL)
		{
			pcon->per = ptr;
			pcon->capacity *= 2;//���ݺ�������Ϊԭ��������
			printf("�����Ѿ��ɹ���\n");
			return 1;
		}
		else
		{
			return 0;//����ʧ��
		}
	}
	return 1;
}
//��ӳ�Ա*******************************************************
void AddContact(Contact *pcon)
{
	if (CheckFullAndRe(pcon) != 1)
	{
		printf("����ʧ��\n");
		return;
	}
	printf("���������и�����Ϣ:\n");
	printf("����������:>");
	scanf("%s", pcon->per[pcon->usedsize].name);
	printf("�������Ա�:>");
	scanf("%s", pcon->per[pcon->usedsize].sex);
	printf("����������:>");
	scanf("%d", &pcon->per[pcon->usedsize].age);
	printf("������绰����:>");
	scanf("%s", pcon->per[pcon->usedsize].tele);
	printf("�������ַ:>");
	scanf("%s", pcon->per[pcon->usedsize].addr);
	pcon->usedsize++;
	printf("�����ϵ�˳ɹ���");
}

//��ӡͨѶ¼*******************************************************
void ShowContact(Contact *pcon)
{
	int i = 0;
	if (pcon->usedsize == 0)
	{
		printf("��ͨѶ¼Ϊ�գ�Ŀǰû�п�Show��\n");
		return;
	}
	for (i = 0; i < pcon->usedsize; i++)
	{
		printf("����:%s   ", pcon->per[i].name);
		printf("�Ա�:%s   ", pcon->per[i].sex);
		printf("����:%d   ", pcon->per[i].age);
		printf("�绰����:%s   ", pcon->per[i].tele);
		printf("��ַ:%s   ", pcon->per[i].addr);
		printf("\n");
	}
}

//������ϵ��***************************************************
int SearchContact(Contact *pcon)
{
	int i = 0;
	char name[MAX_NAME] = { 0 };
	if (pcon->usedsize == 0)
	{
		printf("��Ǹ����ͨѶ¼Ϊ�գ�");
		return -1;
	}
	printf("������Ҫ���ҵ���ϵ��������");
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

//ɾ����ϵ��*****************************************************
void DelContact(Contact *pcon)
{
	int i = 0;
	int index = SearchContact(pcon);
	if (index == -1)
	{
		printf("δ�ҵ����ˣ�");
		return;
	}
	for (i = index; i < pcon->usedsize - 1; i++)
	{
		pcon->per[i] = pcon->per[i + 1];
	}
	pcon->usedsize--;
	printf("ɾ����ϵ�˳ɹ���");
}
//�����ϵ��*****************************************************
void ClearContact(Contact *pcon)
{
	pcon->usedsize = 0;
	printf("�����ϵ�˳ɹ���");
}
//�ļ��ݻ�֮ǰ���ֽ���ϵ�˴洢���ļ���
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


//�ݻ�ͨѶ¼********************************************************
void DestoryContact(Contact *pcon)//�ݻ�ͨѶ¼
{
	SaveContact(pcon);
	free(pcon->per);
	pcon->per = NULL;//Ԥ��Ұָ��
	pcon->capacity = 0;
	pcon->usedsize = 0;
}




