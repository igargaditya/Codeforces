// https://codeforces.com/contest/1914/problem/A

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int t;
        cin >> t;
        string s;
        cin >> s;
        unordered_map<char, int> mp;
        for (int i = 0; i < t; i++)
        {
            mp[s[i]]++;
        }
        int ans = 0;
        for (auto it : mp)
        {
            char ch = it.first;
            int freq = it.second;
            // cout <<ch << " -> " << ch-'A'+1 << " " << freq << endl ;
            if (ch - 'A' + 1 <= freq)
                ans++;
        }
        cout << ans << endl;
    }
}