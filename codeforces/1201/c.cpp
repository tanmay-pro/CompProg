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
    vl a(n);
    fo(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    ll medianInd = n / 2;
    ll curr = medianInd;
    ll steps = 1;
    ll ans = a[medianInd];
    while (k > 0)
    {
        if (curr == n - 1)
            break;
        if (a[curr] == a[curr + 1])
        {
            curr++;
            steps++;
            continue;
        }
        ll diff = a[curr + 1] - a[curr];
        if (k >= steps)
        {
            // perform max steps less than diff
            ll maxSteps = min(k / steps, diff);
            ans += maxSteps;
            k -= maxSteps * steps;
            curr++;
            steps++;
        }
        else
        {
            break;
        }
    }
    if (k >= steps)
    {
        ans += k / steps;
    }
    cout << ans << endl;
    return 0;
}