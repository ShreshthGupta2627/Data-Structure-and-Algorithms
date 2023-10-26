/*Given an expression, A, with operands and operators (OR , AND , XOR), in how many ways can you evaluate the expression to true, by grouping in different ways?
Operands are only true and false.
Return the number of ways to evaluate the expression modulo 103 + 3.
The string A, may contain these characters:
'|' will represent or operator
'&' will represent and operator
'^' will represent xor operator
'T' will represent true operand
'F' will represent false operand
*/
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int ADD(int a, int b)
{
    return (a % MOD + b % MOD) % MOD;
}
int MUL(int a, int b)
{
    return ((a % MOD) * (b % MOD)) % MOD;
}
int rec(int i, int j, int isTrue, string &exp)
{
    if (i > j)
        return 0;
    if (i == j)
    {
        if (isTrue)
        {
            return exp[i] == 'T';
        }
        else
        {
            return exp[i] == 'F';
        }
    }
    int ways = 0;
    for (int ind = i + 1; ind <= j - 1; ind += 2)
    {
        int LT, RT, LF, RF;
        LT = rec(i, ind - 1, 1, exp);
        LF = rec(i, ind - 1, 0, exp);
        RT = rec(ind + 1, j, 1, exp);
        RF = rec(ind + 1, j, 0, exp);

        if (exp[ind] == '&')
        {
            if (isTrue)
            {
                ways = ADD(ways, MUL(LT, RT));
            }
            else
            {
                ways = ADD(ways, MUL(LT, RF));
                ways = ADD(ways, MUL(LF, RT));
                ways = ADD(ways, MUL(LF, RF));
            }
        }
        else if (exp[ind] == '|')
        {
            if (isTrue)
            {
                ways = ADD(ways, MUL(LT, RT));
                ways = ADD(ways, MUL(LF, RT));
                ways = ADD(ways, MUL(RF, LT));
            }
            else
            {
                ways = ADD(ways, MUL(RF, LF));
            }
        }
        else 
        {
            if (isTrue)
            {
                ways = ADD(ways, MUL(RT, LF));
                ways = ADD(ways, MUL(RF, LT));
            }
            else
            {
                ways = ADD(ways, MUL(RT, LT));
                ways = ADD(ways, MUL(RF, LF));
            }
        }
    }
    return ways;
}

int mem(int i, int j, int isTrue, string &exp, vector<vector<vector<int>>> &dp)
{
    if (i > j)
        return 0;
    if (i == j)
    {
        if (isTrue)
        {
            return exp[i] == 'T';
        }
        else
        {
            return exp[i] == 'F';
        }
    }

    if (dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];
    int ways = 0;
    for (int ind = i + 1; ind <= j - 1; ind += 2)
    {
        int LT, RT, LF, RF;
        LT = mem(i, ind - 1, 1, exp, dp);
        LF = mem(i, ind - 1, 0, exp, dp);
        RT = mem(ind + 1, j, 1, exp, dp);
        RF = mem(ind + 1, j, 0, exp, dp);

        if (exp[ind] == '&')
        {
            if (isTrue)
            {
                ways = ADD(ways, MUL(LT, RT));
            }
            else
            {
                ways = ADD(ways, MUL(LT, RF));
                ways = ADD(ways, MUL(LF, RT));
                ways = ADD(ways, MUL(LF, RF));
            }
        }
        else if (exp[ind] == '|')
        {
            if (isTrue)
            {
                ways = ADD(ways, MUL(LT, RT));
                ways = ADD(ways, MUL(LF, RT));
                ways = ADD(ways, MUL(RF, LT));
            }
            else
            {
                ways = ADD(ways, MUL(RF, LF));
            }
        }
        else if (exp[ind] == '^')
        {
            if (isTrue)
            {
                ways = ADD(ways, MUL(RT, LF));
                ways = ADD(ways, MUL(RF, LT));
            }
            else
            {
                ways = ADD(ways, MUL(RT, LT));
                ways = ADD(ways, MUL(RF, LF));
            }
        }
    }
    return dp[i][j][isTrue] = ways;
}
int main()
{
    string exp = "T^T^F";
    int n = exp.size();
    // Ans mem
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));

    cout << mem(0, n - 1, 1, exp, dp) << endl;
    return 0;
}