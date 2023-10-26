#include <bits/stdc++.h>
using namespace std;
// If our eqn depend on prev k term then the state matrix will be of k * k and multiplication with it will convert from {f1,f2,f3.....fk} to {f2,f3,f4......f(k+1)}
// Solve [f1 f2]*|P  Q| = [f2 f3]
//               |R  S|

// By above way we found a tarnsition state matrix not to reack kth stage just multily [f1 f2] with (state matrix)^(k-1)
//:. We can use matrix exponentiation to reduce time in calculating (state matrix or tansition matrix)^(k-1)
int I[3][3], T[3][3], fib[3]; // I is identity matrix and T is the transition matrix
void mul(int A[3][3], int B[3][3], int dim)
{
    int res[dim + 1][dim + 1];
    for (int i = 1; i <= dim; i++)
    {
        for (int j = 1; j <= dim; j++)
        {
            res[i][j] = 0;
            for (int k = 1; k <= dim; k++)
            {
                res[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    for (int i = 1; i <= dim; i++)
    {
        for (int j = 1; j <= dim; j++)
        {
            A[i][j] = res[i][j];
        }
    }
}
int getfib(int n)
{
    if (n <= 2)
        return fib[n];
    I[1][1] = I[2][2] = 1;
    I[1][2] = I[2][1] = 0;
    T[1][1] = 0;
    T[1][2] = T[2][1] = T[2][2] = 1;
    // for n we need pow n-1
    n--;
    while (n)
    {
        if (n & 1)
        {
            mul(I, T, 2);
            n--;
        }
        else
        {
            mul(T, T, 2);
            n /= 2;
        }
    }
    int fib_n = fib[1] * I[1][1] + fib[2] * I[2][1];
    return fib_n;
}
int main()
{
    int n;
    cin >> fib[1] >> fib[2] >> n;
    n++;
    cout << getfib(n);
    return 0;
}