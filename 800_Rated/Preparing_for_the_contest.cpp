// https://codeforces.com/contest/1914/problem/B

#include <iostream>

using namespace std;

int main()
{

    int n, k;
    cin >> n >> k;

    vector<int> ans(n);
    if (k == 0)
    {
        for (int i = n; i > 0; i--)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    else
    {
        cout << 1 << " ";
        int twoenter = n - k - 1;
        int lastinsert = n;
        while (twoenter--)
        {
            cout << n << " ";
            n--;
        }
        int lastelement = n;
        for (int i = 2; i <= lastelement; i++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}