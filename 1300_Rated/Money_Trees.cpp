
#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> fruits(n);
        vector<int> heights(n);
        for (int i = 0; i < n; i++)
            cin >> fruits[i];
        for (int i = 0; i < n; i++)
            cin >> heights[i];

        int f = 0;

        int j = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            // if fruit bigger than target itself then just go to next index and make f=0
            if (fruits[i] > k)
            {
                j = i + 1;
                f = 0;
                continue;
            }
            // if current fruit + sum of fruits <=k then include it
            if (fruits[i] + f <= k)
            {
                f += fruits[i];
                ans = max(ans, i - j + 1);
            }
            // decrease the window size until current fruit included
            else
            {
                while (j < i && fruits[i] + f > k)
                {
                    f -= fruits[j];
                    j++;
                }
                f += fruits[i];
                ans = max(ans, i - j + 1);
            }

            // check if divisble of not - if not then j = i+1 ; and i increases so i=j for next iterations

            if (i + 1 < n && heights[i] % heights[i + 1] != 0)
            {
                j = i + 1;
                f = 0;
            }
        }
        cout << ans << endl;
    }
}