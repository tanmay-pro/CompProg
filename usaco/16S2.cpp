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
#define file_read                   \
    freopen("div7.in", "r", stdin); \
    freopen("div7.out", "w", stdout);
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
    ll n;
    cin >> n;
    vl a(n);
    fo(i, n)
    {
        cin >> a[i];
    }
    vl prefixSums(n, 0);
    prefixSums[0] = a[0];
    Fo(i, 1, n)
    {
        prefixSums[i] = (prefixSums[i - 1] + a[i] % 7) % 7;
    }
    ll ans = LONG_LONG_MIN;
    map<ll, ll> mp;
    fo(i, n)
    {
        if (mp[prefixSums[i]] == 0)
        {
            mp[prefixSums[i]] = i + 1;
        }
    }
    map<ll, ll> mp2;
    fo(i, n)
    {
        mp2[prefixSums[i]] = i + 1;
    }
    tr(mp2, it)
    {
        if (it->second - mp[it->first] > ans)
        {
            ans = it->second - mp[it->first];
        }
    }
    cout << ans;
    return 0;
}