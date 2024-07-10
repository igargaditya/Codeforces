#include <iostream>
#include <set>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int i = 0;
        int j = n - 1;
        int deleted = 0;
        while (i < j)
        {
            if ((s[i] == '0' && s[j] == '1') || (s[i] == '1' && s[j] == '0'))
            {
                i++;
                j--;
                deleted += 2;
            }
            else
                break;
        }
        cout << n - deleted << endl;
    }
}