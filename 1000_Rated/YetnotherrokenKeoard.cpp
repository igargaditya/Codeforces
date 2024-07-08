// https://codeforces.com/problemset/problem/1907/B

// yet another broken keyboard

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

        int small = 0;
        int large = 0;
        string ans = "";
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == 'b')
                small++;
            else if (s[i] == 'B')
                large++;
            else if (small > 0 && s[i] >= 'a' && s[i] <= 'z')
            {
                small--;
            }
            else if (large > 0 && s[i] >= 'A' && s[i] <= 'Z')
            {
                large--;
            }
            else
            {
                ans += s[i];
            }
        }
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
}