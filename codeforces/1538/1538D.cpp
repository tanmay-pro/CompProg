#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265
#define br cout << endl
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define tr(container, it) \
    for (auto it = container.begin(); it != container.end(); it++)
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
ll MOD = 1e9 + 7;
int p = 31;

ll primefac(ll a)
{
    ll ans = 0;
    while (a % 2 == 0)
    {
        a = a / 2;
        ans++;
    }
    for (int i = 3; i * i <= a; i += 2)
    {
        if (a % i == 0)
        {
            while (a % i == 0)
            {
                a = a / i;
                ans++;
            }
        }
    }
    if (a > 2)
        ans++;
    return ans;
}

int main()
{
    amazing;
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        ll k;
        cin >> k;
        ll x;
        if (a == b)
            x = 0;
        else if (__gcd(a, b) == a || __gcd(a, b) == b)
            x = 1;
        else
            x = 2;
        ll y;
        y = primefac(a) + primefac(b);
        // cout << x << y;
        // br;
        if (k == 1)
        {
            if (x == 1)
                cout << "YES";
            else
                cout << "NO";
            br;
            continue;
        }
        if (k <= y && k >= x)
        {
            cout << "YES";
            br;
        }
        else
        {
            cout << "NO";
            br;
        }
    }
    return 0;
}