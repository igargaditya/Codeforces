#include <iostream>
#include <set>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int x = 0;
        int y = 0;
        bool found = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'U')
                y++;
            else if (s[i] == 'D')
                y--;
            else if (s[i] == 'L')
                x--;
            else
                x++;
            if (x == 1 && y == 1)
            {
                found = 1;
                cout << "YES" << endl;
                break;
            }
        }
        if (found == 0)
            cout << "NO" << endl;
    }
}