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
    ll n, d;
    cin >> n >> d;
    vpl friends(n);
    fo(i, n)
    {
        cin >> friends[i].ff >> friends[i].ss;
    }
    sort(friends.begin(), friends.end());
    ll ans = -1;
    ll ep = 0, sp = 0;
    vl prefSum(n);
    prefSum[0] = friends[0].ss;
    Fo(i, 1, n)
    {
        prefSum[i] = prefSum[i - 1] + friends[i].ss;
    }
    // fo(i, n)
    // {
    //     cout << prefSum[i] << " ";
    // }
    // br;
    while (sp < n)
    {

        while (ep < n)
        {
            if (friends[ep].ff >= friends[sp].ff + d)
                break;
            ans = max(ans, prefSum[ep] - prefSum[sp] + friends[sp].ss);
            ep++;
            if (ep == n || friends[ep].ff >= friends[sp].ff + d)
                break;
        }
        sp++;
    }
    cout << ans << endl;
    return 0;
}