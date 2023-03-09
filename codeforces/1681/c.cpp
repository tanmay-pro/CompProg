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
        vl a(n);
        vl b(n);
        fo(i, n)
        {
            cin >> a[i];
        }
        fo(i, n)
        {
            cin >> b[i];
        }
        vpl ops;
        ll ans = 0;
        fo(i, n - 1)
        {
            fo(j, n - i - 1)
            {
                if (a[j] > a[j + 1])
                {
                    ans++;
                    swap(a[j], a[j + 1]);
                    swap(b[j], b[j + 1]);
                    ops.push_back(make_pair(j+ 2, j + 1));
                }
            }
        }
        if (is_sorted(b.begin(), b.end()))
        {
            cout << ans;
            br;
            fo(i, ops.size())
            {
                cout << ops[i].ff << " " << ops[i].ss << endl;
            }
            continue;
        }
        fo(i, n - 1)
        {
            fo(j, n - i - 1)
            {
                if (b[j] > b[j + 1])
                {
                    ans++;
                    swap(b[j], b[j + 1]);
                    swap(a[j], a[j + 1]);
                    ops.push_back(make_pair(j + 2, j + 1));
                }
            }
        }
        if (is_sorted(a.begin(), a.end()))
        {
            cout << ans << endl;
            fo(i, ops.size())
            {
                cout << ops[i].ff << " " << ops[i].ss << endl;
            }
            continue;
        }
        cout << -1 << endl;
    }
    return 0;
}