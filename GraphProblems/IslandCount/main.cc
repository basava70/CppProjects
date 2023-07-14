/* Copyright 2023 Owned by Seshadri Basava
 * Island Count problem
 * Print Max length of Island
 * Written on July 14
 */
#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

class Solution {
public:
  int numIslands(std::vector<std::vector<char>> &grid) {
    int num_islands = 0, max_island_length = 0, current_island_length = 0;
    for (int row = 0; row < grid.size(); row++) {
      for (int col = 0; col < grid[0].size(); col++) {
        if (grid[row][col] == '1') {
          num_islands++;
          current_island_length = 0;
          current_island_length =
              mark_island(grid, row, col, current_island_length);
          max_island_length = max_island_length >= current_island_length
                                  ? max_island_length
                                  : current_island_length;
        }
      }
    }
    std::cout << "max_island_length is " << max_island_length << std::endl;
    return num_islands;
  }
  int mark_island(std::vector<std::vector<char>> &grid, int row, int col,
                  int current_island_length) {
    if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() ||
        grid[row][col] != '1')
      return current_island_length;

    grid[row][col] = '2';
    current_island_length++;

    current_island_length =
        mark_island(grid, row - 1, col, current_island_length);
    current_island_length =
        mark_island(grid, row + 1, col, current_island_length);
    current_island_length =
        mark_island(grid, row, col - 1, current_island_length);
    current_island_length =
        mark_island(grid, row, col + 1, current_island_length);

    return current_island_length;
  }
};

int main() {
  int vertices = 7;

  // create graph
  std::vector<std::vector<char>> grid = {{'1', '1', '0', '1', '0'},
                                         {'0', '1', '0', '0', '1'},
                                         {'1', '1', '1', '0', '0'},
                                         {'0', '1', '0', '1', '1'}};
  Solution solution;
  int num_islands = solution.numIslands(grid);
  std::cout << "Number of islands are " << num_islands << std::endl;
  return 0;
}
