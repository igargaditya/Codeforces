#include <iostream>

#define ll long long
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<ll, ll>> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].first;
            arr[i].second = i;
        }

        sort(arr.begin(), arr.end());
        vector<pair<ll, ll>> dp(n);

        ll sum = arr[0].first;
        int i = 1;
        while (i < n && sum >= arr[i].first)
        {
            cout << "running for" << i << endl;
            cout << sum << endl;
            sum += arr[i].first;
            i++;
        }
        dp[0].first = i;
        dp[0].second = sum;

        for (int i = 1; i < n; i++)
        {
            ll previndex = dp[i - 1].first;
            ll prevsum = dp[i - 1].second;
            // cout << previndex ;
            if (previndex == i)
            {
                prevsum += arr[previndex].first;
                previndex++;
            }
            while (previndex < n && prevsum >= arr[previndex].first)
            {
                prevsum += arr[i].first;
                previndex++;
            }

            dp[i].first = previndex;
            dp[i].second = prevsum;
        }

        vector<ll> ans(n);
        for (int i = 0; i < n; i++)
        {
            ans[arr[i].second] = dp[i].first - 1;
        }
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}