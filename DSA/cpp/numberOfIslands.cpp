// Basic application of Depth First Search in GRAPHS

// Name of the Question: Number of Islands (#200 on Leetcode)
// Language Used: C++ (Cplusplus)
// Platform: Leetcode
// Question Link: https://leetcode.com/problems/number-of-islands/

// Question:

// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water. 


// Example 1:

// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1

// Example 2:

// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// Output: 3
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 300
// grid[i][j] is '0' or '1'.

// Space Complexity: O(m*n)
// Time Complexity: O(m*n)

// My Solution:

class Solution {
public:
    int row[4] = {0,0,-1,1};
    int col[4] = {-1,1,0,0};
    
    bool isSafe(int i, int j, int r, int c) {
        return i>=0 && j>=0 && i < r && j < c;
    }
    
    void dfs(vector<vector<char>> &grid, int i, int j) {
        grid[i][j] = '0';
        int r = grid.size(), c = grid[0].size();
        for(int k=0; k<4; k++) {
            if(isSafe(i+row[k], j+col[k], r, c) && grid[i+row[k]][j+col[k]] == '1') {
                dfs(grid, i+row[k], j+col[k]);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int r =  grid.size(), c = grid[0].size();
        int count = 0;
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(grid[i][j] == '1') {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }
};

// Explanation:

// Perform DFS (depth first search) at every node that is equal to '1' and increase count by 1. While doing the depth first search, instead of maintaining the visited array, simply change '1' to '0' to mark it as visited. Finally, count is the number of islands.
