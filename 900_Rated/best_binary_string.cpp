// https://codeforces.com/contest/1837/problem/C
#include <iostream>
using namespace std;
int main()
{
    string s;
    cin >> s;
    if (s[0] == '?')
        s[0] = '0';
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == '?')
            s[i] = s[i - 1];
    }
    cout << s << endl;
}