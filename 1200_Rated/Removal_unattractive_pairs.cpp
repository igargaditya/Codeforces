#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        unordered_map<char, int> mp;
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            mp[s[i]]++;
            maxi = max(maxi, mp[s[i]]);
        }
        if (maxi >= (n + 1) / 2)
        {
            cout << 2 * maxi - n << endl;
        }
        else
            cout << (n & 1) << endl;
    }
}