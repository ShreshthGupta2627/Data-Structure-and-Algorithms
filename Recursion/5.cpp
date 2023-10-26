// Problem on functional recursion
#include <bits/stdc++.h>
using namespace std;
// Reverse array using recursion
void swapp(int *A, int i, int j)
{
    if (i >= j)
    {
        return;
    }
    swap(A[i], A[j]);
    // Intead of j we can also use n-i-1
    swapp(A, i + 1, j - 1);
}

// checking string as palindrome
bool chk_pald(string s, int i, int j)
{
    if (i >= s.length() / 2)
        return true;
    if (s[i] != s[j])
        return false;
    return chk_pald(s, i + 1, j - 1);
}
int main()
{
    int n = 5, i, j;
    int A[5] = {1, 2, 3, 4, 5};
    i = 0, j = n - 1;
    swapp(A, i, j);
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }

    string s = "aba";
    int i = 0, j = s.length() - 1;
    cout << chk_pald(s, i, j);
}