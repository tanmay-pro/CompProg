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

pair<long, long> sum2(ll index, ll reqSum, vpl a, ll n)
{
    ll sp = 0, ep = n - 1;
    if (sp == index)
        sp++;
    if (ep == index)
        ep--;
    while (sp < ep)
    {
        ll sum = a[sp].first + a[ep].first;
        if (sum > reqSum)
        {
            ep--;
            if (ep == index)
                ep--;
        }
        else if (sum < reqSum)
        {
            sp++;
            if (sp == index)
                sp++;
        }
        else
        {
            // cout << index << " " << reqSum;
            // br;
            return {a[sp].second, a[ep].second};
        }
    }
    // cout << "-1 output for " << index << " " << reqSum;
    // br;
    return {-1, -1};
}

int main()
{
    amazing;
    ll n, x;
    cin >> n >> x;
    vpl a(n);
    fo(i, n)
    {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    if(n <= 2)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    sort(a.begin(), a.end());
    bool ch = false;
    fo(i, n)
    {
        pll selElem = a[i];
        pll output = sum2(i, x - a[i].first, a, n);
        if (output.second != -1)
        {
            cout << output.first << " " << output.second << " " << selElem.second;
            br;
            ch = true;
            break;
        }
    }
    if (!ch)
        cout << "IMPOSSIBLE" << endl;
    return 0;
}