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

ll maxim(ll a, ll b, ll c)
{
    ll max_val = max(a, b);
    return max(max_val, c);
}

ll minim(ll a, ll b, ll c)
{
    ll min_val = min(a, b);
    return min(min_val, c);
}

int main()
{
    amazing;
    // ll t = 1;
    // cin >> t;
    // while (t--)
    // {
    // }
    string str;
    cin >> str;
    bool set = false;
    fo(i, str.length())
    {
        if (str[i] == '4' || str[i] == '7')
        {
            set = true;
            break;
        }
    }
    if (set == false)
    {
        cout << -1;
        br;
        return 0;
    }
    ll ans4 = 0;
    ll ans7 = 0;
    fo(i, str.length())
    {
        if (str[i] == '4')
            ans4++;
        else if (str[i] == '7')
            ans7++;
    }
    if (ans4 >= ans7)
        cout << "4";
    else
        cout << "7";
    br;
    return 0;
}