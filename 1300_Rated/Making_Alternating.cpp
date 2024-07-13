#include <iostream>
#define ll long long
using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;

        vector<ll> dp;
        ll ans = 0;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == s[i - 1])
                ans++;
        }

        ll ways = 1;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == s[i - 1])
            {
                ways++;
                if (i == s.size() - 1)
                    dp.push_back(ways);
            }
            else
            {
                dp.push_back(ways);
                ways = 1;
            }
        }
        ll sum = 1;
        ll ansfact;
        if (ans == 0)
            ansfact = 1;
        else
            ansfact = ans;

        ll fac = 1;
        while (ansfact != 1)
        {
            fac = (fac * (ansfact % 998244353)) % 998244353;
            ansfact--;
        }
        for (int i = 0; i < dp.size(); i++)
        {
            sum = (sum * (dp[i] % 998244353) % 998244353);
        }

        cout << ans << " " << (sum * (fac % 998244353)) % 998244353 << endl;
    }
}