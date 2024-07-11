#include <iostream>
#include <list>
#include <queue>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, y;
        cin >> n >> y;
        vector<int> visted(n + 1, 0);
        vector<int> indegree(n + 1, 0);
        unordered_map<int, list<int>> adj;
        for (int i = 0; i < y; i++)
        {
            int f, s;
            cin >> f >> s;
            adj[f].push_back(s);
            adj[s].push_back(f);
            indegree[f]++;
            indegree[s]++;
        }

        queue<int> q;
        int leaf = 0;
        for (int i = 1; i <= n; i++)
        {
            if (indegree[i] == 1)
            {
                q.push(i);
                leaf++;
                visted[i] = 1;
            }
        }
        // cout << "LEAFS " << leaf << endl ;
        int first = 0;
        int level = 0;

        while (!q.empty())
        {
            int size = q.size();
            level++;
            for (int i = 0; i < size; i++)
            {
                int top = q.front();
                q.pop();
                for (auto it : adj[top])
                {
                    if (visted[it] == 0)
                    {
                        q.push(it);
                        if (level == 1)
                            first++;
                        visted[it] = 1;
                    }
                }
            }
        }
        // cout << leaf << " " << first << endl ;
        int mid = leaf / first;
        cout << first << " " << mid << endl;
    }
}