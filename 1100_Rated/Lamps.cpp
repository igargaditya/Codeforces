// https://codeforces.com/contest/1839/problem/B

#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
static bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> vec(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> vec[i].first >> vec[i].second;
        }
        sort(vec.begin(), vec.end(), cmp);

        int on = 0;
        int i = 0;
        int j = 0;
        ll score = 0;
        int off = 0;
        while (i < n && j < n)
        {
            score += vec[j++].second;
            on++;
            off = 0;
            while (i < n && vec[i].first <= on)
            {
                i++;
                off++;
            }
            on = max(0, on - off);

            if (i >= j)
                j = i;
        }
        cout << score << endl;
    }
}