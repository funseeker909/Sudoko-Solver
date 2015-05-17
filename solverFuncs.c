/*
 * Project 3 
 * 
 * Reed Garmsen
 * Logan Gardner
 *
 * Instructor: Julie Workman
 */
 
#include <stdio.h>

/*
 * This function reads in a Sudoku puzzle as input and stores it in the array given as 
 * an argument. A '0' indicates a blank square. Use a format specifier of "%1d" 
 * (that's the digit, one; not the lowercase version of the letter, L) to read in a single 
 * digit from the input stream
 */

void readSudoku(int puzzle[][9])
{
	int i, j;
	
	for (i = 0; i < 9; i++)
	{
		printf("Enter line %d: ", i+1);
		for (j = 0; j < 9; j++)
		{
		       scanf("%1d", &puzzle[i][j]);
		}
	}
}

/*
 * checkValid takes as arguments the puzzle, the square to test (row and column), 
 * and the number to test. If the number can be legally placed in the square, then the 
 * function should return 1. The function should return 0 if the number cannot be 
 * placed in the square. The function should return -1 if the square is not empty. The 
 * puzzle array should not be changed by the function. 
 */

int checkValid(int puzzle[][9], int row, int col, int num)
{
  int i, j, startRow, startCol;
	
	if (puzzle[row][col] == 0)
	{
	   startRow = (row / 3) * 3;
	   startCol = (col / 3) * 3;
			for ( i = startRow; i < startRow + 3; i++)
			{
				for ( j = startCol; j < startCol + 3; j++)
				{
					if (num == puzzle[i][j])
					{
						return 0;
					}
				}

			}			
	

		 /*checks row*/
		 for (i = 0; i < 9; i++)
		{
			if (num == puzzle[row][i] || num <= 0)
			{
				return 0;
			}
		}
		 /*checks column*/
		for (j = 0; j < 9; j++)
		{
			if (num == puzzle[j][col])
			{
				return 0;
			}
		}
	}
	else 
	{
		return -1;
	}

	return 1;
}









