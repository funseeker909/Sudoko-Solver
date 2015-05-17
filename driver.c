/* Driver file for program 4.
 * This driver should be tested with the driver_input input file
 */

#include <stdio.h>
void readSudoku(int puzzle[][9]);
int checkValid(int puzzle[][9], int row, int col, int num);

int main(void) {
	int puzzle[9][9];  /* array to store the puzzle */

	readSudoku(puzzle);  /* read in the puzzle */
	
	printf("\n\n***Testing checkValid function...***\n\n");
	printf ("Output:   %d\n", checkValid(puzzle, 0, 2, 5));  /* place 5 in row 0, column 2 = invalid */
	printf("Expected: 0\n");
	
	printf ("Output:   %d\n", checkValid(puzzle, 0, 2, 8));  /* place 8 in row 0, column 2 = invalid */
	printf("Expected: 0\n");
	
	printf ("Output:   %d\n", checkValid(puzzle, 0, 2, 9));  /* place 9 in row 0, column 2 = invalid */
	printf("Expected: 0\n");
	
	
	printf ("Output:   %d\n", checkValid(puzzle, 1, 1, 8));  /* place 8 in row 1, column 1 = valid */
	printf("Expected: 1\n");
	
	printf ("Output:   %d\n", checkValid(puzzle, 0, 8, 7));  /* place 7 in row 0, column 8 = valid */
	printf("Expected: 1\n");
	
	printf ("Output:   %d\n", checkValid(puzzle, 8, 0, 6));  /* place 6 in row 8, column 0 = valid */
	printf("Expected: 1\n");
	
	
	printf ("Output:  %d\n", checkValid(puzzle, 0, 0, 6));  /* place 6 in row 0, column 0 = square not empty */
	printf("Expected:-1\n");

	return 0;
}

