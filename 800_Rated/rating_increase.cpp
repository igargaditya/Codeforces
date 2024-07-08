// https://codeforces.com/contest/1913/problem/A

#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int num1 = 0;
    int num2 = 0;
    bool ans = 0;
    for (int i = 0; i < s.size() - 1; i++)
    {
        num1 = num1 * 10 + (s[i] - '0');
        if (s[i + 1] != '0')
        {
            num2 = stoi(s.substr(i + 1));
        }
        if (num1 < num2)
        {
            ans = 1;
            cout << num1 << " " << num2 << endl;
            break;
        }
    }
    if (ans == 0)
        cout << -1 << endl;
}