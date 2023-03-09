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

ll n, m;
vl a;

bool good(ll mid)
{
    vl freq(n + 1, 0);
    fo(i, m)
    {
        freq[a[i]]++;
    }
    ll tasks = 0;
    Fo(i, 1, n + 1)
    {
        if (freq[i] <= mid)
        {
            tasks += freq[i];
            tasks += (mid - freq[i]) / 2;
        }
        else
        {
            tasks += mid;
        }
    }
    if (tasks >= m)
        return true;
    return false;
}

int main()
{
    amazing;
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        a.resize(m);
        fo(i, m) cin >> a[i];
        ll l = 0, r = 1e6;
        while (r > l + 1)
        {
            ll mid = l + (r - l) / 2;
            if (!good(mid))
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }
        cout << r;
        br;
    }
    return 0;
}