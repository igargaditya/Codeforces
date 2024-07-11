#include <iostream>
#define ll long long
using namespace std;

int main()
{
    int mod = 1000000007;
    int n;
    cin >> n;
    vector<int> ini(n);
    vector<int> fin(n);
    for (int i = 0; i < n; i++)
        cin >> ini[i];
    for (int i = 0; i < n; i++)
        cin >> fin[i];

    sort(fin.rbegin(), fin.rend());
    sort(ini.rbegin(), ini.rend());
    int j = 0;
    ll ans = 1;
    ll ways = 0;
    for (int i = 0; i < n; i++)
    {

        while (j < n && ini[j] > fin[i])
        {
            ways++;
            j++;
        }
        ans *= ways;
        ans = ans % mod;
        ways--;
    }
    cout << ans << endl;
}