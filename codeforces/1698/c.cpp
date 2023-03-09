#include <bits/stdc++.h>
using namespace std;
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

void solve()
{
    ll n;
    cin >> n;
    vl a(n);
    vl pos, neg;
    ll zero = 0;
    fo(i, n) cin >> a[i];
    fo(i, n)
    {
        if (a[i] > 0)
            pos.pb(a[i]);
        else if (a[i] < 0)
            neg.pb(a[i]);
        else
            zero++;
    }
    if (zero > 2)
        zero = 2;
    if (pos.size() > 2 || neg.size() > 2)
    {
        cout << "NO" << endl;
        return;
    }
    vl temp;
    fo(i, pos.size())
    {
        temp.pb(pos[i]);
    }
    fo(i, neg.size())
    {
        temp.pb(neg[i]);
    }
    fo(i, zero)
    {
        temp.pb(0);
    }
    fo(i, temp.size())
    {
        Fo(j, i + 1, temp.size())
        {
            Fo(k, j + 1, temp.size())
            {
                bool stat = false;
                fo(l, temp.size())
                {
                    if (temp[i] + temp[j] + temp[k] == temp[l])
                    {
                        stat = true;
                    }
                }
                if (!stat)
                {
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    }
    cout << "YES" << endl;
    return;
}
int main()
{
    amazing;
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}