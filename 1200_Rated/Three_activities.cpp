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
        vector<pair<int, int>> a(n);
        vector<pair<int, int>> b(n);
        vector<pair<int, int>> c(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i].first;
            b[i].second = i;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> c[i].first;
            c[i].second = i;
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());

        cout << endl;
        int ans = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int z = 0; z < 3; z++)
                {
                    if (a[n - 1 - i].second != b[n - 1 - j].second && a[n - 1 - i].second != c[n - 1 - z].second && b[n - 1 - j].second != c[n - 1 - z].second)
                    {
                        // cout << i << " " << j << " " << z << "->"  ;
                        ans = max(ans, a[n - 1 - i].first + b[n - 1 - j].first + c[n - 1 - z].first);
                        // cout << ans <<endl ;
                    }
                }
            }
        }
        cout << ans << endl;
    }
}