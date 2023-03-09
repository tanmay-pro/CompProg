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
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vl a(n);
        fo(i, n)
        {
            cin >> a[i];
        }
        ll ans = 0;
        if (k >= n)
        {
            ll add = 0;
            fo(i, n)
            {
                ans += a[i];
                ans += add;
                add++;
            }
            if (k > n)
            {
                k -= n;
                ans += k * n;
            }
            cout << ans;
            br;
        }
        else
        {
            ll overall = 0;
            ll sum1 = 0, add = 0;
            fo(i, k)
            {
                sum1 += a[i];
                sum1 += add;
                add++;
            }
            overall += sum1;
            Fo(i, k, n)
            {
                sum1 -= a[i - k];
                sum1 += a[i];
                overall = max(overall, sum1);
            }
            cout << overall;
            br;
        }
    }
    return 0;
}