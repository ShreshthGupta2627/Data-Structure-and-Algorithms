// Basics of upper bound and lower using c++ stl
#include <bits/stdc++.h>
using namespace std;
void f1()
{
    // Check if 'x' exists in a sorted array or not
    int x = 4;
    vector<int> v = {1, 4, 5, 8, 9};
    bool res = binary_search(v.begin(), v.end(), x);
    x = 3;
    bool res1 = binary_search(v.begin(), v.end(), x);
    cout << res << " " << res1 << endl;
}

void f2()
{
    // Finding lower bound
    // Lower bound return iterator to that element if found else it points to next greater element and if the element req > last element then
    int x = 1;
    vector<int> v = {1, 4, 5, 6, 9, 9};
    int ind1 = lower_bound(v.begin(), v.end(), x) - v.begin();
    // without -v.begin() it will give iterator
    x = 7;
    int ind2 = lower_bound(v.begin(), v.end(), x) - v.begin();
    x = 10;
    int ind3 = lower_bound(v.begin(), v.end(), x) - v.begin();
    cout << ind1 << " " << ind2 << " " << ind3 << endl;
}

void f3()
{
    // finding upper bound
    // Upper bound always give iterator to next greater element even if it exists
    int x = 1;
    vector<int> v = {1, 4, 5, 6, 9, 9};
    int ind1 = upper_bound(v.begin(), v.end(), x) - v.begin();
    // without -v.begin() it will give iterator
    x = 6;
    int ind2 = upper_bound(v.begin(), v.end(), x) - v.begin();
    x = 9;
    int ind3 = upper_bound(v.begin(), v.end(), x) - v.begin();
    x = 10;
    int ind4 = upper_bound(v.begin(), v.end(), x) - v.begin();
    cout << ind1 << " " << ind2 << " " << ind3 << " " << ind4 << endl;
}

void f4()
{
    // Q. Find the first occurence of 'x' in sorted array if not found print -1;
    vector<int> v = {1, 4, 4, 5, 6, 9, 9, 10, 11};
    int x = 4;
    int ind = lower_bound(v.begin(), v.end(), x) - v.begin();
    if (ind != v.size() && v[ind] == x)
        cout << ind << endl;
    else
        cout << -1 << endl;
}

void f5()
{
    // Q. Find the last occurence of 'x' in sorted array if not found print -1;
    vector<int> v = {1, 4, 4, 4, 4, 9, 9, 10, 11};
    int x = 4;
    int ind = upper_bound(v.begin(), v.end(), x) - v.begin();
    ind--; // up points to nxt
    if (ind >= 0 && v[ind] == x)
        cout << ind << endl;
    else
        cout << -1 << endl;
}

void f6()
{
    // Q. Find the largest number smaller then 'x' if not found print -1
    vector<int> v = {1, 4, 4, 4, 4, 9, 9, 10, 11};
    int x = 11;
    int ind = lower_bound(v.begin(), v.end(), x) - v.begin();
    ind--;
    if (ind >= 0)
        cout << v[ind] << endl;
    else
        cout << -1 << endl;
}

void f7()
{
    // Q. Find the smallest number greater then 'x' if not found print -1
    vector<int> v = {1, 4, 4, 4, 4, 9, 9, 10, 11};
    int x = 10;
    int ind = upper_bound(v.begin(), v.end(), x) - v.begin();
    if (ind < v.size())
        cout << v[ind] << endl;
    else
        cout << -1 << endl;
}

int main()
{
    // all works in log(n) i.e. similar to binary search
    f1();
    f2();
    f3();
    f4();
    f5();
    f6();
    f7();
    return 0;
}