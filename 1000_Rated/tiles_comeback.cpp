#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int sk = 0;
        int send = -1;
        int ek = 0;
        int eend = -1;
        int s1 = arr[0];
        int e1 = arr[n - 1];
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == s1)
            {
                sk++;
                if (sk == k)
                    send = i;
            }
            if (arr[n - i - 1] == e1)
            {
                ek++;
                if (ek == k)
                    eend = n - i - 1;
            }
        }
        // cout << sk << ek << send << eend << endl ;
        if (s1 == e1)
        {
            if (sk >= k)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else
        {
            if (sk >= k && ek >= k && send < eend)
            {
                cout << "YES" << endl;
            }
            else
                cout << "NO" << endl;
        }
    }
}