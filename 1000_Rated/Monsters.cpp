#include <iostream>
#include <queue>
using namespace std;
struct cmp
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        if (a.first == b.first)
        {
            return a.second > b.second;
        }
        return a.first < b.first;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            int ele;
            cin >> ele;
            ele = ele % (k);
            arr[i] = ele;
            if (ele == 0)
                cout << i + 1 << " ";
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
                continue;
            pq.push({arr[i], i});
        }

        while (!pq.empty())
        {

            int topin = pq.top().second;

            pq.pop();
            cout << topin + 1 << " ";
        }
        cout << endl;
    }
}