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
        vector<ll> v;
        vector<ll> v1;
        fo(i, n)
        {
            ll x;
            cin >> x;
            v.pb(x);
            v1.pb(x);
        }
        sort(v1.begin(), v1.end());
        fo(j, n)
        {
            if (v1[0] == v[0] && n > 1)
            {
                swap(v1[0], v1[1]);
            }
            fo(i, n - 1)
            {
                if (v1[i] == v[i])
                {
                    swap(v1[i], v1[i + 1]);
                }
            }
            if (v1[n - 1] == v[n - 1] && n > 1)
            {
                swap(v1[n - 1], v1[n - 2]);
            }
        }
        bool check = true;
        fo(i, n)
        {
            if (v[i] == v1[i])
            {
                check = false;
                break;
            }
        }
        if (check)
        {
            fo(i, n)
            {
                cout << v1[i] << " ";
            }
            br;
        }
        else
        {
            cout << "-1" << endl;
        }
    }
    return 0;
}