# Subdirectory CMakeLists file to compile the code containing in the source directory

# Add library to call code from the different classes defined for the code
add_library(gameGrid Grid.h Grid.cpp)

add_library(gameState GameOver.h GameOver.cpp)

add_library(gamePuzzle Puzzle.h Puzzle.cpp)


# Link the target exucutable to include code from the source directory
# The "${CMAKE_CURRENT_SOURCE_DIR}" variable contains the path and name of current directory,
#  it's a defult variable defined in CMAKE that holds these path directives
target_link_directories(gameGrid PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_directories(gameState PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_directories(gamePuzzle PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

