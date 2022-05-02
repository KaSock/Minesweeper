#include "game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	for (int i = 0; i < rows; i++)        //遍历循环赋值二维数组
	{
		for (int j = 0; j < cols; j++)
		{
			board[i][j] = set;				   //使用set来保证通用性
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	printf("--------扫雷--------\n");		
	//打印列号
	for (int i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (int i = 1; i <= row; i++)
	{
		printf("%d ", i);								//打印行号
		for (int j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);			//打印棋盘
		}
		printf("\n");
	}
}

void SetMine(char mine[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		//生成随机下标去布置雷
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

static int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	//此函数仅只用于FindMine函数，不用在头文件声明

	/*逻辑
	*	x-1, y-1		x-1, y	 x-1, y+1
	* 
		x	,  y-1		x  ,  y	 x,    y+1

		x+1 y-1		x+1 y	x+1,y+1
	*/

	//思路，将附近八个坐标的字符加起来，然后减去8个字符0，得到的就是整型雷的个数
	return
		mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	//用户输入想排查的坐标
	/*检查坐标位置是不是雷
		1.是雷		游戏结束
		2.不是雷	游戏继续 统计坐标附近雷的数量 存储信息到show数组里
	*/

	int x = 0;
	int y = 0;
	int win = 0;
	while (win<row*col- EASY_COUNT)
	{
		printf("输入坐标排雷>>");
		scanf("%d%d", &x, &y);				//x(1-9) y(1-9)

		if (x >= 1 && x <= row && y >= 1 && y <= col)			//检测输入合法性
		{
			if (mine[x][y] == '1')
			{
				system("cls");
				printf("游戏结束\n");
				DisplayBoard(mine, row, col);			//显示结束后的棋盘
				printf("\n");
				break;
			}
			else
			{
				//统计x,y周围雷的数量
				int count = get_mine_count(mine, x, y);
				show[x][y] = count + '0';				//将count的值放入对应x, y坐标内，int + '0'将整型转为字符型
				system("cls");
				DisplayBoard(show, row, col);		//查看排查情况
				win++;
			}
		}
		else
		{
			printf("非法坐标，重新输入\n");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		system("cls");
		printf("\n游戏胜利");
		DisplayBoard(mine, row, col);
	}
}