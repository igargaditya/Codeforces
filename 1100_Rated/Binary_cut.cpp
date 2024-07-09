#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int ans = 1;
    int pair = 0;
    for (int i = 1; i < n; i++)
    {
        if (s[i] != s[i - 1])
            ans++;
        if (s[i] == '1' && s[i - 1] == '0')
            pair = 1;
    }

    cout << ans - pair << endl;
}