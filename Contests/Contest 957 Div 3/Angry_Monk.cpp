#include <iostream>
#include <vector>
#define ll long long
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        vector<int> arr(k);
        for (int i = 0; i < k; i++)
            cin >> arr[i];

        ll maxi = 0;
        int index = -1;
        for (int i = 0; i < k; i++)
        {
            if (arr[i] > maxi)
            {
                maxi = arr[i];
                index = i;
            }
        }
        ll ans = 0;
        ll ones = 0;
        // cout << ans << ones ;
        for (int i = 0; i < k; i++)
        {
            if (i == index)
                continue;
            ans += (arr[i] - 1);
            ones += arr[i];
        }
        // cout << ans-maxi << " " << ones-maxi << endl ;
        cout << ans + ones << endl;
    }
}