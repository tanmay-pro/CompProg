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
    ll n;
    cin >> n;
    vl a(n);
    fo(i, n) cin >> a[i];
    vl b(n);
    fo(i, n) cin >> b[i];
    vl diff;
    fo(i, n) diff.pb(a[i] - b[i]);
    vl pos;
    vl neg;
    ll zero = 0;
    fo(i, n)
    {
        if (diff[i] > 0)
            pos.pb(diff[i]);
        else if (diff[i] < 0)
            neg.pb(abs(diff[i]));
        else
            zero++;
    }
    sort(neg.begin(), neg.end());
    ll ans = 0;
    ll val = pos.size();
    ans += val*(val - 1) / 2;
    ans += pos.size() * zero;
    if (neg.size() == 0)
    {
        cout << ans;
        return 0;
    }
    fo(i, pos.size())
    {
        auto it = lower_bound(neg.begin(), neg.end(), pos[i]);
        if (it == neg.end())
        {
            ans += neg.size();
        }
        else
        {
            ll ind = it - neg.begin();
            ind--;
            if (ind >= 0)
                ans += ind + 1;
        }
    }
    cout << ans;

    return 0;
}