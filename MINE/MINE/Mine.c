#include"Mine.h"
int GetRandIdex(int start, int end)
{
	return rand() % (end - start + 1) + start;
}

void SetMine(char mine[][COL], int row, int col,int count)
{
	srand((unsigned long)time(NULL));
	int _count = 0;
	while (_count < count)
	{
		int x = GetRandIdex(1, 10);
		int y = GetRandIdex(1, 10);
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			_count++;
		}
	}
}
void ShowBoard(char board[][COL], int row, int col)
{
	printf("   ");
	int i = 1;
	for (; i <= 10; i++)
	{
		printf("%3d", i);
	}
	printf("\n----");
	for(i = 1; i <= 10; i++)
	{
		printf("---");
	}
	printf("\n");
	for (i = 1; i <= 10; i++)
	{
		printf("%3d|", i);
		int j = 1;
		for (; j <= 10; j++)
		{
			printf(" %c|", board[i][j]);
		}
		printf("\n----");
		int k = 1;
		for (; k <= 10; k++)
		{
			printf("---");
		}
		printf("\n");
	}
}
char GetMine(char mine[][COL],char board[][COL], int row, int col)
{
	board[row][col] = (mine[row - 1][col - 1] + mine[row - 1][col] + mine[row - 1][col + 1] + \
		mine[row][col - 1] + mine[row][col + 1] + mine[row + 1][col - 1] + \
		mine[row + 1][col] + mine[row + 1][col + 1] - 7 * '0');//(+'0'-8*'0')
	if (board[row][col] == '0')
	{
		if (board[row - 1][col - 1] == '?')
			GetMine(mine, board, row - 1, col - 1);
		if (board[row - 1][col] == '?')
			GetMine(mine, board, row - 1, col);
		if (board[row - 1][col + 1] == '?')
			GetMine(mine, board, row - 1, col + 1);
		if (board[row][col - 1] == '?')
			GetMine(mine, board, row, col - 1);
		if (board[row][col + 1] == '?')
			GetMine(mine, board, row, col + 1);
		if (board[row + 1][col - 1] == '?')
			GetMine(mine, board, row + 1, col - 1);
		if (board[row + 1][col] == '?')
			GetMine(mine, board, row + 1, col);
		if (board[row + 1][col + 1] == '?')
			GetMine(mine, board, row + 1, col + 1);
	}
}

void Game()
{
	char mine[ROW][COL];
	char board[ROW][COL];
	memset(mine, '0', sizeof(mine));
	memset(board, '?', sizeof(board));
	SetMine(mine, ROW, COL, MINE_NUM);
	int x = 0;
	int y = 0;
	int count = TOTAL;
	while (1)
	{
		ShowBoard(board,ROW,COL);
		printf("请选择坐标：\n");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= ROW - 2 && y >= 1 && y <= COL - 2)
		{
			if (mine[x][y] == '1'&& count == TOTAL)
			{
				mine[x][y] = '0';
				SetMine(mine, ROW, COL, 1);
				count--;
			}
			if (mine[x][y] == '0')
			{
				GetMine(mine, board, x, y);
				count--;
				if (count <= 20)
				{
					printf("恭喜你，你已经获得了胜利！\n");
					break;
				}
			}
			else
			{
				printf("不好意思，你已经被炸死了！\n");
				ShowBoard(mine, ROW, COL);
				break;
			}
		}
		else
		{
			printf("你输入的坐标有误，请重新输入：\n");
		}
	}
}