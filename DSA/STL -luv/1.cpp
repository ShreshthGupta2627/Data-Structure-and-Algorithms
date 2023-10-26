// Basics of pair
#include <bits/stdc++.h>
using namespace std;
int main()
{
    pair<int, int> p, p1, p2;
    p.first = 1;
    p.second = 2;
    cout << p.first << " " << p.second << endl;
    swap(p.first, p.second);
    cout << p.first << " " << p.second << endl;
    p1 = make_pair(3, 4);
    p2 = make_pair(4, 5);
    cout << p1.first << " " << p1.second << endl;
    cout << p2.first << " " << p2.second << endl;
    return 0;
}