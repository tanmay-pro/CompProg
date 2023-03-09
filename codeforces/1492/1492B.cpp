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

int main()
{
    amazing;
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vl p;
        fo(i, n)
        {
            ll x;
            cin >> x;
            p.push_back(x);
        }
        vl ans;
        map<int, int> checker;
        fo(i, n)
        {
            checker.insert(make_pair(i + 1, 0));
        }
        ll val = p[0];
        fo(i, n)
        {
            if (p[i] > val)
                val = p[i];
        }
        ll end = n;
        fo(i, n)
        {
            if (p[n - 1 - i] == val)
            {
                Fo(j, n - i - 1, end)
                {
                    ans.push_back(p[j]);
                    checker[p[j]] = 1;
                }
                end = n - i - 1;
                while (checker[val] != 0)
                {
                    val--;
                }
            }
        }
        fo(i, ans.size())
        {
            cout << ans[i] << " ";
        }
        br;
    }
    return 0;
}