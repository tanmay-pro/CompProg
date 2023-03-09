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
int m = 1e9 + 7;
int p = 31;

ll minim(ll a, ll b)
{
    if (a < b)
        return a;
    else
        return b;
}

int main()
{
    amazing;
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll k;
        cin >> k;
        ll tye = minim(k, 100 - k);
        if (k == 100 || k == 0)
        {
            cout << 1;
        }
        else if (100 % k == 0)
        {
            cout << 100 / tye;
        }
        else 
        {
            ll temp = __gcd(k, 100 - k);
            cout << k / temp + (100 - k) / temp;
        }
        // else if (k % 10 == 0)
        // {
        //     cout << k / 10 + (100 - k) / 10;
        // }
        // else if (k % 2 == 0)
        // {
        //     cout << k / 2 + (100 - k) / 2;
        // }
        // else if (k % 5 == 0)
        // {
        //     cout << k / 5 + (100 - k) / 5;
        // }
        // else
        // {
        //     cout << 100;
        // }
        br;
    }
    return 0;
}