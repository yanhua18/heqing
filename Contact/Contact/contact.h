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
//抽象个人信息
typedef struct PersonIfo
{
	char name[MAX_NAME];
	char sex[SEX_NAME];
	int age;
	char tele[TEL_NAME];
	char addr[ADDR_NAME];
}PersonInfo;
//抽象通讯录
typedef struct Contact
{
	int usedsize;//有效数据个数
	PersonInfo *per;
	int capacity;//通讯录的容量
}Contact;
void InitContact(Contact *pcon);//通讯录初始化
void AddContact(Contact *pcon);//添加成员
void ShowContact(Contact *pcon);//打印通讯录
void DelContact(Contact *pcon);//删除成员
int SearchContact(Contact *pcon);//查找成员
void ClearContact(Contact *pcon);//清空通讯录
void DestoryContact(Contact *pcon);//摧毁通讯录
void SaveContact(Contact *pcon);//保存联系人到文件
void LoadContact(Contact *pcon);//加载联系人
#endif