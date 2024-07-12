#include <iostream>

using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int size, jump, swim;
        cin >> size >> jump >> swim;
        vector<char> arr(size);
        for (int i = 0; i < size; i++)
            cin >> arr[i];

        int temp = jump;
        bool ans = 0;
        for (int i = 0; i < size; i++)
        {
            temp--;
            if (arr[i] == 'L')
            {
                temp = jump;
            }
            else if (arr[i] == 'W' && temp <= 0 && swim > 0)
            {
                swim--;
            }
            else if (arr[i] == 'W' && temp <= 0 && swim <= 0)
            {
                cout << "NO" << endl;
                ans = 1;
                break;
            }
            else if (arr[i] == 'C' && temp <= 0)
            {
                cout << "NO" << endl;
                ans = 1;
                break;
            }
        }
        if (ans == 0)
            cout << "YES" << endl;
    }
}