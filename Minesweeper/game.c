#include "game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	for (int i = 0; i < rows; i++)        //����ѭ����ֵ��ά����
	{
		for (int j = 0; j < cols; j++)
		{
			board[i][j] = set;				   //ʹ��set����֤ͨ����
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	printf("--------ɨ��--------\n");		
	//��ӡ�к�
	for (int i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (int i = 1; i <= row; i++)
	{
		printf("%d ", i);								//��ӡ�к�
		for (int j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);			//��ӡ����
		}
		printf("\n");
	}
}

void SetMine(char mine[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		//��������±�ȥ������
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
	//�˺�����ֻ����FindMine������������ͷ�ļ�����

	/*�߼�
	*	x-1, y-1		x-1, y	 x-1, y+1
	* 
		x	,  y-1		x  ,  y	 x,    y+1

		x+1 y-1		x+1 y	x+1,y+1
	*/

	//˼·���������˸�������ַ���������Ȼ���ȥ8���ַ�0���õ��ľ��������׵ĸ���
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
	//�û��������Ų������
	/*�������λ���ǲ�����
		1.����		��Ϸ����
		2.������	��Ϸ���� ͳ�����긽���׵����� �洢��Ϣ��show������
	*/

	int x = 0;
	int y = 0;
	int win = 0;
	while (win<row*col- EASY_COUNT)
	{
		printf("������������>>");
		scanf("%d%d", &x, &y);				//x(1-9) y(1-9)

		if (x >= 1 && x <= row && y >= 1 && y <= col)			//�������Ϸ���
		{
			if (mine[x][y] == '1')
			{
				system("cls");
				printf("��Ϸ����\n");
				DisplayBoard(mine, row, col);			//��ʾ�����������
				printf("\n");
				break;
			}
			else
			{
				//ͳ��x,y��Χ�׵�����
				int count = get_mine_count(mine, x, y);
				show[x][y] = count + '0';				//��count��ֵ�����Ӧx, y�����ڣ�int + '0'������תΪ�ַ���
				system("cls");
				DisplayBoard(show, row, col);		//�鿴�Ų����
				win++;
			}
		}
		else
		{
			printf("�Ƿ����꣬��������\n");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		system("cls");
		printf("\n��Ϸʤ��");
		DisplayBoard(mine, row, col);
	}
}