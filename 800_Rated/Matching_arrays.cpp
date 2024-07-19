#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        if (n * m == 1)
        {
            cout << -1 << endl;
            int times = n * m;
            while (times--)
            {
                int ele;
                cin >> ele;
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    int element;
                    cin >> element;
                    if (element == n * m)
                        element = 1;
                    else
                        element++;
                    cout << element << " ";
                }
                cout << endl;
            }
        }
    }
}