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

ll minim(ll a, ll b, ll c)
{
    if (a <= b && a <= c)
        return a;
    else if (b <= a && b <= c)
        return b;
    else
        return c;
}

int main()
{
    amazing;
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll p, a, b, c;
        cin >> p >> a >> b >> c;
        ll check1, check2, check3;
        if (p <= a)
        {
            check1 = a - p;
        }
        else
        {
            ll temp1 = p % a;
            if (temp1 == 0)
            {
                check1 = 0;
            }
            else
            {
                check1 = a * (p / a + 1) - p;
            }
        }
        if (p <= b)
        {
            check2 = b - p;
        }
        else
        {
            ll temp1 = p % b;
            if (temp1 == 0)
            {
                check2 = 0;
            }
            else
            {
                check2 = b * (p / b + 1) - p;
            }
        }
        if (p <= c)
        {
            check3 = c - p;
        }
        else
        {
            ll temp1 = p % c;
            if (temp1 == 0)
            {
                check3 = 0;
            }
            else
            {
                check3 = c * (p / c + 1) - p;
            }
        }
        cout << minim(check1, check2, check3);
        br;
    }
    return 0;
}