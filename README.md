# Sudoku Solver

A visually interactive **Sudoku Solver** built with **C++** and **SFML**, capable of solving puzzles using a backtracking algorithm. The project features a clean GUI, cell selection, error checking, puzzle generation, and more — making it a complete utility for Sudoku enthusiasts and learners alike.

> This project was developed as part of an internship at CodeAlpha.

## Quick Start

**No setup required** — just download and run the latest version:

- Go to the [Releases](https://github.com/AlyKazani04/CodeAlpha_SudokuSolver/releases) page
- Download the zip
- Run the application (in src/), and start solving Sudoku puzzles instantly

## Features

- **Backtracking Algorithm**  
  Efficient logic to solve any valid Sudoku puzzle

- **Graphical Interface with SFML**  
  A polished and interactive 9x9 grid

- **Cell Editing and Input**  
  Manually enter values into empty cells

- **Instant Solve Button**  
  Automatically solves the puzzle

- **Error Checking**  
  Highlights user mistakes based on the solution

- **Random Puzzle Generator**  
  Creates new puzzles with varying difficulty

- **Dark/Light Mode**  
  Toggle between light and dark UI themes
<img width="794" height="796" alt="image" src="https://github.com/user-attachments/assets/02a2527c-0c6b-4cd3-93b8-881e1f6b529e" />
<img width="795" height="796" alt="image" src="https://github.com/user-attachments/assets/88fcb649-1317-4b42-a50c-365ab9231271" />



## For Developers: Building from Source

If you prefer to build the project yourself or want to contribute to development:

### Requirements

- C++17 compatible compiler
- SFML 3.0
- CMake (optional but recommended for cross-platform builds)

### Build Instructions (Linux Example)

```
git clone https://github.com/AlyKazani04/CodeAlpha_SudokuSolver
cd CodeAlpha_SudokuSolver
g++ src/*.cpp -o sudokusolver -lsfml-graphics -lsfml-window -lsfml-system
./sudokusolver
```
