#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long
typedef pair<ll, ll> ii;
#define br cout << endl
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
#define amazing ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define ff first
#define ss second
#define pb push_back
#define tc    \
    int t;    \
    cin >> t; \
    while (t--)
#define file_read(x, y)     \
    freopen(x, "r", stdin); \
    freopen(y, "w", stdout);
int main()
{
    amazing;
    tc
    {
        ll a, b, n;
        cin >> a >> b >> n;
        vii monster(n);
        fo(i, n)
        {
            ll x;
            cin >> x;
            monster[i] = {x, 0};
        }
        fo(i, n)
        {
            ll x;
            cin >> x;
            monster[i] = {monster[i].ff, x};
        }
        sort(monster.begin(), monster.end());
        for (int i = 0; i < n - 1; i++)
        {
            ll x = (monster[i].ss + a - 1) / a;
            b -= x * monster[i].ff;
        }
        if (b <= 0)
        {
            cout << "NO\n";
        }
        else
        {
            ll x = (monster[n - 1].ss + a - 1) / a;
            x--;
            b -= x * monster[n - 1].ff;
            if (b <= 0)
                cout << "NO\n";
            else
                cout << "YES\n";
        }
    }
}