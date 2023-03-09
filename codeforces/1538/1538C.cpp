#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265
#define br cout << endl
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define tr(container, it) \
    for (auto it = container.begin(); it != container.end(); it++)
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
ll MOD = 1e9 + 7;
int p = 31;

ll maxim(ll a, ll b, ll c)
{
    ll max_val = max(a, b);
    return max(max_val, c);
}

ll minim(ll a, ll b, ll c)
{
    ll min_val = min(a, b);
    return min(min_val, c);
}

int main()
{
    amazing;
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n, l, r;
        cin >> n >> l >> r;
        vl a(n);
        fo(i, n)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        ll answer = 0;
        tr(a, it)
        {
            ll elem = *it;
            ll upper1 = upper_bound(it + 1, a.end(), r - elem) - it - 2;
            ll lower1 = lower_bound(it + 1, a.end(), l - elem) - it - 1;
            answer += upper1 - lower1 + 1;
        }
        cout << answer;
        br;
    }
    return 0;
}