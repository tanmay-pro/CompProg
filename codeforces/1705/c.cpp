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
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, c, q;
        cin >> n >> c >> q;
        string str;
        cin >> str;
        vpl v;
        vpl v2;
        v.push_back({1, n});
        v2.push_back({1, n});
        ll start = n + 1;
        fo(i, c)
        {
            ll l, r;
            cin >> l >> r;
            v.push_back({l, r});
            v2.push_back({start, start + r - l});
            start = start + r - l + 1;
        }
        // fo(i, v.size())
        // {
        //     cout << v[i].ff << " " << v[i].ss << endl;
        // }
        // br;
        // fo(i, v2.size())
        // {
        //     cout << v2[i].ff << " " << v2[i].ss << endl;
        // }
        while (q--)
        {
            ll x;
            cin >> x;
            if (x <= n)
            {
                cout << str[x - 1];
                br;
            }
            else
            {
                while (x > n)
                {
                    ll i = 0;
                    for (; i < v2.size(); i++)
                    {
                        if (x <= v2[i].ss && x >= v2[i].ff)
                        {
                            break;
                        }
                    }
                    ll start = v[i].ff;
                    ll end = v[i].ss;
                    ll dist = x - v2[i].ff;
                    x = start + dist;
                }
                cout << str[x - 1];
                br;
            }
        }
    }
    return 0;
}