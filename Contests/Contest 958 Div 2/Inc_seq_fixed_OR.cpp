#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> ans;
        if ((n & (n - 1)) == 0)
        {
            cout << 1 << endl;
            cout << n << endl;
        }
        else
        {
            ans.push_back(n);
            for (int i = 0; i < 64; i++)
            {
                int bit = (n >> i) & 1;
                // cout << bit << " " ;
                if (bit == 1)
                {
                    long long temp = 1;
                    temp = temp << i;
                    temp = ~temp;
                    long long add = temp & n;
                    if (add <= 1e18)
                        ans.push_back(add);
                }
            }
            cout << ans.size() << endl;
            for (int i = ans.size() - 1; i >= 0; i--)
            {
                cout << ans[i] << " ";
            }
            cout << endl;
        }
    }
}