// https://codeforces.com/contest/1912/problem/L

#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int left = 0;
    int right = 1;
    int lb = 0;
    int lo = 0;
    int rb = 0;
    int ro = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (i == 0)
        {
            if (s[i] == 'L')
                lb++;
            else
                lo++;
        }
        else
        {
            if (s[i] == 'L')
                rb++;
            else
                ro++;
        }
    }
    bool ans = 0;
    if (lo != ro && rb != lb)
    {
        ans = 1;
        cout << 1 << endl;
    }
    if (ans == 0)
    {
        int j = 1;
        cout << "left bread" << lb << " right bread " << rb << endl;
        cout << "left onion" << lo << " right onion " << ro << endl;

        while (j < s.size() && ((lb == rb || lo == ro)))
        {

            if (s[j] == 'L')
            {
                rb--;
                lb++;
            }
            else
            {
                ro--;
                lo++;
            }
            cout << "left bread" << lb << " right bread " << rb << endl;
            cout << "left onion" << lo << " right onion " << ro << endl;
            j++;
        }
        if (j == s.size())
            cout << -1 << endl;
        else
            cout << j << endl;
    }
}
