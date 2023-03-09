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
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        ll n, a, b, k;
        cin >> n >> a >> b >> k;
        vl monster;
        fo(i, n)
        {
            ll x;
            cin >> x;
            monster.pb(x);
        }
        ll ans = 0;
        vl arr;
        fo(i, monster.size())
        {
            ll curr = monster[i];
            ll div = curr / (a + b);
            ll rem = curr % (a + b);
            ll remHealth = curr - (div * (a + b));
            if (rem == 0)
            {
                remHealth = a + b;
                div = remHealth / (a);
                rem = remHealth % (a);
                if (rem == 0)
                {
                    arr.push_back(div - 1);
                }
                else
                {
                    arr.push_back(div);
                }
            }
            else if (rem <= a)
            {
                arr.push_back(0);
            }
            else
            {
                div = remHealth / (a);
                rem = remHealth % (a);
                if (rem == 0)
                {
                    arr.push_back(div - 1);
                }
                else
                {
                    arr.push_back(div);
                }
            }
        }
        sort(arr.begin(), arr.end());
        fo(i, arr.size())
        {
            if (arr[i] <= k)
            {
                ans++;
                k -= arr[i];
            }
            else
                break;
        }
        cout << ans << endl;
    }
    return 0;
}