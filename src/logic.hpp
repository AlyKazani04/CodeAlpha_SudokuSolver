#pragma once

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <random>
#include <ctime>
#include <algorithm>
#include <vector>

class Solver
{   
    public:
        static bool isCellValid(const std::vector<std::vector<int>>& map, int row, int col, int cellVal);

        bool solve(std::vector<std::vector<int>>& map, int row = 0, int col = 0);
};

class Generator
{
    protected:
        std::vector<int> m_numbers = {1,2,3,4,5,6,7,8,9};

        bool fillGrid(std::vector<std::vector<int>>& map);

        void generatePuzzle(std::vector<std::vector<int>>& map, int holes);
    public:
        void generateSudokuPuzzle(std::vector<std::vector<int>>& map, int emptyCells);
};