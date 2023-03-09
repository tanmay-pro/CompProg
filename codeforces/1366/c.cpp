#include <bits/stdc++.h>
using namespace std;
// code for implementing binary search
/*lli l = -1, r = size;while (r > l + 1){ lli mid = l + (r - l) / 2; if (array[mid] <= val)l = mid;elser = mid;}*/
#define ll long long
#define PI 3.14159265
#define br cout << endl
#define fo(i, n) for (int i = 0; i < n; i++)
#define tr(container, it) \
    for (auto it = container.begin(); it != container.end(); it++)
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
        ll n, m;
        cin >> n >> m;
        vvl a(n, vl(m, 0));
        fo(i, n)
        {
            fo(j, m)
            {
                cin >> a[i][j];
            }
        }
        map<ll, vl> ds;
        fo(i, n)
        {
            fo(j, m)
            {
                ll dis = i + j;
                ds[dis].pb(a[i][j]);
            }
        }
        ll ans = 0;
        fo(i, m + n)
        {
            ll dis1 = i;
            ll dis2 = m + n - i - 2;
            vl vc1 = ds[dis1];
            vl vc2 = ds[dis2];
            ll totLen = vc1.size() + vc2.size();
            ll ones = 0, zeroes = 0;
            fo(i, vc1.size())
            {
                if (vc1[i] == 1)
                    ones++;
                else
                    zeroes++;
            }
            fo(i, vc2.size())
            {
                if (vc2[i] == 1)
                    ones++;
                else
                    zeroes++;
            }
            if (ones > zeroes)
            {
                ds[dis1] = vector<ll>(vc1.size(), 1);
                ds[dis2] = vector<ll>(vc2.size(), 1);
                ans += zeroes;
            }
            else
            {
                ds[dis1] = vector<ll>(vc1.size(), 0);
                ds[dis2] = vector<ll>(vc2.size(), 0);
                ans += ones;
            }
        }
        cout << ans << endl;
    }
    return 0;
}