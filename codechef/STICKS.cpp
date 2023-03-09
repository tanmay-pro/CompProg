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
ll m = 1e9 + 7;
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
        map<ll, int, greater<ll>> mp;
        ll freq[1001] = {0};
        fo(i, n)
        {
            ll x;
            cin >> x;
            mp[x] = 1;
            freq[x]++;
        }
        ll val1 = -1;
        ll val2 = -1;
        tr(mp, it)
        {
            if (freq[it->first] > 1)
            {
                val1 = it->first;
                if (freq[it->first] > 3)
                {
                    val2 = it->first;
                }
                break;
            }
        }
        if (val2 == -1)
        {
            tr(mp, it2)
            {
                if (freq[it2->first] > 1 && it2->first != val1)
                {
                    val2 = it2->first;
                    break;
                }
            }
        }
        // cout << val1;
        // br;
        // cout << val2;
        // br;
        if (val2 == -1)
        {
            cout << -1;
            br;
        }
        else
        {
            cout << val1 * val2;
            br;
        }
    }
    return 0;
}