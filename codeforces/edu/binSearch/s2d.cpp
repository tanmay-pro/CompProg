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

ll m, n;
vl t, z, y;

pair<bool, vl> good(ll mid)
{
    vl assi;
    ll sum = 0;
    fo(i, n)
    {
        ll bal = 0;
        ll temp = mid;
        if (temp / t[i] > z[i])
        {
            while (temp > 0)
            {
                if (temp / t[i] > z[i])
                {
                    bal += z[i];
                    temp -= z[i] * t[i];
                    temp -= y[i];
                }
                else
                {
                    bal += temp / t[i];
                    break;
                }
            }
        }
        else
        {
            bal = temp / t[i];
        }

        if (sum + bal <= m)
        {
            assi.push_back(bal);
        }
        else
        {
            if (m >= sum)
                assi.push_back(m - sum);
            else
                assi.push_back(0);
        }
        sum += bal;
    }
    if (sum >= m)
        return {true, assi};
    return {false, assi};
}

int main()
{
    amazing;
    cin >> m >> n;
    t.resize(n);
    z.resize(n);
    y.resize(n);
    fo(i, n)
    {
        cin >> t[i] >> z[i] >> y[i];
    }
    ll l = 0;
    ll r = 5e6;
    vl ans;
    while (l + 1 < r)
    {
        ll mid = l + (r - l) / 2;

        pair<bool, vl> temp = good(mid);
        if (!temp.ff)
        {
            l = mid;
        }
        else
        {
            r = mid;
            ans.clear();
            ans = temp.ss;
        }
    }
    cout << r;
    br;
    fo(i, ans.size())
    {
        cout << ans[i] << " ";
    }
    br;
    return 0;
}