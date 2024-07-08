// https://codeforces.com/problemset/problem/1909/A
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> vec(n);

    for (int i = 0; i < n; i++)
    {
        cin >> vec[i].first >> vec[i].second;
    }

    bool possibleD = 1;
    bool possibleU = 1;
    bool possibleR = 1;
    bool possibleL = 1;
    // L R U
    for (int i = 0; i < n; i++)
    {
        if (vec[i].second < 0)
            possibleD = 0;
        if (vec[i].second > 0)
            possibleU = 0;
        if (vec[i].first < 0)
            possibleL = 0;
        if (vec[i].first > 0)
            possibleR = 0;
    }
    // L R D
    bool final = possibleD || possibleL || possibleR || possibleU;
    if (final)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}