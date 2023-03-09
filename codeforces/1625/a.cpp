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

string getBin(ll x, ll n)
{
    string str;
    Fo(i, n - 1, -1)
    {
        if (x & (1 << i))
            str += '1';
        else
            str += '0';
    }
    return str;
}

int main()
{
    amazing;
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, l;
        cin >> n >> l;
        vl a(n);
        fo(i, n)
        {
            cin >> a[i];
        }
        ll num = 0;
        vector<string> forms(n);
        fo(i, n)
        {
            forms[i] = getBin(a[i], l);
        }
        // fo(i, n)
        // {
        //     cout << forms[i];
        //     br;
        // }
        fo(i, l)
        {
            ll count = 0;
            ll c2 = 0;
            fo(j, n)
            {
                if (forms[j][i] == '1')
                    count++;
                else
                    c2++;
            }
            if (count > c2)
            {
                num += 1 * pow(2, l - i - 1);
            }
        }
        cout << num << endl;
    }
    return 0;
}