// Finding duplicate in unsorted array
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int A[10] = {8, 3, 6, 4, 6, 5, 6, 8, 2, 7};
    for (int i = 0; i < 10; i++)
    {
        int count = 1;
        for (int j = i + 1; j < 10; j++)
        {
            if (A[i] == A[j])
            {
                count++;
                A[j] = -1;
            }
        }
        if (count > 1 && A[i] != -1)
        {
            cout << A[i] << " repeats " << count << " times" << endl;
        }
    }

    return 0;
}