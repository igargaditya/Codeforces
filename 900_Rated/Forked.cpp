#include <iostream>
#define ll long long
using namespace std;
void fnot(ll x, ll y, ll x1, ll y1, ll x2, ll y2)
{
    ll delrow[] = {-x, -y, -y, -x, x, y, y, x};
    ll delcol[] = {-y, -x, x, y, y, x, -x, -y};

    ll ans = 0;
    for (int i = 0; i < 8; i++)
    {
        ll kingx = x1 + delrow[i];
        ll kingy = y1 + delcol[i];
        for (int j = 0; j < 8; j++)
        {
            ll queenx = x2 + delrow[j];
            ll queeny = y2 + delcol[j];
            if (queenx == kingx && queeny == kingy)
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
}
void fequal(ll x, ll y, ll x1, ll y1, ll x2, ll y2)
{

    ll delrow[] = {-x, -x, x, x};
    ll delcol[] = {-x, x, x, -x};

    ll ans = 0;
    for (int i = 0; i < 4; i++)
    {
        ll kingx = x1 + delrow[i];
        ll kingy = y1 + delcol[i];
        for (int j = 0; j < 4; j++)
        {
            ll queenx = x2 + delrow[j];
            ll queeny = y2 + delcol[j];
            if (queenx == kingx && queeny == kingy)
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    ll x, y, x1, y1, x2, y2;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;

    if (x != y)

        fnot(x, y, x1, y1, x2, y2);

    else
        fequal(x, y, x1, y1, x2, y2);
}