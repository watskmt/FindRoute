// squashのためのテストー２

#include <stdio.h>
#include <conio.h>

typedef struct Point
{
	int x;
	int y;
}Point;

int ShowStatus(int state[][10], Point p);
int ShowStatus(int state[][10], Point p, FILE *fp);

int main(void)
{
	int i;
	char key = 0;
	int state[10][10] = {
							{0,1,0,0,0, 0,0,0,0,0},
							{0,0,1,0,0, 0,0,0,0,0},
							{0,0,0,1,0, 0,0,0,0,0},
							{0,0,0,0,0, 0,0,0,0,0},
							{0,0,0,0,0, 1,0,0,1,0},

							{0,0,0,0,0, 0,1,0,1,0},
							{0,0,0,0,0, 0,0,0,1,0},
							{0,0,0,0,0, 0,0,0,1,0},
							{0,0,0,0,0, 0,0,0,0,1},
							{0,0,0,0,0, 0,0,0,1,0}
	};
	Point route[100];
	int steps=0;
	
	Point current;
	current.x = 0;
	current.y = 0;
	route[steps++] = current;
	
	FILE *logFile;

	logFile = fopen("route.log", "w");
	fputs("Start\n", logFile);
	fprintf(logFile, "(%d,%d)\n", current.x, current.y);
	ShowStatus(state, current);
	ShowStatus(state, current, logFile);

	while (key != ' ')// スペースで終了
	{
		key = getch();
		// 通ってきた道をマーク（-1）
		state[current.y][current.x] = -1;

		// 右から初めて右回りに探索
		if (current.x != 9 && state[current.y][current.x + 1] == 0)
		{
			current.x++;
			route[steps++] = current;
		}
		else if (current.y != 9 && state[current.y + 1][current.x] == 0)
		{
			current.y++;
			route[steps++] = current;
		}
		else if (current.x != 0 && state[current.y][current.x - 1] == 0)
		{
			current.x--;
			route[steps++] = current;
		}
		else if (current.y != 0 && state[current.y - 1][current.x] == 0)
		{
			current.y--;
			route[steps++] = current;
		}
		else
		{
			if (steps > 0)
				current = route[--steps];
			else
				break;
		}


		fprintf(logFile, " -> セル(%d,%d)\n", current.x, current.y);
		ShowStatus(state, current);
		ShowStatus(state, current, logFile);
		if (current.x == 9 && current.y == 9)
		{
			printf("Goal\n");
			break;
		}
		else if(steps == 0)
		{
			printf("Failed\n");
			break;
		}


	}


	fclose(logFile);
}



int ShowStatus(int state[][10], Point p)
{
	char ch;

	int i, j;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
			printf("--");
		printf("-\n");

		for (j = 0; j < 10; j++)
		{
			if (j == p.x && i == p.y)
				ch = '*';
			else
			{
				switch (state[i][j])
				{
				case 0:
					ch = ' ';
					break;
				case -1:
					ch = 'X';
					break;
				case 1:
					ch = 'O';
					break;
				default:
					ch = '@';
					break;
				}
			}
			printf("|%c", ch);
		}
		printf("|\n");
	}
	for (j = 0; j < 10; j++)
		printf("--");
	printf("-\n");

	return 0;
}
int ShowStatus(int state[][10], Point p, FILE *fp)
{
	char ch;
	int i, j;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
			fprintf(fp, "--");
		fprintf(fp, "-\n");

		for (j = 0; j < 10; j++)
		{
			if (j == p.x && i == p.y)
				ch = '*';
			else
			{
				switch (state[i][j])
				{
				case 0:
					ch = ' ';
					break;
				case -1:
					ch = 'X';
					break;
				case 1:
					ch = 'O';
					break;
				default:
					ch = '@';
					break;
				}
			}
			fprintf(fp, "|%c", ch);
		}
		fprintf(fp, "|\n");
	}
	for (j = 0; j < 10; j++)
		fprintf(fp, "--");
	fprintf(fp, "-\n");

	return 0;
}

