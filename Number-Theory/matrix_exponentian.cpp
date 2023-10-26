#include <bits/stdc++.h>
using namespace std;
class naive
{
private:
    vector<vector<int>> mul(vector<vector<int>> &res, vector<vector<int>> &mat)
    {
        vector<vector<int>> ans(mat.size(), vector<int>(mat[0].size(), 0));
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat.size(); j++)
            {
                for (int k = 0; k < mat.size(); k++)
                {
                    ans[i][j] += res[i][k] * mat[k][j];
                }
            }
        }
        return ans;
    }

public:
    vector<vector<int>> solve(vector<vector<int>> &mat, int n)
    {
        // pow( A( m * m ) , n ) we will use binary exponentiation to reduce the time complexity from O(m^3*n) to O(m^3*log(n))
        vector<vector<int>> res(mat.size(), vector<int>(mat[0].size(), 0));
        // mat.size() =  mat[0].size()
        for (int i = 0; i < mat.size(); i++)
        {
            res[i][i] = 1;
        }
        // Identity matrix is being created
        for (int i = 0; i < n; i++)
        {
            res = mul(res, mat);
        }
        // return res;
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat.size(); j++)
            {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
    }
};
class optimized
{
private:
    vector<vector<int>> mul(vector<vector<int>> &res, vector<vector<int>> &mat)
    {
        vector<vector<int>> ans(mat.size(), vector<int>(mat[0].size(), 0));
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat.size(); j++)
            {
                for (int k = 0; k < mat.size(); k++)
                {
                    ans[i][j] += res[i][k] * mat[k][j];
                }
            }
        }
        return ans;
    }

public:
    vector<vector<int>> solve(vector<vector<int>> &mat, int n)
    {
        vector<vector<int>> res(mat.size(), vector<int>(mat[0].size(), 0));
        for (int i = 0; i < mat.size(); i++)
        {
            res[i][i] = 1;
        }
        while (n)
        {
            if (n & 1)
            {
                res = mul(res, mat);
                n--;
            }
            else
            {
                res = mul(mat, mat);
                n /= 2;
            }
        }
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat.size(); j++)
            {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
    }
};
int main()
{
    vector<vector<int>> res = {{2, 0, 0}, {0, 2, 0}, {0, 0, 2}};
    naive n;
    n.solve(res, 3);
    optimized O;
    O.solve(res, 4);
    return 0;
}