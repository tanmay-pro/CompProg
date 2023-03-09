#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265
#define br cout << endl
#define fo(i, n) for (int i = 0; i < n; i++)
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
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vl a(n);
        ll ans = 0;
        fo(i, n)
        {
            cin >> a[i];
            ans += a[i] / k;
            a[i] %= k;
        }

        sort(a.begin(), a.end());
        while (!a.empty())
        {
            ll currElem = a[0];
            a.erase(a.begin());
            if(currElem == 0)
            {
                continue;
            }
            if (a.empty())
            {
                break;
            }
            auto it = lower_bound(a.begin(), a.end(), k - currElem);
            if (it != a.end())
            {
                ans++;
                a.erase(it);
            }
        }
        cout << ans << endl;
    }
    return 0;
}