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
    freopen("bcount.in", "r", stdin); \
    freopen("bcount.out", "w", stdout);
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
    ll n, m;
    cin >> n >> m;
    vl a(n + 1, 0), b(n + 1, 0), c(n + 1, 0);
    Fo(i, 1, n + 1)
    {
        ll x;
        cin >> x;
        if (x == 1)
            a[i] = a[i - 1] + 1;
        else
            a[i] = a[i - 1];
        if (x == 2)
            b[i] = b[i - 1] + 1;
        else
            b[i] = b[i - 1];
        if (x == 3)
            c[i] = c[i - 1] + 1;
        else
            c[i] = c[i - 1];
    }
    fo(i, m)
    {
        ll l, r;
        cin >> l >> r;
        cout << a[r] - a[l - 1] << " " << b[r] - b[l - 1] << " " << c[r] - c[l - 1] << endl;
    }
    return 0;
}