# This is the script to compile and run the sudoku game.
# The script currently only runs on a Unix or Linux based machine.

# Initialize cmake to build makefile using source and build directories
cmake -S . -B build/.

# call make to create the executable file
cmake --build build/.


# Run the executable to launch game
./build/SudokuGame

