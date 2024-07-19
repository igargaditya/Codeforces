#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        int k;
        cin >> n >> k;
        int ans = 0;
        while (n > 1)
        {
            ans++;
            n -= (k - 1);
        }
        cout << ans << endl;
    }
}