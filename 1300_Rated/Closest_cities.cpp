#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> arr[i];

        vector<int> dp(n + 1);
        dp[1] = 2;
        dp[n] = n - 1;
        for (int i = 2; i < n; i++)
        {
            if (abs(arr[i - 1] - arr[i]) > abs(arr[i + 1] - arr[i]))
                dp[i] = i + 1;
            else
                dp[i] = i - 1;
        }
        vector<int> lr(n + 2, 0);
        vector<int> rl(n + 2, 0);
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            lr[i] = sum;

            if (dp[i] == i + 1)
                sum += 1;
            else
                sum += arr[i + 1] - arr[i];
        }
        sum = 0;
        for (int i = n; i >= 1; i--)
        {
            rl[i] = sum;
            if (dp[i] == i - 1)
                sum += 1;
            else
                sum += arr[i] - arr[i - 1];
        }
        // cout << "LEFT SUM " << endl;

        // for (int i = 1; i <= n; i++)
        // {
        //     cout << lr[i] << " ";
        // }
        // cout << "RIGHT SUM " << endl;

        // for (int i = n; i >= 1; i--)
        // {
        //     cout << rl[i] << " ";
        // }
        int m;
        cin >> m;

        while (m--)
        {
            int first;
            cin >> first;
            int second;
            cin >> second;
            if (first <= second)
            {
                cout << lr[second] - lr[first] << endl;
            }
            else
            {
                cout << rl[second] - rl[first] << endl;
            }
        }
    }
}