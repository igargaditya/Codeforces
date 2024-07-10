#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        char ch;
        cin >> ch;
        set<char> st;
        string s = "codeforces";
        for (int i = 0; i < s.size(); i++)
        {
            st.insert(s[i]);
        }
        if (st.find(ch) != st.end())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}