#include <iostream>
using namespace std;
bool f(long long mid, long long n)
{
    long long temp = 0;

    if (mid & 1)
    {
        temp = (mid) * ((mid + 1) / 2);
    }
    else
        temp = (mid / 2) * (mid + 1);

    if (temp > n)
        return 1;
    return 0;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;

        long long low = 0;
        long long high = min<long long>(2e9, 2 * n);
        long long ans = 0;
        while (low <= high)
        {
            long long mid = (low) + (high - low) / 2;
            // cout << mid << " ";
            bool check = f(mid, n);
            if (check == 0)
            {
                low = mid + 1;
            }
            else
            {
                ans = mid;
                high = mid - 1;
            }
        }
        int hmm = ans;
        ans--;
        long long temp = 0;
        if (ans & 1)
        {
            temp = ((ans)) * ((ans + 1) / 2);
        }
        else
            temp = (ans / 2) * ((ans + 1));

        cout << hmm + (n - temp) << endl;
    }
}
