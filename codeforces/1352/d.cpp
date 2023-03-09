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
        ll n;
        cin >> n;
        vl a(n);
        fo(i, n) cin >> a[i];
        ll moves = 1;
        ll p1 = a[0], prevp1 = a[0];
        ll p2 = 0, prevp2 = 0;
        auto sp = a.begin();
        auto ep = a.end();
        while (sp < ep)
        {
            ll so = 0;
            bool ch = 0;
            while (so <= prevp1)
            {
                ep--;
                if (sp == ep)
                    break;
                so += *ep;
                ch = 1;
            }
            if (ch == 1)
            {
                prevp2 = so;
                moves++;
                p2 += prevp2;
            }
            if (sp >= ep)
                break;
            so = 0;
            ch = 0;
            while (so <= prevp2)
            {
                sp++;
                if (sp == ep)
                    break;
                so += *sp;
                ch = 1;
            }
            if (ch == 1)
            {
                prevp1 = so;
                p1 += prevp1;
                moves++;
            }
        }
        cout << moves << " " << p1 << " " << p2 << endl;
    }
    return 0;
}