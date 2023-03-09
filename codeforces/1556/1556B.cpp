#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265
#define endl "\n"
#define br cout << endl
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define tr(container, it) \
    for (auto it = container.begin(); it != container.end(); it++)
#define amazing ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
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

int main()
{
    amazing;
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vl a;
        vl final;
        ll ce = 0, co = 0;
        unordered_map<ll, ll> m;
        fo(i, n)
        {
            ll x;
            cin >> x;
            a.pb(x % 2);
            m[x % 2]++;
        }
        if (n % 2 == 1)
        {
            if (abs(m[0] - m[1]) != 1)
            {
                cout << -1 << endl;
                continue;
            }   
            ll high = 1;
            if(m[0] > m[1])
            {
                high = 0;
            }
            ll current = 0, traversed  = 0;
            fo(i, n)
            {
                if(a[i] == high)
                {
                    traversed += abs(i - current);
                    current += 2; 
                }
            }
            cout << traversed << endl;
        }
        else 
        {
            if (abs(m[0] - m[1]) != 0)
            {
                cout << -1 << endl;
                continue;
            }
            ll oi = 0;
            ll ans1 = 0, ans2 = 0;
            ll current = 0;
            fo(i, n)
            {
                if (a[i] == 0)
                {
                    ans1 += abs(i - current);
                    current += 2;
                }
            }
            current = 0;
            fo(i, n)
            {
                if (a[i] == 1)
                {
                    ans2 += abs(i - current);
                    current += 2;
                }
            }
            cout << min(ans1, ans2) << endl;
        }
    }
    return 0;
}