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
    ll n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> movies;
    fo(i, n)
    {
        ll x, y;
        cin >> x >> y;
        movies.push_back({y, x});
    }
    sort(movies.begin(), movies.end());

    ll ans = 0;
    multiset<ll> m;
    fo(i, k)
        m.insert(0);

    fo(i, n)
    {
        auto elem = upper_bound(m.begin(), m.end(), movies[i].ss);
        if(elem == begin(m))
            continue;
        m.erase(--elem);
        m.insert(movies[i].ff);
        ans++;
    }
    cout << ans;
    br;

    return 0;
}