#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> take(n);
        vector<int> givesome(n);
        for (int i = 0; i < n; i++)
            cin >> take[i];
        for (int i = 0; i < n; i++)
            cin >> givesome[i];

        int j = n - 1;
        long long coins = 0;
        while (j >= m)
        {
            coins += min(take[j], givesome[j]);
            j--;
        }

        vector<long long> dp(m, 0);
        dp[m - 1] = take[m - 1];
        j = m - 1;
        long long extra = givesome[j];
        j--;
        while (j >= 0)
        {
            dp[j] = extra + take[j];
            extra += givesome[j];
            j--;
        }
        long long mini = 1e12;
        for (int i = 0; i < dp.size(); i++)
            mini = min(mini, dp[i]);

        cout << coins + mini << endl;
    }
}