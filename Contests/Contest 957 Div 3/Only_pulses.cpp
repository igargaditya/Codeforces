#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(x);
        pq.push(y);
        pq.push(z);
        int n = 5;
        while (n)
        {
            int top = pq.top();
            pq.pop();
            pq.push(top + 1);
            n--;
        }

        int ans = 1;
        while (!pq.empty())
        {
            ans *= pq.top();
            pq.pop();
        }
        cout << ans << endl;
    }
}