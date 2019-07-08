#ifndef _CONTACT_H_
#define _CONTACT_H_

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<windows.h>
#pragma warning (disable:4996)

enum Oper
{
	EXIT,
	ADD,
	DEL,
	SEAR,
	SHOW,
	CLEAR,
	DESTORY
};

#define MAX_NUMBER 1000
#define MAX_NAME 10
#define SEX_NAME 5
#define TEL_NAME 11
#define ADDR_NAME 20

#define DEFAULT_SIZE 2
//���������Ϣ
typedef struct PersonIfo
{
	char name[MAX_NAME];
	char sex[SEX_NAME];
	int age;
	char tele[TEL_NAME];
	char addr[ADDR_NAME];
}PersonInfo;
//����ͨѶ¼
typedef struct Contact
{
	int usedsize;//��Ч���ݸ���
	PersonInfo *per;
	int capacity;//ͨѶ¼������
}Contact;
void InitContact(Contact *pcon);//ͨѶ¼��ʼ��
void AddContact(Contact *pcon);//��ӳ�Ա
void ShowContact(Contact *pcon);//��ӡͨѶ¼
void DelContact(Contact *pcon);//ɾ����Ա
int SearchContact(Contact *pcon);//���ҳ�Ա
void ClearContact(Contact *pcon);//���ͨѶ¼
void DestoryContact(Contact *pcon);//�ݻ�ͨѶ¼
void SaveContact(Contact *pcon);//������ϵ�˵��ļ�
void LoadContact(Contact *pcon);//������ϵ��
#endif