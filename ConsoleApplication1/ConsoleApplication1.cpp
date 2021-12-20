#include <stdio.h>
#include <conio.h>

int ShowStatus(int state[][10]);
int main(void)
{
	char key = 0;
	int state[10][10] = {
							{0,1,0,0,0, 0,0,0,0,0},
							{0,0,1,0,0, 0,0,0,0,0},
							{0,0,0,1,0, 0,0,0,0,0},
							{0,0,0,0,0, 0,0,0,0,0},
							{0,0,0,0,0, 1,0,0,0,0},

							{0,0,0,0,0, 0,1,0,0,0},
							{0,0,0,0,0, 0,0,1,0,0},
							{0,0,0,0,0, 0,0,0,0,0},
							{0,0,0,0,0, 0,0,0,0,1},
							{0,0,0,0,0, 0,0,0,0,0}
	};
	
	int current_x = 0;
	int current_y = 0;
	FILE *logFile;

	logFile = fopen("route.log", "w");
	fputs("Start\n", logFile);
	fprintf(logFile, "(%d,%d)\n", current_x, current_y);
	
	while (key != ' ')// スペースで終了
	{
		ShowStatus(state);
		key = getch();
		state[current_y][current_x] = -1;
		if (current_x != 9 && state[current_y][current_x + 1] == 0)
			current_x++;
		else if (current_y != 9 && state[current_y + 1][current_x] == 0)
			current_y++;
		else if (current_x != 0 && state[current_y][current_x - 1] == 0)
			current_x--;
		else if (current_y != 0 && state[current_y - 1][current_x] == 0)
			current_y--;
		else
			break;
		fprintf(logFile, " -> セル(%d,%d)\n", current_x, current_y);

	}
	ShowStatus(state);

	fclose(logFile);
}





int ShowStatus(int state[][10])
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
			printf("|%c", ch);
		}
		printf("|\n");
	}
	for (j = 0; j < 10; j++)
		printf("--");
	printf("-\n");

	return 0;
}

