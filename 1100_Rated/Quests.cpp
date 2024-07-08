// https://codeforces.com/contest/1914/problem/C
#include <iostream>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> first(n);
    vector<int> second(n);
    for (int i = 0; i < n; i++)
        cin >> first[i];
    for (int i = 0; i < n; i++)
        cin >> second[i];

    int ans = 0;
    int sum = 0;
    int maxi = 0;
    int again = 0;
    for (int i = 0; i < min(n, k); i++)
    {
        sum += first[i];
        maxi = max(maxi, second[i]);
        again = k - i - 1;

        int extrasum = again * maxi;
        ans = max(ans, sum + extrasum);
    }
    cout << ans << endl;
}
