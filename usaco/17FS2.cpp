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
    freopen("maxcross.in", "r", stdin); \
    freopen("maxcross.out", "w", stdout);
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
    file_read;
    ll n, k, b;
    cin >> n >> k >> b;
    vl a(n);
    fo(i, n)
        a[i] = 0;
    fo(i, b)
    {
        ll x;
        cin >> x;
        a[x - 1] = 1;
    }
    ll sp = 0;
    ll curr = 0;
    ll ans = LONG_LONG_MAX;
    fo(i, k)
    {
        if (a[i] == 1)
            curr++;
    }
    ans = min(ans, curr);
    Fo(i, k , n)
    {
        if (a[i] == 1)
            curr++;
        if (a[i - k] == 1)
            curr--;
        ans = min(ans, curr);
    }
    cout << ans;

    return 0;
}