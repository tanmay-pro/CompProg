#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265
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
    set<pll> byNum;
    set<pll> byM;
    ll num = 0;
    while (t--)
    {
        ll n;
        cin >> n;
        if (n == 1)
        {
            ll m;
            cin >> m;
            num++;
            byM.insert({m, num});
            byNum.insert({num, m});
        }
        if (n == 2)
        {
            pll p = *byNum.begin();
            byNum.erase(byNum.begin());
            cout << p.ff << " ";
            pll temp = {p.ss, p.ff};
            byM.erase(temp);
        }
        if (n == 3)
        {
            pll p = *byM.rbegin();
            auto it = byM.lower_bound({p.ff, -1});
            cout << it->ss << " ";
            byM.erase(it);
            pll temp = {it->ss, it->ff};
            byNum.erase(temp);
        }
    }
    cout << endl;

    return 0;
}