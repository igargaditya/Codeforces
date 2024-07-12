#include <iostream>

#define ll long long
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        ll n, m, k;
        cin >> n >> m >> k;
        for (ll i = n; i > m; --i)
        {
            cout << i << " ";
        }
        for (ll i = 1; i <= m; ++i)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}