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
        ll n;
        cin >> n;
        vpl a(n);
        fo(i, n)
        {
            pll temp;
            cin >> temp.ff >> temp.ss;
            a[i] = temp;
        }
        ll xMax = 0, xMin = 0, yMax = 0, yMin = 0;
        fo(i, n)
        {
            if (a[i].ff > xMax)
                xMax = a[i].ff;
            if (a[i].ff < xMin)
                xMin = a[i].ff;
            if (a[i].ss > yMax)
                yMax = a[i].ss;
            if (a[i].ss < yMin)
                yMin = a[i].ss;
        }
        cout << 2 * (xMax - xMin) + 2 * (yMax - yMin) << endl;
    }
    return 0;
}