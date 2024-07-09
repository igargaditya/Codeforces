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
        set<string> st;
        int ans = 0;

        for (int i = 0; i < n - 1; i++)
        {

            string temp = string(1, s[i]) + string(1, s[i + 1]);
            if (st.find(temp) == st.end())
            {
                st.insert(temp);
                ans++;
            }
        }
        cout << ans << endl;
    }
}