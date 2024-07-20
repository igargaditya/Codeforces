#include <iostream>
using namespace std;
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end(), cmp);

        bool ans = 0;
        for (int i = 0; i < n - 1; i += 2)
        {
            if (arr[i + 1] == arr[i])
            {
                continue;
            }
            else
            {
                ans = 1;
                break;
            }
        }
        if (ans == 0 && n & 1)
            cout << "YES" << endl;
        else if (ans)
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
}