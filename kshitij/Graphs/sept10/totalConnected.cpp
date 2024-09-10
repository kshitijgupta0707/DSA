//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void bfs(int row , int col , vector<vector<bool>> &visited, vector<vector<char>> &M)
    {

        int m = visited.size();
        int n = visited[0].size();

        queue<pair<int, int>> q;

        q.push({row , col});

        visited[row][col] = true;

        while (!q.empty())
        {

            pair<int, int> temp = q.front();
            q.pop();
            int row = temp.first;
            int col = temp.second;
         

          for(int delrow = -1 ; delrow <= 1 ; delrow++){
            for(int delcol = -1 ; delcol <= 1 ; delcol++){
                int nrow = row + delrow;
                int ncol = col + delcol;
                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && M[nrow][ncol] == '1' && 
                !visited[nrow][ncol]){
                    q.push({nrow , ncol});
                    visited[nrow][ncol] = true;
                }
 
            }
          }
        }
    }

    // Function to find the number of islands.
    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int cnt = 0;

        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (grid[row][col] == '1' && !visited[row][col])
                {
                    cnt++;
                    bfs(row, col, visited, grid);
                }
            }
        }

        return cnt;
    }
};
