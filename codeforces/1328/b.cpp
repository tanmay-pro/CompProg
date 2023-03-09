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

ll getComb(ll n)
{
    return (n * (n - 1)) / 2;
}

ll getComb2(ll n)
{
    return n;
}

int main()
{
    amazing;
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll currB = 0;
        ll firstBpos = -1, lastBpos = -1;
        Fo(i, n - 1, -1)
        {
            if (currB == 0)
            {
                ll combVal = getComb(i);
                if (k > combVal)
                {
                    currB = 1;
                    firstBpos = n - i - 1;
                    k -= combVal;
                }
            }
            else if (currB == 1)
            {
                ll combVal = getComb2(i);
                if (k > combVal)
                {
                    currB = 2;
                    lastBpos = n - i - 1;
                    k -= combVal;
                }
            }
        }
        string ans = "";
        Fo(i, 0, n)
        {
            if (i == firstBpos)
            {
                ans += 'b';
            }
            else if (i == lastBpos)
            {
                ans += 'b';
            }
            else
            {
                ans += 'a';
            }
        }
        cout << ans << endl;
    }
    return 0;
}