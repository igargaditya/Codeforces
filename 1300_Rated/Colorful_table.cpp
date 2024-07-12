#include <iostream>
#include <set>
#include <unordered_map>
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
        set<int> st;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            st.insert(arr[i]);
        }

        map<ll, pair<int, int>> mp;
        int p = 1;
        int left = 0;
        int right = n - 1;
        while (left <= right)
        {
            if (arr[left] >= p && arr[right] >= p)
            {
                mp[p] = {left, right};
                p++;
            }
            else if (arr[left] < p)
                left++;
            else if (arr[right] < p)
                right--;
        }

        for (int i = 1; i <= k; i++)
        {
            if (st.find(i) == st.end())
                cout << 0 << " ";
            else
                cout << 2 * (mp[i].second - mp[i].first + 1) << " ";
        }
        cout << endl;
    }
}