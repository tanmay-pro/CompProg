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

ll query(ll a, ll b)
{
    cout << "? " << a + 1 << " " << b + 1 << endl;
    ll ans;
    cin >> ans;
    return ans;
}

int main()
{
    amazing;
    ll n;
    cin >> n;
    ll x = query(1, 2);
    ll y = query(0, 1);
    ll z = query(0, 2);
    vl a(n, -1);
    a[1] = (x + y - z) / 2;
    a[2] = x - a[1];
    a[0] = y - a[1];
    Fo(i, 3, n)
    {
        ll x = query(0, i);
        a[i] = x - a[0];
    }
    cout << "! ";
    fo(i, n)
    {
        cout << a[i] << " ";
    }
    br;
    return 0;
}