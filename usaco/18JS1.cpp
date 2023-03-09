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
    freopen("lifeguards.in", "r", stdin); \
    freopen("lifeguards.out", "w", stdout);
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
    vpl a(n);
    fo(i, n) cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end());
    ll ans = 0;
    vl unique;
    ll tempval = min(a[1].first, a[0].second) - a[0].first;
    if(tempval < 0) tempval = 0;
    unique.pb(tempval);
    Fo(i, 1, n - 1)
    {
        ll tempval = min(a[i + 1].first, a[i].second) - max(a[i].first, a[i - 1].second);
        if(tempval < 0) tempval = 0;
        unique.pb(tempval);
    }
    tempval = a[n - 1].second - max(a[n - 1].first, a[n - 2].second);
    if(tempval < 0) tempval = 0;
    unique.pb(tempval);
    ll totalTime = 0;
    ll start = a[0].first, end = a[0].second;
    Fo(i, 1, n)
    {
        if(a[i].first <= end)
        {
            end = max(end, a[i].second);
        }
        else
        {
            totalTime += end - start;
            start = a[i].first;
            end = a[i].second;
        }
    }
    totalTime += end - start;
    // cout << totalTime << endl;
    cout << totalTime - *min_element(unique.begin(), unique.end());
    return 0;
}