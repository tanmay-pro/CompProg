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
        string str;
        cin >> str;
        ll n = str.length();
        ll zeroes = 0, ones = 0;
        fo(i, n)
        {
            if (str[i] == '0')
                zeroes++;
            else
                ones++;
        }
        ll ans = min(zeroes, ones);
        ll temp = 0;
        vl onesSoFar, zeroesSoFar;
        if (str[0] == '0')
        {
            zeroesSoFar.pb(1);
            onesSoFar.pb(0);
        }
        else
        {
            zeroesSoFar.pb(0);
            onesSoFar.pb(1);
        }
        Fo(i, 1, n)
        {
            if (str[i] == '0')
            {
                zeroesSoFar.pb(zeroesSoFar[i - 1] + 1);
                onesSoFar.pb(onesSoFar[i - 1]);
            }
            else
            {
                zeroesSoFar.pb(zeroesSoFar[i - 1]);
                onesSoFar.pb(onesSoFar[i - 1] + 1);
            }
        }
        fo(i, n)
        {
            ll val = onesSoFar[i] + zeroes - zeroesSoFar[i];
            ll val2 = zeroesSoFar[i] + ones - onesSoFar[i];
            ans = min(ans, min(val, val2));
        }
        cout << ans << endl;
    }
    return 0;
}