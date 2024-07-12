#include <iostream>
#include <set>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        ll ans = 0;
        set<ll> st;

        if (k % arr[0] == 0)
            st.insert(arr[0]);
        bool flag = 0;
        set<ll> temp;
        for (int i = 1; i < n; i++)
        {
            if (k % arr[i] > 0)
                continue;
            // cout << i << " " ;
            flag = 0;
            temp.clear();
            for (auto it : st)
            {
                ll check = it * arr[i];
                if (k % check)
                    continue;
                else
                    temp.insert(check);
                if (check == k)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
            {
                st.clear();
                ans++;
            }
            else
                for (auto it : temp)
                    st.insert(it);
            if (k % arr[i] == 0)
                st.insert(arr[i]);
        }
        ans++;
        cout << ans << endl;
    }
}