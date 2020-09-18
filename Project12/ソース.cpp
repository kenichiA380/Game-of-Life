#include <iostream>
#include <Windows.h>
constexpr int height = 30;
constexpr int width  = 30;

int cell[height][width];
int ucell[height][width];

bool loop = true;

void draw(void);

int main(void) 
{
	//init
	for (int i = 0; i < height; i++) 
	{
		for (int j = 0; j < width; j++)
		{
			cell[i][j] = 0;
			ucell[i][j] = 0;
		}
	}
	//glider
	cell[0][10] = 1;
	cell[1][11] = 1;
	cell[2][9] = 1;
	cell[2][10] = 1;
	cell[2][11] = 1;
	
	draw();

	system("pause");
	//system("cls");

	while (loop)
	{
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				int count = 0;
				//top row
				if (i > 0) {
					if (j > 0)          if (cell[i - 1][j - 1]) count++; //top left
					                    if (cell[i - 1][j])     count++; //top center
					if (j < width - 2)  if (cell[i - 1][j + 1]) count++; //top right
				}
				//center row
				if (j > 0)              if (cell[i][j - 1])     count++; //left
				//if (cell[i][j]) count++; center cell is ignored  
				if (j < width - 2)      if (cell[i][j + 1])     count++; //right
				
				//bottom row
				if (i < height - 2) {
					if (j > 0)          if (cell[i + 1][j - 1]) count++; //bottom left
					                    if (cell[i + 1][j])     count++; //bottom center
					if (j < width - 2)  if (cell[i + 1][j + 1]) count++; //bottom right
				}

				if (cell[i][j] == 1 && count == 2) ucell[i][j] = 1; //survive
				else if (count == 3) ucell[i][j] = 1;               //birth
				else ucell[i][j] = 0;                               //death
				//printf("row:%d col:%d stt:%d cnt:%d\n", i, j, cell[i][j], count); debug info
			}
		}
		//update
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				cell[i][j] = ucell[i][j];
			}
		}
		draw();
		system("pause");
	}
	return 0;
}

void draw(void)
{
	//draw
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j % width == 0)
			{
				printf("\n");
			}
			//dead cell
			if (cell[i][j] == 0)
			{
				printf(" ");
			}
			//living cell
			else if (cell[i][j] == 1)
			{
				printf("¡");
			}
			else
			{
				printf("e");
			}
		}
	}
	printf("\n");
}