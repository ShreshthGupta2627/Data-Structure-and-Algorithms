// Iterators in stl
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v = {2, 3, 4, 5, 6, 7};
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    vector<int>::iterator it;
    it = v.begin();
    cout << *it << " ";
    cout << *(it + 1) << " ";
    cout << *(it + 2) << " ";
    cout << *(it + 3) << " ";
    cout << *(it + 4) << " ";
    cout << *(it + 5) << " ";
    cout << endl;
    for (it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    vector<pair<int, int>> v_p = {{1, 2}, {3, 4}, {5, 6}};
    vector<pair<int, int>>::iterator it1;
    for (it1 = v_p.begin(); it1 != v_p.end(); it1++)
    {
        cout << it1->first << " " << (*it1).second << "   ";
    }
    cout << endl;
    for (pair<int, int> value : v_p)
    {
        cout << value.first << " " << value.second << "  ";
    }
    cout << endl;
    // Reducing code length for using iterators
    // range based loop
    for (int value : v)
    {
        cout << value << " ";
    }
    cout << endl;
    // This loop work in all container , actually a copy of element is stored in value to change actual value use refference i.e. &value
    // auto directly determine datatype of iterartor
    // Below like statement can be skipped using auto
    //   vector<pair<int, int>>::iterator it1;
    vector<pair<int, int>> v_p2 = {{1, 2}, {3, 4}, {5, 6}};
    for (auto value : v_p2)
    {
        cout << value.first << " " << value.second << "   ";
    }
    cout << endl;
    return 0;
}