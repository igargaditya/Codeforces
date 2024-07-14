#include <iostream>
using namespace std;
bool prime(int n)
{
    if (n <= 1)
    {
        return false;
    }
    if (n <= 3)
    {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0)
    {
        return false;
    }
    for (int i = 5; i * i <= n; i = i + 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    if (prime(n) == 0 && prime(m) == 0)
    {
        int ele = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << ele++ << " ";
            }
        }
    }
    else if (prime(n) == 1 && prime(m) == 1)
    {
        int ele = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << ele++ << " ";
            }
        }
        cout << ele << " ";
        ele = n * m;
        for (int i = 1; i < n; i++)
        {
            cout << ele << " ";
            ele--;
        }
    }
    else if (prime(n) == 1)
    {
        int ele = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << ele << " ";
            }
        }
    }
    else if (prime(m) == 1)
    {
        int ele = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << ele << " ";
            }
        }
    }
}