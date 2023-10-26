// N-Queens
/* The n-queens is the problem of placing n queens on n × n chessboard such that no two queens can attack each other. Given an integer n, return all distinct solutions to the n -queens puzzle. Each solution contains a distinct boards configuration of the queen’s placement, where ‘Q’ and ‘.’ indicate queen and empty space respectively.
 */
#include <bits/stdc++.h>
using namespace std;
// Since we need to generate all possible ways :. Use recursion
// Try to place queen coloumn wise by following rule if rule are not followed just backtrack to prev state
bool isSafe(int row, int col, vector<string> &board, int n)
{
    // We are moving from left to right i col :. no need to chk for right and also we are not placing quees in up or down :. we have to chk for (i-1,j-1),(i,j-1),(i+1,j-1)

    int duprow = row, dupcol = col;
    while (row >= 0 && col >= 0)
    {
        // for upper dig chk
        if (board[row][col] == 'Q')
            return false;
        col--;
        row--;
    }

    row = duprow, col = dupcol;
    while (col >= 0)
    {
        // in same row
        if (board[row][col] == 'Q')
            return false;
        col--;
    }
    row = duprow, col = dupcol;
    while (row < n && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row++;
        col--;
    }
    return true;
}
// Chk for possibility in better way : for chk in row we can maintain a hash of size n and for dig. we can use the concept that the sum (i+j) remain same in dig of sq (dig with angle = 45deg in anti clockwise dirn for lower dig and angle =135deg for upper dig) :. for size n we can maintain a hash of sine 2n-1 to store dig queens value
void solve2(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftRow, vector<int> &UpperDig, vector<int> &LowerDig, int n)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (leftRow[row] = 0 && LowerDig[row + col] == 0 && UpperDig[row + col] == 0)
        {
            board[row][col] = 'Q';
            leftRow[row] = 1;
            LowerDig[row + col] = 1;
            UpperDig[n - 1 + col - row] = 1;
            solve2(col + 1, board, ans, leftRow, UpperDig, LowerDig, n);
            board[row][col] = '.';
            leftRow[row] = 0;
            LowerDig[row + col] = 0;
            UpperDig[n - 1 + col - row] = 0;
        }
    }
}
void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {
            board[row][col] = 'Q';
            solve(col + 1, board, ans, n);
            board[row][col] = '.';
        }
    }
}
vector<vector<string>> SolveNQueen(int n)
{
    vector<vector<string>> ans;
    string s(n, '.');
    vector<string> board(n, s);
    solve(0, board, ans, n);
    return ans;
}
int main()
{
    int n = 4;
    vector<vector<string>> ans = SolveNQueen(n);
    for (auto &it : ans)
    {
        for (auto &i : it)
        {
            cout << i << endl;
        }
        cout << endl;
    }
    return 0;
}