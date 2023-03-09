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

vl compute(ll S, ll X)
{
    ll A = (S - X) / 2;

    ll a = 0, b = 0;

    // Traverse through all bits
    fo(i, 8 * sizeof(S))
    {
        ll temp = (X & (1 << i));
        ll val = (A & (1 << i));
        if (temp == 0 && val == 0)
        {
            continue;
        }
        else if (temp == 0 && val > 0)
        {
            a = ((1 << i) | a);
            b = ((1 << i) | b);
        }
        else if (temp > 0 && val == 0)
        {
            a = ((1 << i) | a);
        }
        else
        {
            return {-1, -1};
        }
    }
    return {a, b};
}

int main()
{
    amazing;
    ll t;
    cin >> t;
    while (t--)
    {
        ll x;
        cin >> x;
        ll s = 2 * x;
        vl temp = compute(s, x);
        if (temp[0] == -1)
        {
            cout << -1;
            br;
            continue;
        }
        else
        {
            if ((temp[0] + temp[1]) % 2 == 1)
            {
                cout << -1;
                br;
                continue;
            }
            else
            {
                cout << temp[0] << " " << temp[1];
                br;
            }
        }
    }
    return 0;
}
