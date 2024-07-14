#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
            cin >> ans[i];

        long long ourans = -1e10;
        long long mini = 1e9;
        long long maxi = -1e9;
        for (int i = 0; i < n; i++)
        {
            if (ans[i] < 0 && mini > ans[i])
                ourans = ans[i];
        }
        for (int i = 0; i < n; i++)
        {
            if (ans[i] > maxi)
                maxi = ans[i];
        }
        if (ourans == -1e10)
            ourans = maxi;
        cout << ourans << endl;
    }
}