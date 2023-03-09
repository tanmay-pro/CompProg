#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265
#define br cout << endl
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define amazing ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define ff first
#define ss second
#define pb push_back
#define file_read                     \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef map<int, int> mii;
typedef map<ll, ll> mll;

int MOD = 1e9 + 7;

int main()
{
    amazing;
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vl b;
        fo(i, n)
        {
            ll a;
            cin >> a;
            b.pb(a);
        }
        bool pos = true;
        ll maxSofar = b[0];
        ll minSofar = b[0];
        if (n > 1)
        {
            maxSofar = max(maxSofar, b[1]);
            minSofar = min(minSofar, b[1]);
            if (n > 2)
            {
                Fo(i, 2, n)
                {
                    if (b[i] < maxSofar && b[i] > minSofar)
                    {
                        pos = false;
                        break;
                    }
                    else
                    {
                        maxSofar = max(maxSofar, b[i]);
                        minSofar = min(minSofar, b[i]);
                    }
                }
            }
        }
        if (pos)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
        br;
    }
    return 0;
}