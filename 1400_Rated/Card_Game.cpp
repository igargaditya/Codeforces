#include <iostream>
#include <queue>
#include <set>
using namespace std;
bool cmp(string a, string b)
{
    if (a[1] == b[1])
        return a[0] < b[0];
    return a[1] < b[1];
}
int main()
{
    int n;
    cin >> n;
    char trumph;
    cin >> trumph;
    vector<string> arr(2 * n);
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> arr[i];
    }

    vector<string> no;
    vector<string> t;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i][1] == trumph)
            t.push_back(arr[i]);
        else
            no.push_back(arr[i]);
    }

    sort(no.begin(), no.end(), cmp);
    sort(t.begin(), t.end(), cmp);

    cout << " NO TRUMP " << endl;
    for (int i = 0; i < no.size(); i++)
    {
        cout << no[i] << " ";
    }
    cout << endl;
    cout << "trump" << endl;
    for (int i = 0; i < t.size(); i++)
    {
        cout << t[i] << " ";
    }
    cout << endl;

    vector<string> ans;
    bool what = 1;
    int j = 0;
    for (int i = 0; i < no.size();)
    {
        if (i + 1 == no.size() && j < t.size())
        {
            ans.push_back(no[i]);
            ans.push_back(t[j]);
            j++;
            break;
        }

        if (no[i][1] == no[i + 1][1])
        {

            ans.push_back(no[i]);
            ans.push_back(no[i + 1]);
            i += 2;
        }
        else if (no[i][1] != no[i + 1][1])
        {
            ans.push_back(no[i]);
            if (j == t.size())
            {
                what = 0;
                break;
            }
            ans.push_back(t[j]);
            j++;
            i++;
        }
    }
    if (what == 0)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        while (j < t.size())
        {
            ans.push_back(t[j]);
            ans.push_back(t[j + 1]);
            j += 2;
        }

        for (int i = 0; i < ans.size(); i += 2)
        {
            cout << ans[i] << " " << ans[i + 1] << endl;
        }
    }
}
