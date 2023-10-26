// Flood fill algorithm
#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    void dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>> &image, int newColor, int *delRow, int *delCol, int iniColor)
    {
        int n = image.size();
        int m = image[0].size();
        ans[row][col] = newColor;
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor)
            {
                dfs(nrow, ncol, ans, image, newColor, delRow, delCol, iniColor);
            }
        }
    }

public:
    vector<vector<int>> floodfill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        dfs(sr, sc, ans, image, newColor, delRow, delCol, iniColor);
        return ans;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> image = {{1, 1, 1}, {2, 2, 0}, {2, 2, 2}};
    int sr = 2, sc = 0, newColor = 3;
    vector<vector<int>> ansf = s.floodfill(image, sr, sc, newColor);
    for (int i = 0; i < ansf.size(); i++)
    {
        for (int j = 0; j < ansf[i].size(); j++)
        {
            cout << ansf[i][j] << " ";
        }
        cout << endl;
    }
    // TC = O(M*N)    SC = O(N*M) + O(N*M) stck space
    return 0;
}