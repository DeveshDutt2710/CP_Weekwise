/*
https://leetcode.com/problems/number-of-islands/submissions/

200_NumberofIslands

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.

*/


class Solution {
public:
    void DFS(vector<vector<char>>& grid, int i, int j) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return;

        if(grid[i][j] == '2' || grid[i][j] == '0')
            return;
        

        grid[i][j] = '2';
        

        DFS(grid, i+1, j);
        DFS(grid, i, j-1);
        DFS(grid, i-1, j);
        DFS(grid, i, j+1);
    }
    
    int numIslands(vector<vector<char>>& grid) 
    {
        int islands = 0;
        for(int i = 0; i < grid.size(); i++) 
        {
            for(int j = 0; j < grid[0].size(); j++) 
            {
                if(grid[i][j] == '1') 
                {
                    DFS(grid, i, j);
                    ++islands;
                } 
            }
        }
        return islands;
    }
};