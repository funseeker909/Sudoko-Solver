/*
 * Project 3
 *
 * Reed Garmsen
 * Logan Gardner
 *
 * Instructor: Julie Workman
 * CPE 101 Sec. 07
 */
 
#include <stdio.h>
#include "sudokusolver.h"

#define SIZE 9

int main ()
{
	int i, j, oneChanged, numSinCan = 0, sinCanAns = 0, solved = 0, failedAttempts = 0, backtracks = 0;
	int puzzle[SIZE][SIZE];
	
	readSudoku(puzzle);
	printSudoku(puzzle);
																/* Check inst version to see what prints if already solved */
	do
	{
		oneChanged = 0;
		for (i = 0; i < SIZE; i++)
		{
			for (j = 0; j < SIZE; j++)
			{
				if (puzzle[i][j] == 0)
				{
					sinCanAns = singleCandidate(puzzle, i, j);
					if (sinCanAns == 1)
					{
						oneChanged = 1;
						numSinCan++;
					}
				}
			}
		}
	}
	while (oneChanged == 1);
	solved = isSolved(puzzle);
	if (solved == 1)
	{
		printf("Solved by single candidate technique.\n");
		printf("Single candidates found: %d\n", numSinCan);
		printf("Failed attempts: %d\n", failedAttempts);
		printf("Backtracks: %d\n", backtracks);
		printSudoku(puzzle);
	}
	/*else if (   )*/
	else if ( solved == 0 )
	{
		 bruteForce(puzzle, &failedAttempts, &backtracks); 
		 solved = isSolved(puzzle);
		 if (solved == 1 && backtracks == 0)
		 {
			printf("Solved by brute force with no backtracking.\n");
			printf("Single candidates found: %d\n", numSinCan);
			printf("Failed attempts: %d\n", failedAttempts);
			printf("Backtracks: %d\n", backtracks);
			printSudoku(puzzle);
		}
		else if ( solved == 1 )
		{
			printf("Solved by brute force with backtracking.\n");
			printf("Single candidates found: %d\n", numSinCan);
			printf("Failed attempts: %d\n", failedAttempts);
			printf("Backtracks: %d\n", backtracks);
			printSudoku(puzzle);
		}
		else
		{
			printf("Puzzle is not solvable.\n");
			printf("Single candidates found: %d\n", numSinCan);
			printf("Failed attempts: %d\n", failedAttempts);
			printf("Backtracks: %d\n", backtracks);
		}


	}
	return 0;
}
 
void printSudoku(int puzzle[][9])
{
	int i, j, numZeroes = 0;
	
	for (i= 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			if (puzzle[i][j] == 0)
			{
				numZeroes++;
			}
		}
	}
	
	if (numZeroes != 0)
	{
		printf("\n\nInput puzzle:\n\n");
		
		for (i = 0; i < SIZE; i++)
		{
			for (j = 0; j < SIZE; j++)
			{
				printf("%d", puzzle[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	else
	{
		printf("\nSolution:\n\n");
	
		for (i = 0; i < SIZE; i++)
		{
			for (j = 0; j < SIZE; j++)
			{
				printf("%d", puzzle[i][j]);
				
				if ((j + 1) % 3 == 0  && j != 8)
				{
					printf(" | ");
				}
			}
			printf("\n");			
			if ((i + 1) % 3 == 0 && i != 8)
			{
				printf("---------------\n");
			}

		}
	}
}

int isSolved(int puzzle[][9]) 
{
	int i, j, numZeroes = 0;
	
	for (i= 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			if (puzzle[i][j] == 0)
			{
				numZeroes++;
			}
		}
	}
	
	if (numZeroes == 0)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

int singleCandidate(int puzzle[][9], int row, int col) /* Use checkValid, give if else with 1 and 0 as values */
{
	int i, valid, numWorks, numValid = 0;
	
	for (i = 1; i < 10; i++)
	{
		valid = checkValid(puzzle, row, col, i);
		if (valid == 1)
		{
			numWorks = i;
			numValid++;
		}
	}
	if (numValid == 1)
	{
		puzzle[row][col] = numWorks;
		return 1;
	}
	else
	{
		return 0;
	}
}

void bruteForce(int puzzle[][9], int *attempts, int *backTracks)
{
	int i, j, k, valid, oldBack;
	int copy[9][9];
	

	/*making copy of puzzle*/
	for (i =0; i < 9; i++)
		{
			for (j = 0; j < 9; j++)
			{
				copy[i][j] = puzzle[i][j];
			}
		}
	/*made copy*/
	
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (copy[i][j] == 0)  /* check for zeros in copy[i][j] */
			{
				k = puzzle[i][j]+1;  /* start at puzzle[i][j]+1 */
				puzzle[i][j] = 0;/* set puzzle[i][j] back to zero */
				
				while (puzzle[i][j] == 0 && k < 10)
				{
					valid = checkValid(puzzle, i, j, k);
					
					if (valid == 1)
					{
						puzzle[i][j] = k;
					}
					else
					{
						(*attempts)++;
						k++;
					}
				}
			    do
				{
					if ( k == 10 )
					{
						j--;
						oldBack = *backTracks;
						(*backTracks)++;
						if (j < 0)
						{
							i--;
							j = 8;
							if (i == -1)
							{
								return;
							}
						}
					} 
				} while (copy[i][j] != 0);
				if (*backTracks != oldBack)
				{
					j--;
				}/* if you didn't find anything... backup your i and j until you find a zero in the copy puzzle */
					/* back up one more spot */
			}
		}
	}
}