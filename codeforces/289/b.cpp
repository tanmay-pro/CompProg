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
    ll n, m, d;
    cin >> n >> m >> d;
    vvl a(n, vl(m, 0));
    fo(i, n) fo(j, m) cin >> a[i][j];
    ll ans = 0;
    vl arr;
    fo(i, n)
    {
        fo(j, m)
        {
            arr.push_back(a[i][j]);
        }
    }
    sort(arr.begin(), arr.end());
    bool ch = 1;
    Fo(i, 1, arr.size())
    {
        if ((arr[i] - arr[i - 1]) % d != 0)
        {
            ch = 0;
            break;
        }
    }
    if (ch)
    {
        ll elem = arr[arr.size() / 2];
        fo(i, arr.size())
        {
            ans += abs((arr[i] - elem)) / d;
        }
        cout << ans;
        br;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}