#include <bits/stdc++.h>
using namespace std;
int main()
{
    // pairs can directly be compared i.e 1st on basis of first element then on the basis of second element
    // Similar hold for set
    // Q. Sort first with marks then withlexographic name
    map<int, multiset<string>> mp;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int marks;
        string name;
        cin >> name >> marks;
        mp[-1 * marks].insert(name);
    }
    for (auto &marks_student_pair : mp)
    {
        auto &students = marks_student_pair.second;
        int marks = marks_student_pair.first;
        for (auto &s : students)
        {
            cout << s << " " << -1 * marks << endl;
        }
    }
    return 0;
}