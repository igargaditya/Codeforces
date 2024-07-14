#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int x, y, x1, y1, x2, y2;
        cin >> x >> y >> x1 >> y1 >> x2 >> y2;

        long double radius_one = (x1) * (x1) + (y1) * (y1);
        long double radius_two = (x2) * (x2) + (y2) * (y2);
        long double dist_one = (x - x1) * (x - x1) + (y - y1) * (y - y1);
        long double dist_two = (x - x2) * (x - x2) + (y - y2) * (y - y2);
        long double bw = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        // cout << radius_one << "  " << radius_two << "  " << dist_one << "  " << dist_two << endl;
        long double ans = 1e9;

        ans = min(ans, sqrt(max(radius_two, dist_two)));
        ans = min(ans, sqrt(max(radius_one, dist_one)));
        ans = min(ans, max(sqrt(radius_one), max(sqrt(dist_two), (sqrt(bw)) / 2)));

        ans = min(ans, max(sqrt(radius_two), max(sqrt(dist_one), (sqrt(bw)) / 2)));

        cout << fixed << setprecision(10) << ans << endl;
    }
}
