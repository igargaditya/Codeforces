#include <iostream>

using namespace std;
int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}
class dis
{
public:
    vector<pair<int, int>> parent;
    vector<int> size;
    dis(int n, int m, vector<vector<int>> grid)
    {
        parent.resize(n * m);
        size.resize(n * m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                parent[i * n + j] = {i, j};
                size[i * n + j] = grid[i][j];
            }
        }
    }
    pair<int, int> findparent(int x, int y, int n, int m)
    {
        if (parent[x * n + y].first == x && parent[x * n + y].second == y)
            return {x, y};
        return parent[x * n + y] = findparent(parent[x * n + y].first, parent[x * n + y].second, n, m);
    }

    void unionbysize(int x1, int y1, int x2, int y2, int n, int m)
    {
        pair<int, int> up = findparent(x1, y1, n, m);
        pair<int, int> vp = findparent(x2, y2, n, m);
        if (vp.first == up.first && vp.second == up.second)
            return;
        if (size[up.first * n + up.second] > size[vp.first * n + vp.second])
        {
            size[up.first * n + up.second] += size[vp.first * n + vp.second];
            parent[vp.first * m + vp.second] = {up.first, up.second};
        }
        else
        {
            size[vp.first * n + vp.second] += size[up.first * n + up.second];
            parent[up.first * n + up.second] = {vp.first, vp.second};
        }
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        dis d(n, m, grid);

        int delrow[] = {0, -1, 0, 1};
        int delcol[] = {1, 0, -1, 0};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 0)
                {
                    // cout << i << " " << j << "SKipped" << endl ;
                    continue;
                }

                for (int k = 0; k < 4; k++)
                {
                    int x = delrow[k] + i;
                    int y = delcol[k] + j;
                    if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != 0)
                    {
                        pair<int, int> vp = d.findparent(x, y, n, m);
                        if (vp.first == i && vp.second == j)
                            continue;
                        else
                        {
                            d.unionbysize(x, y, i, j, n, m);
                            if (i == 1 && j == 0)
                            {
                                // cout << "VALUES " << d.size[i*n+j] << " " << d.size[x*n+y];
                                // cout << d.findparent(x,y,n,m).first << d.findparent(x,y,n,m).second<< endl  ;
                            }
                        }
                    }
                }
            }
        }
        int ans = 0;

        for (int i = 0; i < n * m; i++)
        {

            ans = max(d.size[i], ans);
        }
        cout << ans << " " << endl;
    }
}
