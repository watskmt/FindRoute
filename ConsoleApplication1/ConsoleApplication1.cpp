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
							{0,0,0,0,1, 0,0,0,0,0},
							{0,0,0,0,0, 1,0,0,0,0},

							{0,0,0,0,0, 0,1,0,0,0},
							{0,0,0,0,0, 0,0,1,0,0},
							{0,0,0,0,0, 0,0,0,1,0},
							{0,0,0,0,0, 0,0,0,0,1},
							{0,0,0,0,0, 0,0,0,0,0}
	};

	ShowStatus(state);

	while (key != ' ')// スペースで終了
	{
			key = getch();
			// if (key == 'w')printf("↑");
			// if (key == 'z')printf("↓");
			// if (key == 'a')printf("←");
			// if (key == 's')printf("→");
	}
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

