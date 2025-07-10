#include "logic.hpp"

bool Solver::isCellValid(const std::vector<std::vector<int>>& map, int row, int col, int num)
{
    // Check row
    for (int x = 0; x < 9; x++) {
        if (map[row][x] == num)
            return false;
    }

    // Check column
    for (int x = 0; x < 9; x++) {
        if (map[x][col] == num)
            return false;
    }

    // Check 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(map[i + startRow][j + startCol] == num)
                return false;
        }
    }

    return true;
}

bool Solver::solve(std::vector<std::vector<int>>& map, int row, int col)
{
    // Sudoku Solved
    if (row == 9)
		return true;

	// Finished a Row 
	if (col == 9)
		return solve(map, row + 1, 0); 

	// Skip filled cells
	if (map[row][col] != 0)
		return solve(map, row, col + 1);

	for (int k = 1; k <= 9; k++) {
		if (isCellValid(map, row, col, k)) {
			map[row][col] = k; 
			if (solve(map, row, col + 1)) {
				return true; 
			}
			map[row][col] = 0; // Backtrack
		}
		else if (k == 9 && !isCellValid(map, row, col, 9)) {
			return false;
		}
	}
	return false; // No Correct solution found
}