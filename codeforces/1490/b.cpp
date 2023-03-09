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
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vl a;
        fo(i, n)
        {
            ll x;
            cin >> x;
            a.push_back(x);
        }
        ll c0 = 0, c1 = 0, c2 = 0;
        fo(i, n)
        {
            if (a[i] % 3 == 0)
                c0++;
            else if (a[i] % 3 == 1)
                c1++;
            else
                c2++;
        }
        ll ans = 0;
        while (c0 != n / 3 || c1 != n / 3 || c2 != n / 3)
        {
            while (c0 > n / 3)
            {
                c0--;
                c1++;
                ans++;
            }
            while (c1 > n / 3)
            {
                c1--;
                c2++;
                ans++;
            }
            while (c2 > n / 3)
            {
                c2--;
                c0++;
                ans++;
            }
        }
        cout << ans;
        br;
    }
    return 0;
}