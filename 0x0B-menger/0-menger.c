#include "menger.h"
/**
 * menger - Function that draws a 2D Menger Sponge
 * @level: Menger Sponge level to draw
 * Return: Void
 **/
void menger(int level)
{
	int row, column, level_size, x, y;
	char pound_sign;

	if (level < 0)
		return;

	level_size = pow(3, level);
	for (row = 0; row < level_size; row++)
	{
		for (column = 0; column < level_size; column++)
		{
			pound_sign = '#';
			x = row;
			y = column;
			while (x > 0 || y > 0)
			{
				if ((x % 3 == 1) && (y % 3 == 1))
				{
					pound_sign = ' ';
				}
				x /= 3;
				y /= 3;
			}
			printf("%c", pound_sign);
		}
		printf("\n");
	}
}
