#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <cassert>

#define SEA 0
#define LAND 1

using namespace std;

class Solution {
public:
    void    displayMat(vector<vector<int>> grid)
    {
        for (int i=0; i < grid.size(); i++)
        {
            for (int j=0; j < grid[0].size(); j++)
            {
                cout << grid[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
    void    dfs(int i, int j, int m, int n, vector<vector<int>>& grid)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != LAND)
            return;

        grid[i][j] = 0;
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        for(int k=0;k<4;k++){
            int nx = i + dx[k];
            int ny = j + dy[k];
            dfs(nx, ny, m, n, grid);
        }
        return;
    }

    bool isBorder(int i, int j, int m, int n)
    {
        if (i*j == 0 || i == m-1 || j == n-1)
            return true;
        return false;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isBorder(i, j, m, n) && grid[i][j] == LAND)
                    dfs(i, j, m, n, grid);
            }
        }

        int enclaves = 0;
        for (int i = 0; i < m; i++)
            enclaves += std::count(grid[i].begin(), grid[i].end(), LAND);
        return enclaves;
    }
};



int main()
{
    {
        vector<vector<int>> grid = {{0,0,0,0}, {1,0,1,0},{0,1,1,0},{0,0,0,0}};
        Solution test;
        test.numEnclaves(grid);
    }
    cout << "\n";
    {
        vector<vector<int>> grid = {{0,1,1,0},{0,0,1,0},{0,0,1,0},{0,0,0,0}};
        Solution test;
        test.numEnclaves(grid);
    }
    return 0;
}