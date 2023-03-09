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
        ll n, m;
        cin >> n >> m;
        vl a(n);
        fo(i, n) cin >> a[i];
        vvl adj(n + 1);
        vpl pairs;
        fo(i, m)
        {
            ll x, y;
            cin >> x >> y;
            pairs.pb({x, y});
            adj[x].pb(y);
            adj[y].pb(x);
        }
        if (m % 2 == 0 || m == 0)
        {
            cout << 0;
            br;
            continue;
        }
        vpl weightage;
        ll sum = 0;
        fo(i, n)
        {
            weightage.push_back({a[i], i + 1});
            sum += a[i];
        }
        sort(weightage.begin(), weightage.end(), greater<pll>());
        ll ans = sum;

        map<ll, ll> present;
        fo(i, weightage.size())
        {
            ll eat = 0;
            ll elem = weightage[i].ss;
            sum -= weightage[i].ff;
            present[elem] = 1;
            fo(j, adj[elem].size())
            {
                if (present[adj[elem][j]] == 1)
                {
                    eat++;
                }
            }
            if (eat % 2 == 0)
            {
                ans = min(ans, sum);
                // cout << "Included " << elem << endl;
            }
            else
            {
                present[elem] = 0;
                sum += weightage[i].ff;
                // cout << "Excluded " << elem << " for eat = " << eat << endl;
            }
            // cout << weightage[i].ff << " " << weightage[i].ss << endl;
            // br;
        }
        cout << ans;
        br;
    }
    return 0;
}