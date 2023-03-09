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

struct node
{
    ll x;
    ll y;
    ll minim;
    ll maxim;
};

int main()
{
    amazing;
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vvl a(n, vl(m));
        fo(i, n)
        {
            fo(j, m) cin >> a[i][j];
        }
        if ((m + n) % 2 == 0)
        {
            cout << "NO" << endl;
            continue;
        }
        vector<vector<node>> v(n, vector<node>(m));
        fo(i, n)
        {
            fo(j, m)
            {
                node temp;
                temp.x = i;
                temp.y = j;
                temp.minim = LONG_LONG_MAX;
                temp.maxim = LONG_LONG_MIN;
                if (i - 1 >= 0)
                {
                    temp.minim = min(temp.minim, v[i - 1][j].minim + a[i][j]);
                    temp.maxim = max(temp.maxim, v[i - 1][j].maxim + a[i][j]);
                }
                if (j - 1 >= 0)
                {
                    temp.minim = min(temp.minim, v[i][j - 1].minim + a[i][j]);
                    temp.maxim = max(temp.maxim, v[i][j - 1].maxim + a[i][j]);
                }
                if (temp.minim == LONG_LONG_MAX)
                {
                    temp.minim = a[i][j];
                    temp.maxim = a[i][j];
                }
                v[i][j] = temp;
            }
        }
        if (0 >= v[n - 1][m - 1].minim && 0 <= v[n - 1][m - 1].maxim)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}