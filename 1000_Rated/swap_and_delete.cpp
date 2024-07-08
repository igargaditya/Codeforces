// https://codeforces.com/contest/1913/problem/B
#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        int one = 0;
        int zero = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
                zero++;
            else
                one++;
        }

        int t = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0' && one > 0)
            {
                t++;
                one--;
            }
            else if (s[i] == '0' && one <= 0)
                break;
            else if (s[i] == '1' && zero > 0)
            {
                t++;
                zero--;
            }
            else if (s[i] == '1' && zero <= 0)
                break;
        }

        cout << n - t << endl;
    }
}
