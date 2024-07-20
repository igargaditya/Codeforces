#include <iostream>
#include <vector>
using namespace std;
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        long long x, y;
        cin >> x >> y;
        vector<long long> ans(n + 1, 1);

        for (long long i = y - 1; i >= 1; i--)
        {
            if (((y - i) & 1) == 1)
                ans[i] = -1;
            else
                ans[i] = 1;
        }
        // alternate rkho
        for (long long i = x + 1; i <= n; i++)
        {
            if (((x - i) & 1) == 1)
                ans[i] = -1;
            else
                ans[i] = 1;
        }
        // beech already 1
        // alternate rkho
        for (long long i = 1; i <= n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}