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
    vpl trees;
    cin >> n;
    fo(i, n)
    {
        ll x, y;
        cin >> x >> y;
        trees.pb({x, y});
    }
    ll ans = 0;
    ans += 2;
    ll prevFallen = 0;
    if (n == 1)
    {
        cout << 1;
        br;
        return 0;
    }
    if (n == 2)
    {
        cout << 2;
        br;
        return 0;
    }
    Fo(i, 1, trees.size() - 1)
    {
        ll leftSpace, rightSpace;
        if (!prevFallen)
        {
            leftSpace = trees[i].ff - trees[i - 1].ff;
            rightSpace = trees[i + 1].ff - trees[i].ff;
        }
        else
        {
            leftSpace = trees[i].ff - trees[i - 1].ff - trees[i - 1].ss;
            rightSpace = trees[i + 1].ff - trees[i].ff;
        }
        if (leftSpace > trees[i].ss)
        {
            ans++;
            prevFallen = 0;
        }
        else if (rightSpace > trees[i].ss)
        {
            ans++;
            prevFallen = 1;
        }
        else
        {
            prevFallen = 0;
        }
    }
    cout << ans;
    br;
    return 0;
}
