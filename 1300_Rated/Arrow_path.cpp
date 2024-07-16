#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<char>> arr(2, vector<char>(n));
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }

        vector<int> delrow{-1, 0, 1, 0};
        vector<int> delcol{0, 1, 0, -1};

        vector<vector<bool>> visted(2, vector<bool>(n, 0));
        visted[0][0] = 1;
        queue<pair<int, int>> pq;
        pq.push({0, 0});
        bool found = 0;
        while (!pq.empty())
        {
            int i = pq.front().first;
            int j = pq.front().second;
            if (i == 1 && j == n - 1)
            {
                found = 1;
                break;
            }
            pq.pop();
            for (int del = 0; del < 4; del++)
            {
                int x = delrow[del] + i;
                int y = delcol[del] + j;

                if (x >= 0 && x < 2 && y >= 0 && y < n && visted[x][y] == 0)
                {

                    if (arr[x][y] == '>')
                        y++;
                    else
                        y--;

                    if (y >= 0 && y < n && visted[x][y] == 0)
                    {
                        visted[x][y] = 1;
                        pq.push({x, y});
                        if (x == 1 && j == n - 1)
                            found = 1;
                    }
                }
            }
            if (found)
                break;
        }

        if (found)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}