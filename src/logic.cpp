#include "logic.hpp"

// Generating Logic

bool Generator::fillGrid(std::vector<std::vector<int>>& map)
{
    for(int row = 0; row < 9; row++)
    {
        for(int col = 0; col < 9; col++)
        {
            if(map[row][col] == 0)
            {
                std::random_device rd;
                std::mt19937 gen(rd());
                
                std::shuffle(m_numbers.begin(), m_numbers.end(), gen); // Randomize numbers

                for(int num : m_numbers)
                {
                    if(Solver::isCellValid(map, row, col, num))
                    {
                        map[row][col] = num;
                        if (fillGrid(map))
                        {
                            return true;
                        }

                        map[row][col] = 0; // Backtrack
                    }
                }
                return false; // Trigger backtracking
            }
        }
    }
    return true; // Fully filled
}

void Generator::generatePuzzle(std::vector<std::vector<int>>& map, int holes)
{
    while (holes > 0)
    {
        int row = rand() % 9;
        int col = rand() % 9;

        if (map[row][col] != 0)
        {
            map[row][col] = 0;
            holes--;
        }
    }
}

void Generator::generateSudokuPuzzle(std::vector<std::vector<int>>& puzzle, std::vector<std::vector<int>>& solution, int emptyCells)
{
    std::vector<std::vector<int>> fullMap(9, std::vector<int>(9, 0));

    // Fill the board with a valid complete Sudoku
    fillGrid(fullMap);

    // set this as solution
    solution = fullMap;

    // Create puzzle by copying and adding holes
    puzzle = fullMap;
    generatePuzzle(puzzle, emptyCells);
}

// Solving Logic

bool Solver::isCellValid(const std::vector<std::vector<int>>& map, int row, int col, int num)
{
    // Check row
    for(int x = 0; x < 9; x++)
    {
        if(map[row][x] == num)
        {
            return false;
        }
    }

    // Check column
    for(int x = 0; x < 9; x++)
    {
        if(map[x][col] == num)
        {
            return false;
        }
    }

    // Check 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(map[i + startRow][j + startCol] == num)
            {
                return false;
            }
        }
    }

    return true;
}

bool Solver::solve(std::vector<std::vector<int>>& map, int row, int col)
{
    // Sudoku Solved
    if(row == 9)
    {
		return true;
    }

	// Finished a Row 
	if(col == 9)
    {
		return solve(map, row + 1, 0); 
    }

	// Skip filled cells
	if(map[row][col] != 0)
    {
		return solve(map, row, col + 1);
    }

	for(int k = 1; k <= 9; k++)
    {
		if(isCellValid(map, row, col, k))
        {
			map[row][col] = k; 

			if(solve(map, row, col + 1))
            {
				return true; 
			}

			map[row][col] = 0; // Backtrack
		}
		else if(k == 9 && !isCellValid(map, row, col, 9))
        {
			return false;
		}
	}
    
	return false; // No Correct solution found
}