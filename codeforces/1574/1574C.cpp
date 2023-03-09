#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265
#define endl "\n"
#define br cout << endl
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define tr(container, it) \
    for (auto it = container.begin(); it != container.end(); it++)
#define amazing ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
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
ll MOD = 1e9 + 7;
int p = 31;

int main()
{
    amazing;
    ll n;
    cin >> n;
    vl a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    ll m;
    cin >> m;
    vl def(m), attac(m);
    for (int i = 0; i < m; i++)
    {
        cin >> def[i] >> attac[i];
    }
    ll ans = 0;
    sort(a.begin(), a.end());
    for (int i = 0; i < m; i++)
    {
        ll ival = upper_bound(a.begin(), a.end(), def[i]) - a.begin();
        ll i2val = lower_bound(a.begin(), a.end(), def[i]) - a.begin();
        if (ival != 0)
        {
            ival -= 1;
        }
        //  cout << ival << " " << i2val << endl;
        ll a1 = 0, a2 = 0;
        if (def[i] > a[ival])
        {
            a1 += def[i] - a[ival];
        }
        if (def[i] > a[i2val])
        {
            a2 += def[i] - a[i2val];
        }
        if (attac[i] > (sum - a[ival]))
        {
            a1 += attac[i] - (sum - a[ival]);
        }
        if (attac[i] > (sum - a[i2val]))
        {
            a2 += attac[i] - (sum - a[i2val]);
        }
        cout << min(a1, a2);
        br;
    }

    return 0;
}