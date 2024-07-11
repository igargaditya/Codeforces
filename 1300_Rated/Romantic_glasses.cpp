#include <iostream>
#include <vector>
#include <set>
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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        for (int i = 0; i < n; i += 2)
        {
            arr[i] = -1 * arr[i];
        }
        set<ll> st;
        st.insert(0);
        ll pref = 0;
        bool ans = 0;
        for (int i = 0; i < n; i++)
        {
            pref += arr[i];
            if (st.find(pref) == st.end())
                st.insert(pref);
            else
            {
                cout << "YES" << endl;
                ans = 1;
                break;
            }
        }

        if (ans == 0)
            cout << "NO" << endl;
    }
}