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

ll query(ll c)
{
    cout << "? " << c << endl;
    ll ans;
    cin >> ans;
    return ans;
}

int main()
{
    amazing;
    ll n;
    cin >> n;
    vl a(n + 2);
    a[0] = n + 2;
    a[n + 1] = n + 2;
    ll l = 1, r = n;
    while (l < r)
    {
        ll mid = l + (r - l) / 2;
        ll x = query(mid);
        ll y = query(mid + 1);
        if (x < y)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << "! " << l << endl;

    return 0;
}