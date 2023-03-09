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

string getBin(ll n, ll num)
{
    string out = "";
    for (int i = num - 1; i >= 0; i--)
    {
        if (n & (1 << i))
            out += '1';
        else
            out += '0';
    }
    return out;
}

int main()
{
    amazing;
    ll n;
    cin >> n;
    vl a(n);
    fo(i, n)
    {
        cin >> a[i];
    }
    fo(i, (1 << n))
    {
        ll val = i;
        string bin = getBin(val, n);
        ll ans = 0;
        fo(j, n)
        {
            if (bin[j] == '1')
            {
                ans += a[j];
            }
            else
            {
                ans -= a[j];
            }
        }
        if (ans == 0 || ans % 360 == 0)
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}