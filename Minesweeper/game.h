#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>				//�����.h�ļ�������ͷ�ļ��������ȥÿ��Դ�ļ�������һ����鷳
#include<stdlib.h>
#include<time.h>

#define ROW  9					//����������
#define COL    9					//ROW�� COL��
#define EASY_COUNT 10	//�򵥰汾������

#define ROWS ROW + 2		//��������
#define COLS COL +2

//��ʼ������
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);		//char set �������ó�ʼ��ֵ

//��ӡ����
void DisplayBoard(char board[ROWS][COLS], int row, int col);

//������
void SetMine(char mine[ROWS][COLS], int row, int col);

//����
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);