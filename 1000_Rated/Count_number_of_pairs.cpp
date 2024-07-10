#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        unordered_map<int, pair<int, int>> mp;
        for (int i = 0; i < n; i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                mp[s[i] - 'a'].first++;
            }
            else
            {
                mp[s[i] - 'A'].second++;
            }
        }

        int ans = 0;
        for (auto it : mp)
        {

            int small = it.second.first;
            int big = it.second.second;
            int mini = min(big, small);

            ans += mini;
            small -= mini;
            big -= mini;
            if (k >= 1 && small >= 2)
            {
                ans += (min(k, small / 2));
                k -= (min(k, small / 2));
            }
            if (k >= 1 && big >= 2)
            {
                ans += (min(k, big / 2));
                k -= (min(k, big / 2));
            }
        }
        cout << ans << endl;
    }
}