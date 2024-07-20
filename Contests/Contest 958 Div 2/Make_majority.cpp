#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string k;
        cin >> n >> k;
        int ones = 0;
        for (int i = 0; i < n; i++)
        {
            if (k[i] == '1')
                ones++;
        }
        int zerogroup = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (k[i] == '0' && k[i + 1] == '1')
                zerogroup++;
        }
        if (k[n - 1] == '0')
            zerogroup++;
        if (ones > zerogroup)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}