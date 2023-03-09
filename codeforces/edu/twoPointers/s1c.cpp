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
    ll n, m;
    cin >> n >> m;
    vl a(n), b(m);
    fo(i, n) cin >> a[i];
    fo(i, m) cin >> b[i];
    ll ans = 0;
    map<ll, ll> freqa;
    map<ll, ll> freqb;
    fo(i, n) freqa[a[i]]++;
    fo(i, m) freqb[b[i]]++;
    set<ll> sa, sb;
    fo(i, n) sa.insert(a[i]);
    fo(i, m) sb.insert(b[i]);
    auto it1 = sa.begin();
    auto it2 = sb.begin();
    while (it1 != sa.end() && it2 != sb.end())
    {
        if (*it1 == *it2)
        {
            ans += freqa[*it1] * freqb[*it2];
            it1++;
            it2++;
        }
        else if (*it1 < *it2)
        {
            it1++;
        }
        else
        {
            it2++;
        }
    }
    cout << ans;
    br;
    return 0;
}