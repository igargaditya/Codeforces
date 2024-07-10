// https://codeforces.com/contest/1791/problem/D

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    unordered_map<char, int> left;
    unordered_map<char, int> right;
    left[s[0]]++;
    for (int i = 1; i < n; i++)
    {
        right[s[i]]++;
    }
    int ans = left.size() + right.size();
    for (int i = 1; i < n; i++)
    {
        char element = s[i];
        if (left.find(element) == left.end())
        {
            left[element] = 1;
        }
        right[element]--;
        if (right[element] == 0)
            right.erase(element);

        ans = max(ans, left.size() + right.size());
    }
    cout << ans << endl;
}