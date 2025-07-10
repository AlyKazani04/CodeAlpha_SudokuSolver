#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

namespace Solver
{   
    bool isCellValid(const std::vector<std::vector<int>>& map, int row, int col, int cellVal);

    bool solve(std::vector<std::vector<int>>& map, int row = 0, int col = 0);
};