#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>				//在这个.h文件中引用头文件则可以免去每个源文件都引用一遍的麻烦
#include<stdlib.h>
#include<time.h>

#define ROW  9					//真正的棋盘
#define COL    9					//ROW行 COL列
#define EASY_COUNT 10	//简单版本的雷数

#define ROWS ROW + 2		//数组棋盘
#define COLS COL +2

//初始化棋盘
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);		//char set 用于设置初始化值

//打印棋盘
void DisplayBoard(char board[ROWS][COLS], int row, int col);

//设置雷
void SetMine(char mine[ROWS][COLS], int row, int col);

//排雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);