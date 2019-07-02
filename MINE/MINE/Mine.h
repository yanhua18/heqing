#ifndef _MINE_H_
#define _MINE_H_
#pragma warning (disable:4996)
#include<stdio.h>
#include<string.h>
#include<Windows.h>
#include<time.h>
#define ROW 12
#define COL 12
#define MINE_NUM 20
#define TOTAL 100
void ShowBoard(char board[][COL], int row, int col);
void SetMine(char mine[][COL], int row,int col,int count);
char GetMine(char mine[][COL], char board[][COL], int row, int col);//char ->'0'-'8'
void Game();

#endif