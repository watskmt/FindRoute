#include <stdio.h>
#include <conio.h>

void main(void)
{
	char key = 0;
	int i, j;
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
	char ch;

	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			switch (state[j][i])
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
			printf("%c", ch);
		}
		printf("\n");
	}

	
	while (key != ' ')// スペースで終了
	{
			key = getch();
			// if (key == 'w')printf("↑");
			// if (key == 'z')printf("↓");
			// if (key == 'a')printf("←");
			// if (key == 's')printf("→");
	}
}
